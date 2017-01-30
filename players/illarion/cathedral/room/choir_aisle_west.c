#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's Western Aisle");
  set_long("\
The aisles are the lower-ceilinged areas along the cathedral's east and west walls.  \
This section of the western aisle borders on the choir.  It continues to both \
the south and the north.  It is brightly lit by light shining down from the \
choir's clerestory; the light illiuminates a variety of items, installed on pedestals.\
");

  set_light(1);
  
  add_item("wall","The outer walls of the cathedral are made of grey stone.");
  add_item("clerestory","The upper section of the cathedral, where windows let in light.");
  add_item("items","You spot handcuffs, both metal and furry, a whip, rope in every variety from silk to rawhide, and a number of other toys.  Kinky.");
  add_item("pedestals","Simple marble stands.");
  

  add_exit("north",ROOM+"sanctuary_aisle_west");
  add_exit("east",ROOM+"choir");
  add_exit("south",ROOM+"crossing_aisle_west");
  
    
}

void init() {
  ::init();
}
