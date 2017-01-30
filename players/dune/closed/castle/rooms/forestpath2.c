inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("Dark Forest");
    long_desc=
"     You are deep in a dark rain forest.  Tall trees loom above you,\n"+
"choking off the light of the sun.  Strangely, you hear no animal noises.\n"+
"The forest is silent, as if a dark tide has washed over the land.\n";

    dest_dir=({
CASTLEROOM+"/forestpath1.c","north",
CASTLEROOM+"/forestpath3.c","east" ,
    });

    items=({
"forest","     The Dark forest surrounds you",
"trees", "     The tall trees grow straight upward like dark pillars",
    });
  }
}
