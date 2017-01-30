#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's western Aisle");
  set_long("");
 
  set_light(1);

 add_exit("east",ROOM+"crossing_aisle_west");
  
    
}

void init() {
  ::init();
}