#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's Eastern Aisle");
  set_long("\
The aisles are the lower-ceilinged areas along the cathedral's east and west walls.\
This section of the eastern aisle borders on the choir.  It continues to both \
the south and the north.  It is brightly lit by light shining down from the \
choir's clerestory; the light illiuminates a variety of baubles, installed on pedestals.\
");
  
  add_item("wall","The outer walls of the cathedral are made of grey stone.");
  add_item("clerestory","The upper section of the cathedral, where windows let in light.");
  add_item("baubles","Shiny baubles of all shapes, sizes, and variety.  Many of them are golden or diamond rings, but there is also a large jeweled tiara, and a simple golden ribbon.");
  add_item("pedestals","Simple marble stands.");
  
  set_light(1);

  
  add_exit("north",ROOM+"sanctuary_aisle_east");
  add_exit("west",ROOM+"choir");
  add_exit("south",ROOM+"crossing_aisle_east");
    
}

void init() {
  ::init();
}