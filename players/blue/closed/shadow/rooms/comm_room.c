#include "/players/blue/closed/lib/shadsecure.h"
#define BOARD "/players/blue/closed/shadow/obj/cboard.c"
#define CLERK "/players/blue/closed/store/clerk.c"
#define STORAGE "/players/blue/closed/store/storage.c"

inherit"/room/room";

reset(arg) {
   object board;
   if(arg) return;

   short_desc = "Shadow Commanders Room";
   long_desc = 
"   You are in the depths are darkness....but yet you can see.\n"+
"   Great evils have been planned here, many more to come.  This is where the "+
"\nshadows, the Lords of Darkness, delve into the arcane world of magic and "+
"\ndeath.   May your imagination be your limit...\n";

   dest_dir = ({"/players/blue/closed/shadow/rooms/meeting.c","south"});
   if(!present("board", this_object()))  {
      board = clone_object(BOARD);
      if(board) move_object(board, this_object());
   }
   if(!present("clerk", this_object())) {
      move_object(clone_object(CLERK), this_object());
   }
   if(!present("desk", this_object()))
      move_object(clone_object(STORAGE), this_object());

}
