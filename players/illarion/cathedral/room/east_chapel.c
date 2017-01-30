#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's eastern Chapel");

  set_light(1);

  set_long("");
  add_exit("west",ROOM+"crossing_aisle_east");
  
    
}

void init() {
  ::init();
}