inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;

  set_short("A darkened auditorium");
  set_long("\
You are among the seats in a plush, darkened auditorium.  Several large lights overhead \
are projecting light at the stage to the south, but there is no direct light.  \
All of the exits seem to be chained shut; the only place left to go is up \
the temporary staircase leading to the stage to the south.");


  add_item("stage","Looks kind of spooky.");
  add_item("lights","Stage lights.  The glare can be quite painful, as they're set for working, not a show.");
  add_item("exits","All chained shut.  Forget about it.");
  add_item("staircase","Cheap plywood, leading to the auditorium.");
  add_item("auditorium","You're standing in it.");
  add_item("seats","Really nice.  But there's no concert right now.");
  add_item("staircase","Cheap plywood.");

  add_exit("south",HROOM+"mhall_stage");
}
