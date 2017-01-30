#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET my_reset(arg);
#undef EXTRA_INIT
#define EXTRA_INIT my_init();

my_reset(arg) {
   object board;

   if(arg) return;
   if(!present("ballot")) {
      board = clone_object("players/shinshi/assassin/ballot");
      move_object(board,this_object());
   }
   return;
}

my_init() {
   add_action("vote"); add_verb("vote");
   add_action("south","south");
}

south(){
     this_player()->move_player("south#players/shinshi/assassin/cenguild");
     return 1;
}
vote(str) {
    string who, vote, comments;
    int issue;

    if(!str) {
       write("You need to actually make some sort of vote!\n");
       return 0;
    }
    who = call_other(this_player(),"query_name");
    if(sscanf(str,"%d %s -- %s",issue, vote, comments) == 3) {
     write_file("/players/shinshi/assassin/tally",
       issue+":"+who+":"+vote+":"+comments+"\n");
        write("Vote recorded.\n");
        return 1;
    } else {
        if(sscanf(str,"%d %s",issue,vote) == 2) {
     write_file("players/shinshi/assassin/tally",
       issue+":"+who+":"+vote+"<no comment>\n");
            write("Vote <no comment> recorded.\n");
            return 1;
        } else {
	    write("Bad vote format.\nNo vote recorded.\n");
            write("Look at the notices for the correct format.\n");
            return 1;
        }
    }
}

ONE_EXIT("room/church","south",
         "Assassin voting",
         "This is the voting chamber where you can vote on the players\n"+
         "you would like to be assassinated.\n"+
	 "Your vote will only be counted ONCE.\n"+
	 "If you vote MORE than once, the actual vote will be RANDOMLY\n"+
	 "from all your votes made (or discounted).\n", 1)
