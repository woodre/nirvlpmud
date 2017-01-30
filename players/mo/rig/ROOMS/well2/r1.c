inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
int random_index;
reset(arg) {
   if(arg) return;
   random_index=random(2);
   move_object(clone_object(({"/players/mo/rig/MON/d.c","/players/mo/rig/MON/toolhand2.c"})[random_index]),
      this_object());
   set_light(1);
   set_short("Well #2 - Chinle Oil Platform");
   set_long(
      "     You have just entered "+BOLD+"Well Site #2"+NORM+" on the Chinle Oil Platform. You\n"+
      "are standing on a metal floor that circles around the well. You are able to\n"+
      "walk "+BOLD+"around"+NORM+" the well area, but the view does not change much. The well\n"+
      "extends at least a hundred or so feet in the air.  It is cased in a gray sheet\n"+
      "metal that shields workers from potential blow outs.  Directly in front of you\n"+
      "is a panel with several gauges on it. The area is surprising clean which\n"+
      "indicates that there have not been any oil blowouts recently. Tools used by\n"+
      "the roughnecks, and toolhands are scattered on the floor.\n");
   
   add_exit("/players/mo/rig/ROOMS/well2/r2.c","around");
   add_exit("/players/mo/rig/ROOMS/w2ent.c","out");
   add_item("gauges","A set of gauges that show pressures in the well.\n");
   add_item("tools","Wrenches, screw drivers, and pliers strewn about.\n");
   add_item("floor","A metal floor that you can walk on.\n");
   add_item("panel","A set of gauges that show pressure in the well.\n");
   
}
