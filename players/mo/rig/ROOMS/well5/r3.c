inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Well #5 - Chinle Oil Platform");
   set_long(
      "     You are standing on a metal floor that circles around the well. You are\n"+
      "able to walk "+BOLD+"around"+NORM+" the well area, but the view does not change much.\n"+
      "The well extends at least a hundred or so feet in the air.  It is cased in\n"+
      "a gray sheet metal that shields workers from potential blow outs. The area\n"+
      "is surprising clean which indicates that there have not been any oil blowouts\n"+
      "recently. Tools used by the roughnecks, and toolhands are scattered on\n"+
      "the floor.\n");
   
   add_exit("/players/mo/rig/ROOMS/well5/r4.c","around");
   
   add_item("tools","Wrenches, screw drivers, and pliers strewn about.\n");
   add_item("floor","A metal floor that you can walk on.\n");
   
}
