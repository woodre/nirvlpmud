okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "A dark forest";
  long_desc =
"    In front of you is a large log cabin within the twisted woods.  Any\n"+
"possible path leading away is not discernible- especially when the forest\n"+
"is this dark.  A general aura of discomfort and foreboding emanates from\n"+
"the forest around you.  An old four-door Nova is parked in the grass\n"+
"surrounding the cabin.\n";

  items = ({
"forest","The green forest around you seems to flicker and reshape itself",
"nova","The old car is sitting idle near the cabin",
"car","The old car is sitting idle near the cabin",
"cabin","The creaky, log cabin seems to scream evil",
});

  dest_dir = ({
ED1ROOM+"c8","enter",
ED1ROOM+"o2","west",
});
  }

init() {
  ::init();
  add_action("search","search");
  add_action("leave_here","north");
  add_action("leave_here","east");
  add_action("leave_here","south");
  add_action("leave_here","northwest");
  add_action("leave_here","southwest");
  add_action("leave_here","northeast");
  add_action("leave_here","southeast");
 }

leave_here() {
  write("The forest doesn't allow travel in that direction.\n"); return 1; }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you turn up nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }
