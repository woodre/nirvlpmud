/******************************************************************************
 * Program: c4.c
 * Type: Item
 * Created: March 15th, 2013 by Dragnar
 *
 * Purpose: An object that simulates a connect four game between two players.
 *          This started as a project to get familiar with Nirvana again after
 *          taken a long break from playing.  I modified the C code from Keith
 *          Pomakis: pomakis@pobox.com so it would run on Nirvana.
 *
 ******************************************************************************/
#include <ansi.h>

#define other(x)        ((x) ^ 1)
#define real_player(x)  ((x) - 1)
#define pop_state() (current_state = state_stack[--depth])

#define MAP "players/dragnar/daemons/mapping"

#define FALSE 0
#define TRUE 1
#define INT_MAX 999999

#define ROWS 6
#define COLS 5
#define size_x 7
#define size_y 6
#define NUM_TO_CONNECT 4
#define C4_MAX_LEVEL 10

#define C4_NONE 2
#define PLAYER1 0
#define PLAYER2 1
#define WIN_PLACES 69
#define MAGIC_WIN_NUMBER 16

int eval(int player, int level, int alpha, int beta);

/* Map of all possible winning sequences */
mixed *map;

/* Array of coordinates of winning sequence */
mixed *win_coords;

/*******************************************************************************
 * Main structure that stores:
 * 1. Playing Board - 2d int array of the 7 x 6 board.
 *    State of the board is C4_NONE when blank, or the player number of the
 *    player that played in that cell.
 * 2. Score Array - Tracks the score of the player for each possible winning
 *    sequence.  Each time a piece is dropped we update how many of the players
 *    pieces are in each winning sequence.
 * 3. Number of Pieces played
 * 4. Who the winner is
 * 5. Score 
 ******************************************************************************/
mapping current_state;

/* Array of states for AI */
mixed *state_stack;

int game_in_progress = FALSE;
int initalized = FALSE;
int depth;
int states_allocated = 0;
int *drop_order;

/* Keeps track of who is playing the game */
string *player_names;
/* Tracks who turn it currently is */
int turn;

/* Testing variables, to be removed **/
int l_cnt;

id(string str) {
   return str == "machine" || str == "c4";
}

init() {
   add_action("print_board","print");
   add_action("play","play");
   add_action("reset_board","reset");
   add_action("check_move","ctest");   
}

reset(arg){
  int i;
  if(arg) return;
}

start_game() {
	depth = 5;
	
  current_state[0] = current_state;
  states_allocated = 1;
	
	turn = PLAYER1;
	game_in_progress = TRUE;
	call_out("check_move",10);
	/* Setup game for testing only 
	drop_piece(0, 1);
	drop_piece(1, 5);
	drop_piece(0, 1);
	drop_piece(1, 5);
	drop_piece(0, 1);
	drop_piece(1, 5); */
	print_board();	
}

/*******************************************************************************
 * Create_board
 *   Sets up the board after a game has started.  No memory will be used unless
 *   a player starts a game.  Once the memory is allocated it is reused, the
 *   structures are simply cleared of data. 
 ******************************************************************************/
mapping
create_board() { 
	int i, j;

  mixed *board;
  mixed *score_array;
  int *score;
  mapping l_state;
  
	/************************************************************
	 * Setup the c4 board
	 ************************************************************/
	/* Rows */
	board = allocate(size_x);
	/* Columns */
	for(i=0; i<sizeof(board); i++) {
    board[i] = allocate(size_y); 
    for( j=0; j<size_y; j++ )
      board[i][j] = C4_NONE;
  }
  
  /*************************************************************
	 * Setup the score array
	 *************************************************************/
	score_array = allocate(2);
	score_array[0] = allocate(WIN_PLACES);
	score_array[1] = allocate(WIN_PLACES);
	for( i=0; i < WIN_PLACES; i++ ) {
		score_array[0][i] = 1;
		score_array[1][i] = 1;
	}
	
  score = allocate(2);
  score[0] = WIN_PLACES;
  score[1] = WIN_PLACES;
  
  l_state = ([ "board": board
  	          ,"score_array": score_array
  	          ,"num_of_pieces": 0
  	          ,"winner": C4_NONE
  	          ,"score": score   ]);
  
  return l_state;
}

/*******************************************************************************
 * goodness_of
 *   
 ******************************************************************************/
int 
goodness_of( int player ) {
  int *score;
  score = current_state["score"];
  
  return score[player] - score[other(player)];
}

/*******************************************************************************
 * Initialize_memory
 *   Sets up a map of all possible winning combinations.  This is used to check
 *   to see if a player has won and what their score is in a region to see if
 *   it is a good play or not.
 ******************************************************************************/
