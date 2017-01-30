#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The heat radiates off the river of lava to the south.  The\n"+
  "flames from the river shoot up at regular intervals making\n"+
  "travel across the bridge to the south dangerous.  The Durkor\n"+
  "talk of a ruler of the flame somewhere within the caves.  Very\n"+
  "few enjoy talking about its wrath.\n"); 

  items = ({
    "river",
    "Flames leap out of the river of lava, scorching everything in their path",
    "lava",
    "The lava slowly passes by", 
    "flame",
    "The flame consumes everything that they touch", 
    "flames",
    "The flames consume everything that they touch",
    "bridge",
    "The flames from the river jump between the steps of the bridge",
    "steps",
    "The steps amazingly are the only thing the flames don't destroy"
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_4.c","west",
    "/players/catacomb/Cavern/rooms/lvl2_bridge.c","bridge"
  });
}
