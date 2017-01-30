inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(!present("Kalas",this_object()))
    move_object(clone_object(HMON+"kalas"),this_object());
  if(arg) return;

  set_light(1);
  set_short("A grand stage");
  set_long("\
You stand on the boards of a large music hall stage.  Though it may be very \
impressive during productions, at present the effect is quite creepy.  Unfinished \
props litter the stage, and bright lights hanging above the auditorium \
harsh shadows.  The same props block access to the wings, but a temporary \
wooden staircase allows direct access to the auditorium.\n");

  set_light(1);

  add_item("boards","Wooden boards.");
  add_item("stage","You're standing on it.  If you're standing.");
  add_item("props","Props that appear to be for several different shows.  "
          +"A large sheet of glass catches your eye especially.");
  add_item("glass","A large sheet of glass.  There's something odd about it... like you could "
          +BLD("pass")+" right through it.");
  add_item("lights","Stage lights.  The glare can be quite painful, as they're set for working, not a show.");
  add_item("wings","Totally blocked.  Someone should notify the fire marshall.");
  add_item("staircase","Cheap plywood, leading to the auditorium.");
  add_item("auditorium","Plush red seats, rising upward.  You can't see much through the glare of the lights.");

  add_exit("north",HROOM+"mhall_audience");
}
void init() {
  add_action("cmd_pass","pass");
}
status cmd_pass(string arg) {
  if(arg != "through glass") FAIL("Pass through what?\n");
  TP->move_player("through the glass#"+HROOM+"kitchen");
  return 1;
}