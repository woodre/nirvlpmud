#include "/players/hippo/rvd.h"
id(str) {if(str=="board") return 1; return 0; }
get() { return 0; }
drop() { return 1;}
long() { write("This board is pointing to a new puzzle room.\n"+
  "It says that you can get there by typing '2puzzles'.\n"+
  "Maybe it's the best to take a look.\n");
  return 1;
}
short() { return("A board, pointing to a puzzle room"); }
init() {add_action("puzzles","2puzzles");}
puzzles()
  { move_object(this_player(),"/players/hippo/games/puzzle_room/puzzle_room");
    write("You entered the famous puzzle room!\n");
    say(CTP+" entered the puzzle room.\n");
    return 1;
  }
