inherit "/players/wocket/graveyard/groom.c";
#include "randomroomdesc.h"

reset(arg){
  ::reset();
  short_desc = "A cave";
  get_random_long();
  dest_dir = ({
  "/open/wocket/cavetest/mainpath2.c","west",
  "/open/wocket/cavetest/apath2.c","northeast",
  });
set_light(1);
}

