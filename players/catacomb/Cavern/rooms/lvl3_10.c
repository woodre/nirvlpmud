#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The stonework of the stairs is excellent.  No dust on them signifies\n"+
"that these are used very often by the Durkor.  Up ahead awaits a large \n"+
"stone bridge almost scraping the ceiling of caverns.  Below awaits the \n"+
"shadows cast by the bridge, and the horrors contained within them. \n");

items = ({
  "bridge",
  "A stone bridge lies up ahead", 
  "staircase",
  "The staircase leads up to the bridge", 
  "stonework",
  "The craftsmanship is definately of dwarven heritage",
  "stairs",
  "The quality of the craftsmanship of the stairs is like nothing you've seen before",
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_11.c","west",
  "/players/catacomb/Cavern/rooms/lvl3_9.c","down", 
  });
  }

