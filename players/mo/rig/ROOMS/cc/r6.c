inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Command Center - Chinle Oil Platform");
   set_long(
"This is the southern portion of the Chinle Oil Platform "+BBLU+"Command\n"+
     "Center"+NORM+".  Ahead is a long hallway with a nice, checkered tile floor.\n"+
      "There is a large open space to the west with large windows that provide a view\n"+
      "of the platform.  Several doors line the eastern side of the hallway.  Potted\n"+
      "plants sitting on small tables separate the doors.  Pictures of other oil\n"+
      "platforms owned by Chinle Oil Co. are hung on the eastern walls.\n"+
      "\n");
   add_exit("/players/mo/rig/ROOMS/d3.c","out");
   add_exit("/players/mo/rig/ROOMS/cc/r5.c","north");
   
   add_item("hallway","A long hallway with checkered floors.\n");
   add_item("floor","A clean checkered floor.\n");
   add_item("doors","Wooden doors that lead to offices.\n");
   add_item("plants","Well-manicured, green plants.\n");
   add_item("pictures","Framed pictures of oil platforms owned by Chinle Oil Co.\n");
   
}
