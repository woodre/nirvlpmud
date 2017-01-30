#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  This is a small alcove within the caverns of the Durkor.  Torches\n"+
  "light the way to the east.  A ladder leads up to the first level\n"+
  "of the caverns.  Many rocks and boulders are scattered throughout\n"+
  "the passageway making it somewhat trecherous to navigate through.\n"+
  "Small creatures scurry around at the sight of intruders.\n"); 

  items = ({
    "alcove",
    "The walls block passage in all directions except east", 
    "walls",
    "The walls block passage in all directions except east", 
    "wall",
    "The walls block passage in all directions except east",
    "torches",
    "The torches' flames crackle giving of a sufficient light source",
    "torch",
    "The torch flickers light in all directions",
    "ladder",
    "A crude ladder reaches up to the first level of the caverns",
    "rocks",
    "Many sharp rocks line the passageway",
    "rock",
    "Torn flesh hangs from a jagged rock",
    "boulders",
    "Many sharp boulders line the passageway",
    "boulder",
    "Blood stains a single boulder in the middle of the passageway",
    "passageway",
    "Many sharp rocks line the passageway",
    "creatures",
    "Small creatures scurry through the passageway",
    "creature",
    "A small creature screeches at you before running under a rock",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl1_3.c","ladder",
    "/players/catacomb/Cavern/rooms/lvl2_2.c","east" 
  });
  
}