initalize_memory()
{
	int i, j, k, x;
	int win_index, column;
	int *win_indices;
	
	player_names = allocate(2);
  win_coords = allocate(NUM_TO_CONNECT);
  
	state_stack = allocate( C4_MAX_LEVEL+1 );
  
	/*************************************************************
	 * Allocate memory for the map
	 *************************************************************/
	map = allocate(size_x);
  for (i=0; i<size_x; i++) {
    map[i] = allocate(size_y);
    for (j=0; j<size_y; j++) {
      map[i][j] = allocate(NUM_TO_CONNECT*4 + 1);
      map[i][j][0] = -1;
    }
  }
  
  /* Fill in possible win positions */
  win_index = 0;

	/* Fill in the horizontal win positions */
	for (i=0; i<size_y; i++)
		for (j=0; j<size_x-NUM_TO_CONNECT+1; j++) {
			for (k=0; k<NUM_TO_CONNECT; k++) {
				win_indices = map[j+k][i];
				for (x=0; win_indices[x] != -1; x++)
				;
				win_indices[x++] = win_index;
				win_indices[x] = -1;
			}
			win_index++;
		}
		
	/* Fill in the vertical win positions */
	for (i=0; i<size_x; i++)
		for (j=0; j<size_y-NUM_TO_CONNECT+1; j++) {
			for (k=0; k<NUM_TO_CONNECT; k++) {
				win_indices = map[i][j+k];
				for (x=0; win_indices[x] != -1; x++)
				;
				win_indices[x++] = win_index;
				win_indices[x] = -1;
			}
			win_index++;
		}

	/* Fill in the forward diagonal win positions */
	for (i=0; i<size_y-NUM_TO_CONNECT+1; i++)
		for (j=0; j<size_x-NUM_TO_CONNECT+1; j++) {
			for (k=0; k<NUM_TO_CONNECT; k++) {
				win_indices = map[j+k][i+k];
				for (x=0; win_indices[x] != -1; x++)
				;
				win_indices[x++] = win_index;
				win_indices[x] = -1;
			}
			win_index++;
		}

	/* Fill in the backward diagonal win positions */
	for (i=0; i<size_y-NUM_TO_CONNECT+1; i++)
		for (j=size_x-1; j>=NUM_TO_CONNECT-1; j--) {
			for (k=0; k<NUM_TO_CONNECT; k++) {
				win_indices = map[j-k][i+k];
				for (x=0; win_indices[x] != -1; x++)
				;
				win_indices[x++] = win_index;
				win_indices[x] = -1;
			}
			win_index++;
		}

  /* Set up drop order, middle columns should be played first */
  drop_order = allocate( size_x );
  column = ( size_x - 1 ) / 2;
  for( i = 1; i < size_x; i++ ) {
    drop_order[i-1] = column;
    column += ( (i%2) ? i : -i );
  }
  
  for( i=0; i < size_x; i++ ) {
    write("Drop Order["+i+"] : " + drop_order[i] + "\n");
  }
}

/*******************************************************************************
 * print_board
 *   Prints the current state of the board to the players who are playing the
 *   game, and anyone watching the game (TBD). 
 ******************************************************************************/
print_board() {
  int i, j, x;
  mixed *board;
  object target;
  
  board = current_state["board"];
   
  /* Loop through the list of players watching the game */
  for( x=0; x < sizeof(player_names); x++ ) {
    target = find_player( player_names[x] );
    if(!target)
    	break;
    
    if( current_state["winner"] != C4_NONE ) {
      tell_object(target, capitalize(player_names[current_state["winner"]]) + " is the winner!\n");
    }
    
    tell_object(target, " ");
    for (x=0; x<= ROWS; x++)
        tell_object(target, " " + HIW + (x+1)+ NORM +"  ");
        
	  tell_object(target, "\n");
	  tell_object(target, "+");
	  for( j = 0; j <= ROWS; j++ ) {
	       tell_object(target, "---+");
	  }
	  tell_object(target, "\n");
	  
	  for( i = COLS; i >= 0; i-- ) {
	   	tell_object(target, "|");
	   	for( j = 0; j <= ROWS; j++ ) {
	   	 	tell_object(target, " "+ print_cell(board[j][i], j, i) + " |");
	   	 }
	   	 tell_object(target, "\n");
	   	 tell_object(target, "+" );
	   	 for( j = 0; j <= ROWS; j++ ) {
	       tell_object(target, "---+");
	     }
	     tell_object(target, "\n");
	  }
  }
  return 1;
}

