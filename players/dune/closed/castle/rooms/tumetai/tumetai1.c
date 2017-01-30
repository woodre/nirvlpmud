inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(0);
    short_desc=("The Caverns of Tumetai");
    long_desc=
"     This cave entrance is wide and tall.  Ancient runes are\n"+
"carved upon the walls.  Several formations, now crumbled, represent\n"+
"an old civilization.  Tiny stalagmites and stalagtites puncture\n"+
"the walls.\n";

    dest_dir=({
CASTLEROOM+"/tumetai2.c","west"  ,
    });

    items=({
"runes",      "     The runes are ancient Sithi writing",
"stalagmites","     The stalagmites rest peacefully on the floor",
"stalagtites","     They hang from the ceiling like needles",
"floor",      "     The floor is littered with loose rock and pebbles",
"walls",      "     The walls bend in every direction",
    });
  }
}
