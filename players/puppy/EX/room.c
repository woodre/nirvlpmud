#include "/players/puppy/define.h"
inherit "room/room";

reset(arg) {
   if(arg) return;
   
   set_light(1);
   
   set_short("A room");
   set_long(
   "This is the description.\n"+
   "This is the description.\n"+
   "This is the description.\n"
   );
   
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   
   items=({
         "item", "An item./N"+
		 "item", "An item./N"+
		 "item", "An item./N"
		 });
		 
   dest_dir = ({
         "/players/puppy/workroom.c", "north",
		 "/players/puppy/workroom.c", "south",
		 "/players/puppy/workroom.c", "west",
		 "/players/puppy/workroom.c", "east",
		 
		 });
		 
   move_object(clone_object("/players/puppy/EX/mob.c"), this_object());
   
   return 1; }