/*******************************************************************************
 * print_cell
 * Parameters: cell - integer value of the cell value from the board to be printed
 *             x - x coordinate of the cell we are printing
 *             y - y coordinate of the cell we are printing
 *
 *   Returns the string based on the data in the cell and the coordinates of the
 *   cell.  Function checks to see if the cell is one in the winning sequence, 
 *   if so it makes those cells blink.  It prints Yellow for player 1 and Red
 *   for player 2. 
 ******************************************************************************/
print_cell( int cell, int x, int y ){
	string str;
	int i;
	int winner; 
	
	winner = FALSE;
	
	/* See if the cell we are printing was part of the winning sequence */
	if( current_state["winner"] != C4_NONE  ) {
	  for( i=0; i < sizeof(win_coords) && winner == FALSE; i++ ) {
		  if( (win_coords[i]["x"]) == x && (win_coords[i]["y"]) == y )
			  winner = TRUE;
	  }
  }
  
	switch(cell) {
		case PLAYER1:
			str = (winner ? HIY+BLINK : HIY) + "O" + NORM;
			break;
	  case PLAYER2:
	  	str = (winner ? HIR+BLINK : HIR) + "O" + NORM;
	  	break;
	  default:
	  	str = " ";
	  	break;
	}
	return str;
}

/*******************************************************************************
 * drop_piece
 * Parameters: player - integer value of the playing who is doing the move
 *             column - integer of the column the player is trying to play in
 *
 *   Takes care of what needs to happen when a player drops a piece into the
 *   game board.  Does some validation, then sets the board value to the 
 *   number of the player so we know who played in that position.  We increment
 *   the number of pieces played and then update the players score based on
 *   where the piece was just played.  Then we switch to the other players turn. 
 ******************************************************************************/
drop_piece(int player, int column) {
	int i, y;
	
	mixed *board;
	
	board = current_state["board"];
	
	if( player != PLAYER1 && player != PLAYER2 ) {
	  write("Invalid player.\n");
	  return 1;
	}
	if( column > ROWS || column < 0 ) {
		write("Invalid column.\n");
		return 1;
  }
  
  while( board[column][y] != C4_NONE && ++y < size_y );
    if (y == size_y)
    {
    	write("Column "+(column+1)+" is full.\n");
      return -1;
    }

    board[column][y] = player;
    current_state["num_of_pieces"]++;
    say(capitalize(player_names[turn]) + " plays in column "+ column + "\n");
    update_score(player, column, y);

  print_board();
  return 1;
}

/*******************************************************************************
 * play
 * Parameters: p_str - String to be parsed for player or column number
 *
 *   Command by one of the players that either initiates a game or plays a
 *   game piece in a column.
 ******************************************************************************/
play(string p_str) {
	int player;
	int column;
	string who;
	
	if(!p_str) {
		if( !game_in_progress ) {
	    write("Play who?\n");
	    return 1;
	  }
		write("Play which column?\n");
	  return 1;
	}
	
	if( !game_in_progress ) {
		sscanf( p_str, "%s", who );
		if( who == "c4" || who == "C4" || who == "machine" ) {
		  write("Playing c4 machine.\n");
		  who = "C4";
		}
		else {
			if( !present(who, environment())) {
				write(capitalize(who) +" is not here.\n");
				return 1;
			}
			if( !find_player(who) ) {
				write(capitalize(who) + " is not capable of playing.\n");
				return 1;
			}
	  }
		
		if( !initalized ) {
			write("INIT.....\n");

			current_state = create_board();
			initalize_memory();
			initalized = TRUE;
			state_stack[0] = current_state;
		}
		
		player_names[PLAYER1] = this_player()->query_real_name();
	  player_names[PLAYER2] = who;
		
		start_game();
		return 1;
	}
	else {
		if( this_player()->query_real_name() != player_names[turn] ) {
			write("It is not currently your turn.\n");
			return 1;
	  }
	  sscanf(p_str, "%d", column);
	  drop_piece(turn, column -1);
	  turn = other(turn);
	  return 1;
	}
}

/*******************************************************************************
 * reset_board
 *   Resets the board by setting all of the objects to default state.  Does not
 *   re-allocate the memory.
 ******************************************************************************/
