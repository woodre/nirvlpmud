/*comm_room.c*/
 
#define BOARD "/players/pathfinder/closed/shadow/obj/cboard.c"
#define CLERK "/players/pathfinder/closed/shadow/obj/clerk.c"
#define STORAGE "/players/pathfinder/closed/obj/storage.c"
#include "/players/blue/closed/lib/basic.h"
 
inherit "/room/room";
 
reset(arg) {
   object board;
   object mark;
   mark = present("shadow-mark",this_player());
   if(arg) return;
 
   short_desc = "Shadow Commanders Room";
   long_desc =
"   You are in the depths are darkness....but yet you can see.\n"+
"   Great evils have been planned here, many more to come.  This is where the\n"+
"shadows, the Lords of Darkness, delve into the arcane world of magic and\n"+
"death.   May your imagination be your limit...\n";
 
  dest_dir = ({"/players/pathfinder/closed/shadow/rooms/meeting", "south"});
   if(!present("board", this_object()))  {
      board = clone_object(BOARD);
      if(board) move_object(board, this_object());
   }
   if(!present("clerk", this_object())) {
      move_object(clone_object(CLERK), this_object());
   }
/*
   if(!present("desk", this_object()))
      move_object(clone_object(STORAGE), this_object());
*/
 
}
 
init() {
   ::init();
   filter_room();
}
 
filter_room() {
   object mark, ob;
   ob = this_player();
   mark = present("shadow-mark",ob);
   if((!mark || mark->query_shlevel() < 9) && ob->query_level() < 20) {
     tell_room(this_object(),capitalize(this_player()->query_name())+"tries to enter the room but fails.\n");
         tell_object(ob, "The Master Shadow tells you: You do not belong here.  BEGONE!\n");
         move_object(ob, "/room/church");
      }
   return 1;
}
