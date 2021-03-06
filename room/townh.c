#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET my_reset(arg);
#undef EXTRA_INIT
#define EXTRA_INIT my_init();

my_reset(arg) {
   object board;

   if(arg) return;
/*
   if(!present("town notices")) {
      board = clone_object("obj/town_note");
      move_object(board,this_object());
   }
*/
   return;
}

my_init() {
   add_action("vote", "vote");
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
        log_file("issue"+issue,who+": "+vote+"\n:--: "+comments +"\n");
        write("Vote recorded.\n");
        return 1;
    } else {
        if(sscanf(str,"%d %s",issue,vote) == 2) {
            log_file("issue"+issue,who+": "+vote+"\n:--: <No comment>\n");
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
   "The town council",
   "This is the town council chambers.\nHere will be posted issues "+
   "for players to vote upon.\nLook at the notices to see what is "+
   "there.\n" +
   "Your vote will only be counted ONCE.\n"+
   "If you vote MORE than once, the actual vote will be RANDOMLY\n"+
   "from all your votes made (or discounted).\n", 1)