reset_board() {
	int i;
	int j;
	mixed *board;
	mixed *score_array;
  int *score;
	
	board = current_state["board"];
	score_array = current_state["score_array"];
	score = current_state["score"];
	
	depth = 0;
	
	/* Reset the board back to empty state */
	for( i=0; i < sizeof(board); i++ ) {
		for( j=0; j < sizeof(board[i]); j++ ) {
			board[i][j] = C4_NONE;
		}
	}
	
	/* Reset the score array */
	for( i=0; i < WIN_PLACES; i++ ) {
		score_array[0][i] = 1;
		score_array[1][i] = 1;
	}
	
	score[0] = WIN_PLACES;
  score[1] = WIN_PLACES;
  
  current_state["num_of_pieces"] = 0;
  current_state["winner"] = C4_NONE;
  
  /* Clear winning coordinates */
  for( i=0; i < sizeof(win_coords); i++ ) {
	  win_coords[i] = ([ "x": 0, "y": 0 ]);
	}
  
  turn = PLAYER1;
  
  player_names[PLAYER1] = "";
  player_names[PLAYER2] = "";
  
	game_in_progress = FALSE;
	return 1;
}

/*******************************************************************************
 * update_score
 * Parameters: player - integer of the player who is currently playing
 *             x - integer x coordinate of the position played on the board
 *             y - integer y coordinate of the position played on the board
 *
 *   Updates the score array for the player.  It loops through the map which 
 *   holds all possible winning sequences and identifies how many pieces the
 *   player has of that sequence.  If the player has the correct amount then 
 *   the win sequence is started.
 ******************************************************************************/
update_score(int player, int x, int y){
  int i, j, k, z;
  int win_index, c_index;
  int this_difference, other_difference;
  int other_player;
  mixed *current_score_array;
  int *score;
  
  write("PLAYER: " + player + " x: " + x + " y: " + y + "\n");
  this_difference = 0;
  other_difference = 0; 
  c_index = -1;
  
  current_score_array = current_state["score_array"];
  score = current_state["score"];
  
  other_player = other(player);
  
  for( z=0; map[x][y][z] != -1; z++ ) {
    win_index = map[x][y][z];
    
    this_difference += current_score_array[player][win_index];
    other_difference += current_score_array[other_player][win_index];
    
    if( win_index == 1 ) {
      write("x: " + x + " y: " + y + "\n");
      write("Score for player "+player+" win_index: " + win_index +" : "+ current_score_array[player][win_index] + "\n");
      write("this_diff: " + this_difference + "\n");
    }
    current_score_array[player][win_index] <<= 1;
    current_score_array[other_player][win_index] = 0;
    
    if( win_index == 1 ) {
      write("x: " + x + " y: " + y + "\n");
      write("Score for player "+player+" win_index: " + win_index +" : "+ current_score_array[player][win_index] + "\n");
    }

    if (current_score_array[player][win_index] == MAGIC_WIN_NUMBER)
			if (current_state["winner"] == C4_NONE) {
				current_state["winner"] = player;
				write(" Winner is: "+player_names[player]+"!!\n");
			
				/* Set up the winning coordinates array */
				for (j=0; j<size_y ; j++)
					for (i=0; i<size_x; i++)
						for (k=0; map[i][j][k] != -1; k++)
							if (map[i][j][k] == win_index) {
								win_coords[++c_index] = ([ "x": i, "y": j ]);
								/*write( "x: " + (win_coords[c_index]["x"]) + " y: " + (win_coords[c_index]["y"]) + "\n");*/
							}
			  break;
			}
  }
  
  score[player] += this_difference;
  score[other_player] -= other_difference;
}

check_move() {
	if( player_names[turn] == "C4" ) {
	  write("TURN: " + turn + "\n");
		auto_move( turn, 5 );
	}
	return 1;
}

/*******************************************************************************
 * eval
 * Parameters: player - integer of the player who is currently playing
 *             level - level of AI for the computer
 *             alpha -
 *             beta -
 *
 *   Updates the score array for the player.  It loops through the map which 
 *   holds all possible winning sequences and identifies how many pieces the
 *   player has of that sequence.  If the player has the correct amount then 
 *   the win sequence is started.
 ******************************************************************************/
eval(int player, int level, int alpha, int beta)
{
    int i, goodness, best, maxab;
    l_cnt++;

    if (level == depth)
        return goodness_of(player);
    else {
        /* Assume it is the other player's turn. */
        best = -(INT_MAX);
        maxab = alpha;
        for(i=0; i<size_x; i++) {
            push_state();
            if (drop_piece(other(player), drop_order[i]) < 0) {
                pop_state();
                continue;
            }
            else if (current_state["winner"] == other(player))
                goodness = INT_MAX - depth;
            else
                goodness = eval(other(player), level, -beta, -maxab);
            if (goodness > best) {
                best = goodness;
                if (best > maxab)
                    maxab = best;
            }
            pop_state();
            if (best > beta)
                break;
        }

        /* What's good for the other player is bad for this one. */
        return -best;
    }
}

