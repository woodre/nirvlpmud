inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("The Far Foothills");
    long_desc=
"     Tall foothills bump across the land irregularly.\n"+
"Various trees, but mainly pine, grow everywhere.\n"+
"To the south, the hills eventually become tall snow-capped\n"+
"mountains. A tall green tower stands before you...\n"+
"the Elemental Tower.\n";

    dest_dir=({
CASTLEROOM+"/green19.c","east"  ,
OLDCASTLE+"/floor1.c", "tower"  ,
CASTLEROOM+"/hill11.c","south"  ,
    });

   items=({
"foothills","     Smooth steep foothills surround you",
"mountains","     Tall snow-capped mountains tower over the hills",
"trees",    "     Trees grow all over the hills and up the mountains",
"land",     "     The hilly land is like large swells in a sea",
"tower",    "     Before you stands The Elemental Tower!",
    });
  }
}
