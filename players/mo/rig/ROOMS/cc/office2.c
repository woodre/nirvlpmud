inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("An Office - Chinle Oil Platform");
   set_long(
     "This is the office of the Head Toolhand.  The office looks rather\n"+
      "plain.  The walls are barren except for a group photo on the wall\n"+
      "next to the door.  The desk has a phone and several stacks of paper on it.\n"+  
      "Next to the papers are a couple broken tools.\n");
   add_exit("/players/mo/rig/ROOMS/cc/r3.c","out");
   
   
   add_item("walls","Cream colored walls.\n");
   add_item("photo","A group photo of the 2011 Chinle Oil Platform Toolhands.\n");
   add_item("desk","An oak desk with a phone and papers on it.\n");
   add_item("tools","Two broken wrenches.\n");
   add_item("phone","An old, black phone.\n");
   
   
   add_msg("The phone rings...\n");
   set_chance(10);
   add_object("/players/mo/rig/MON/headtoolhand.c");
   
}
