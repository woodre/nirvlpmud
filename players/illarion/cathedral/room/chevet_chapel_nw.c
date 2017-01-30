#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's northwestern Chevet Chapel");
  set_long("");

  set_light(1);

  add_exit("southeast",ROOM+"ambulatory");
  
    
}

void init() {
  ::init();
}