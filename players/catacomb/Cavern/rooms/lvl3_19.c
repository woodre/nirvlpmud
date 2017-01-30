#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  On the wall to the north, water slowly trickles down.  The light\n"+
"from the cracks in the ceiling show the water flowing to the south\n"+
"as if the ground is sloped.  The sound of water drops can be heard \n"+
"to the south.\n");

items = ({
  "wall",
  "Moisture from above trickles down the wall", 
  "water",
  "The water flows toward the center of the cavern", 
  "cracks",
  "The cracks allow a small amount of light into the area",
  "ceiling",
  "The cracks allow a small amount of light into the area",
  "ground",
  "The water flows toward the center of the cavern",
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_16.c","southwest",
  "/players/catacomb/Cavern/rooms/lvl3_18.c","southeast",
  "/players/catacomb/Cavern/rooms/lvl3_20.c","south" 
});
}

