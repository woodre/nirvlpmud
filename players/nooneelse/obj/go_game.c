/*
 go_game.c
*/

#define EMPTY   0
#define BLACK   1
#define WHITE   2

int board, mark, num_pass;

object black, white;
int to_play;

short() { return "board" || "go board"; }

long() {
  write(
   "A go board. If you want to play with someone, do 'start name' with the\n"+
   "name of your friend.  The player issuing the 'start' command will get\n"+
   "black.  An optional numeric argument to start is the number of handicap\n"+
   "stones.\n");
  if (black || white) {
    write("\n");
    display(board);
  }
}

id(str) { return str=="board" || str=="go board"; }

query_value() { return 10; }

get() { return !occupied(); }

reset(arg) {
  if (arg) return arg;

  to_play = EMPTY;
}

start(str) {
  int i, handicap;
  string name;
  if (environment() == this_player()) {
    write("You mus put it down first !\n");
    return 1;
  }
  if (sscanf(str, "%s %d", name, handicap) != 2) name = str;
  name = present(name, environment(this_object()));
  if (!name) return;
  if (occupied()) return 1;
/*
  if (name == this_player()) {
    write("Sorry, you can't play against yourself.\n");
    return 1;
  }
*/
  notify(" starts a game with " + call_other(name, "query_name") + ".\n");
  to_play = BLACK;
  num_pass = 0;
  white = name;
  black = this_player();
  board = allocate(9);
  mark = allocate(9);
  while(i<9) {
    board[i] = allocate(9);
    mark[i] = allocate(9);
    i += 1;
  }
  write("Board initialized.\n");
  if (handicap) {
    if (handicap < 2 || handicap > 9) {
      write("The handicap must be from 2 to 9 stones.\n");
      white = 0;
      black = 0;
      return 1;
    }
    write("You get " + handicap + " stones, and white starts.\n");
    notify(" gets " + handicap + " stones, and white starts.\n");
    place_hand(handicap);
    to_play = WHITE;
  }
  return 1;
}

display(b) {
  int x, y;

  if (to_play == BLACK)
    write("Black '@' (" + black->query_name() + ") to play.\n\n");
  else
    write("White 'O' (" + white->query_name() + ") to play.\n\n");
  write("  0 1 2 3 4 5 6 7 8\n");
  while(x<9) {
    write(x + " ");
    while(y<9) {
      if (b[x][y] == EMPTY) write(". ");
      else
      if (b[x][y] == BLACK) write("@ ");
      else
      if (b[x][y] == WHITE) write("O ");
      y += 1;
    }
    write("\n");
    x += 1;
    y = 0;
  }
}

disp() {
  display(board);
  return 1;
}

init() {
  add_action("disp",  "disp");
  add_action("start", "start");
  add_action("patch", "patch");
  add_action("play",  "play");
  add_action("score", "score");
  add_action("fill",  "fill");
}

count_lib(b, x, y) {
  clean(mark);
  return lib(b, mark, x, y);
}

clean(b) {
  int i, j;

  i = 0;
  while(i<9) {
    j = 0;
    while(j<9) {
      b[i][j] = 0;
      j += 1;
    }
    i += 1;
  }
}

lib(b, m, x, y) {
  int col, sum;
