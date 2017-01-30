inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("An Office - Chinle Oil Platform");
   set_long(
"This is the office of the Head of Operations.  Photographs line the\n"+
      "walls. The desk has a phone and a lamp on it.  Stacks of cabinets are\n"+
      "in the corner of the room.  A putting green is sitting in the\n"+
      "middle of the room.\n");
   add_exit("/players/mo/rig/ROOMS/cc/r5.c","out");
   
   
   add_item("walls","Cream colored walls.\n");
   add_item("photographs","Photographs of Heads of Operations at other Chinle Oil Co wells.\n");
   add_item("desk","An oak desk with a phone and papers on it.\n");
   add_item("lamp","A small desk lamp.\n");
   add_item("green","A large putting green with artificial grass.\n");
   add_item("phone","An old, black phone.\n");
   
   
   add_msg("The phone rings...\n");
   set_chance(10);
   add_object("/players/mo/rig/MON/headoperations.c");
   
}
