inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("An Office - Chinle Oil Platform");
   set_long(
     "This is the office of the "+BOLD+"Drill Team Leader"+NORM+".  It looks rather\n"+
      "plain.  The walls are barren except for a group photo on the wall\n"+
      "next to the door.  The desk has a phone and several stacks of paper on it.\n"+
      "In the corner of the room are some metal pipes.\n");
   
   add_exit("/players/mo/rig/ROOMS/cc/r2.c","out");
   
   
   add_item("walls","Cream colored walls.\n");
   add_item("photo","A group photo of the 2011 Chinle Oil Platform Drill Team.\n");
   add_item("desk","An oak desk with a phone and papers on it.\n");
   add_item("pipes","Four to five busted metal pipes.\n");
   
   add_msg("The phone rings...\n");
   set_chance(10);
   add_object("/players/mo/rig/MON/dlead.c");
   
}
