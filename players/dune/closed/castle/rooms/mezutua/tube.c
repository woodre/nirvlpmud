inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(0);
    short_desc=("Cavern entrance");
    long_desc=
"     You are in what appears to be some sort of lava tube.\n"+
"It leads into a cavern further ahead. The tube floors and walls are\n"+
"smoothened by occupation.\n";

    dest_dir=({
CASTLEROOM+"/north1.c","north",
CASTLEROOM+"/east1.c","east",
    });

    items=({
"cavern","     The tube becomes less circular and smooth. Eventually, it seems\n"+
         "to form a sort of rough cavernous path",
"outdoors","     The sounds of wind upon trees relaxes you",
"tube",    "     The tube must have been made by hot lava decades ago",
    });
  }
}
