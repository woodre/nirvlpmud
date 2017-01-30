inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Command Center - Chinle Oil Platform");
   set_long(
      "This is a raised platform overlooking the entire room.  To the north\n"+
      "and west windows overlook work being done on the oil platform.  Several\n"+
      "computer monitors are providing feedback on oil platform operations.\n"+
      "Seismic and geologic maps are laying down on a large table in the middle\n"+
      "of the room.\n");
   
   add_exit("/players/mo/rig/ROOMS/cc/r7.c","south");
   add_exit("/players/mo/rig/ROOMS/cc/r9.c","north");
   add_exit("/players/mo/rig/ROOMS/cc/r4.c","east");
   
   add_item("platform","The raised section of floor you are standing on.\n");
   add_item("windows","Large windows that allow you to look at the oil platform.\n");
   add_item("monitors","Computers monitoring well-production.\n");
   add_item("maps","Seismic and geologic maps for this area.\n");
   add_item("table","A large table with maps laying on it.\n");
   add_object("/players/mo/rig/MON/opman.c");
   add_object("/players/mo/rig/MON/op.c");
   add_object("/players/mo/rig/MON/op.c");
   add_object("/players/mo/rig/MON/op.c");
}
