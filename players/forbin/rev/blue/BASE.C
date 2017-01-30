#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(!present("salamite")) add_object(NPC+"warrior.c");      
  if(arg) return;
  short_desc = "";
  long_desc = 
    "\n";
  set_light(1);
  add_item("","");  
  set_chance(random(5));
    add_msg("Did something just brush past you?");
  add_listen("main", 
    "You listen closely and hear a slight scream.\n");
  add_smell("main", "You smell the acrid stench of sulfar.\n"); 
  add_exit(RMS+"cots02","north");
  add_exit(RMS+"cots04","east");
}