/*******************************************************************************
 * auto_move
 * Parameters: player - integer of the player who is currently playing
 *             level - level of AI for the computer
 *
 *   Updates the score array for the player.  It loops through the map which 
 *   holds all possible winning sequences and identifies how many pieces the
 *   player has of that sequence.  If the player has the correct amount then 
 *   the win sequence is started.
 ******************************************************************************/
auto_move( int player, int level ) {
	int i, best_column, goodness, best_worst;
	int num_of_equal, column, current_column;
	mixed *board;
  
  write("auto\n");
  best_column = -1;
  goodness = 0;
  best_worst = -(INT_MAX);
  num_of_equal = 0;
  
  board = current_state["board"];
  
  /* Play in the middle column if it is free */
 	if ( board[3][0] == C4_NONE ) {
	  column = 3;
	  drop_piece(player, column);
	  turn = other(turn);
	  return column;
  }
  
  /* Simulate a drop in each column and see what results are */
  for( i=0; i < size_x; i++ ) {
    push_state();
    current_column = drop_order[i];
    
    /* Ignore if column is full */
    if( drop_piece( player, current_column ) < 0 ) {
      pop_state();
      continue;
    }
    
    /* Check to see if this drop wins the game */
    else if( current_state["winner"] == player ) {
      write("WINNER...\n");
      best_column = current_column;
      pop_state();
      break;
    }
    
    /* Otherwise, look ahead to see how good this move may turn out */
    /* to be (assuming the opponent makes the best moves possible). */
    else {
      l_cnt = 0;
      goodness = eval( player, level, -(INT_MAX), -best_worst);
      write("Recursive calls: " + l_cnt + "\n");
    }

    /* If this move looks better than the ones previously considered, */
    /* remember it.                                                   */
    if (goodness > best_worst) {
      best_worst = goodness;
      best_column = current_column;
      num_of_equal = 1;
    }

    /* If two moves are equally as good, make a random decision. */
    else if (goodness == best_worst) {
      num_of_equal++;
      if ( random(2) )
      best_column = current_column;
    }
    
    
    pop_state();
  }
  
  turn = other(turn);
  if( best_column >= 0 ) {
    drop_piece( player, best_column );
    return TRUE;
  }
  else
    return FALSE;
}

/*******************************************************************************
 * push_state
 *
 *   Adds the current state to the array of states.  Used when a player is
 *   playing the C4 computer.
 ******************************************************************************/
push_state() {
  mapping *old_state, *new_state;
  
  mixed *board, *old_board;
  mixed *score_array, *old_score_array;
  int *score, *old_score;
  int i, j;
  
  write("push depth: " + depth + " states_allocated: "+states_allocated+"\n");
  old_state = (mapping *) state_stack[depth++];
  new_state = (mapping *) state_stack[depth];

  if( depth == states_allocated ) {
  	/* Copy the current state into a new one */
  	new_state = create_board();
	  /* Add state to the array of states */
	  state_stack[depth] = new_state;
	
  	states_allocated++;
  	write("States allocated: " +states_allocated+" \n");
  }
  else {
    new_state = state_stack[depth];
  }
  
  /* Copy the old state to the new state */
  board = new_state["board"];
  old_board = old_state["board"];
  
  score_array = new_state["score_array"];
  old_score_array = old_state["score_array"];
  
  score = new_state["score"];
  old_score = old_state["score"];
  
  /* Copy the values of the board to the new one */
  for(i=0; i<sizeof(board); i++) {
    for( j=0; j<size_y; j++ )
      board[i][j] = old_board[i][j];
  }

  /* Copy values of the score array */
	for( i=0; i < WIN_PLACES; i++ ) {
		score_array[0][i] = old_score_array[0][i];
		score_array[1][i] = old_score_array[1][i];
	}
	
  /* Copy score */
  score[0] = old_score[0];
  score[1] = old_score[1];
  
  new_state["num_of_pieces"] = old_state["num_of_pieces"];
  new_state["winner"] = old_state["winner"];
  
  current_state = new_state;
}

short() {
	/*return HIW+"A Connect "+HIY+"F"+HIR+"o"+HIY+"u"+HIR+"r"+HIW+" Machine"+NORM;*/
	return "A connect Four Machine";
}

long() {
	write(HIW+"A Connect "+HIY+"F"+HIR+"o"+HIY+"u"+HIR+"r"+HIW+" Machine\n"+NORM+"\
		Currently a game " + (game_in_progress ? "is" : "is not") + " in session.\n");
}

get() { return 0; }
drop() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }

