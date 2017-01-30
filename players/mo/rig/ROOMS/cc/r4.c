inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   
   set_light(1);
   set_short("Command Center - Chinle Oil Platform");
   set_long(
     "This is a long hallway with a nice, checkered tile floor.\n"+
      "There is an open space to the west with large windows that provide a view\n"+
      "of the platform.  There is a door leading into an office to the east. A\n"+
      "beautiful green plant is sitting next to the doorway.  On the wall next\n"+
      "to the door is a picture hanging on the wall.\n");
   
   add_exit("/players/mo/rig/ROOMS/cc/r3.c","north");
   add_exit("/players/mo/rig/ROOMS/cc/r5.c","south");
   add_exit("/players/mo/rig/ROOMS/cc/r8.c","west");
   add_item("hallway","A long hallway with checkered floors.\n");
   add_item("floor","A clean checkered floor.\n");
   add_item("door",""+BOLD+"(Lead Geologist)"+NORM+" labeled on the door.  Perhaps you could 'enter'\n");
   add_item("plant","A well-manicured, green plant with yellow flowers.\n");
   add_item("picture","An oil platform located in the Gulf Coast region\n");
}

init() {
   ::init();
   add_action("enter_me","enter");
}

enter_me(str) {
   if(!str || str!="door") return 0;
   write("You open the door and enter it.\n");
   this_player()->move_player("into the doorway#players/mo/rig/ROOMS/cc/office3.c");
   
   say(this_player()->query_name()+" opens the door and enters it.\n");
   return 1;
}
