#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral Ambulatory");  
  set_long("\
You are in the Cathedral's Ambulatory, a semi-circular path behind the Sanctuary.  \
It exists to provide access to the relatively small chapels which radiate outward \
to the northwest, north, and northeast.  The massive statues behind the altar \
block direct access to the Sanctuary.  To return to the rest of the cathedral \
you must use the aisles to the southeast and southwest.\
");
 
  set_light(1);
  
  add_item("ambulatory","That's where you are.");
  add_item("cathedral","......");
  add_item("sanctuary","You can't really see it from here.  The statues are in the way.");
  add_item("statues","Completely nude statues of a man and a woman, entangled in an intimate embrace.");
  add_item("chapels","You can't really see much from here.");
  add_item("altar","You can't see it from here.");
  add_item("aisles","The ambulatory connects the aisles in a semi-circle behind the sanctuary.");

  add_exit("southwest",ROOM+"sanctuary_aisle_west");
  add_exit("southeast",ROOM+"sanctuary_aisle_east");
  add_exit("north",ROOM+"chevet_chapel_n");
  add_exit("northwest",ROOM+"chevet_chapel_nw");
  add_exit("northeast",ROOM+"chevet_chapel_ne");
   
}

void init() {
  ::init();
}