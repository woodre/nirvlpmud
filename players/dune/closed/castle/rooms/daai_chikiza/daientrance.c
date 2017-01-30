inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Cave entrance";
    long_desc=
"     Swirls of fog roll away as you descend into the underground\n"+
"city.  Da'ai Chikiza smells of the sea, and you faintly hear the\n"+
"crashing of waves deep into the cavernous city.\n";

    dest_dir=({
DAAICHIKIZAROOM+"/stairs1.c","down",
    });

    items=({
"entrance","     A dark tunnel leads downward into the cave",
"cave",    "     The cave entrance stands 20 feet tall, 15 feet wide",
"city",    "     The city is entirely undergound, like most Sithi cities",
    });
  }
}
