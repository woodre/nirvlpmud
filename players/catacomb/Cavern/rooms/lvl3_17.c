#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The ceiling looms high above letting in small rays of light.  The\n"+
"light shines down casting distorted shadows upon the ground.  The \n"+
"floor seems to slope downward to the north.  The sound of the trickling\n"+
"of water can be heard from the north.\n");

items = ({
  "ceiling",
  "The ceiling is several yards above.", 
  "rays",
  "Small cracks in the ceiling provide the light for the area", 
  "cracks",
  "Small cracks in the ceiling provide the light for the area",
  "floor",
  "The floor slopes downward to the north",
  "ground",
  "The floor slopes downward to the north",
  "shadows",
  "The light forms strange shaped shadows throughout the area"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_18.c","northeast",
  "/players/catacomb/Cavern/rooms/lvl3_16.c","northwest",
  "/players/catacomb/Cavern/rooms/lvl3_20.c","north" 
});
}

