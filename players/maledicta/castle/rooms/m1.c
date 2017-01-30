#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a pass between the mountains";
long_desc =
"  You stand between two towering mountains, their mass looming over you\n"+
"like a pair of behemoths. A small trail leads further along the pass to\n"+
"the west, rounding the northern most mountain near its base.\n";

items = ({
  "shadow",
  "You see that it engulfs the pass when the sun is either to the west or\n"+
  "east, the mountains allowing the light to only shine when it is directly\n"+
  "overhead",	
  "mountain",
  "You peer out and up at the northern mountain, its peak covered in snow\n"+
  "and mostly obscured by clouds. Its rocky base is speckled with an\n"+
  "occassional tree, or some other vegetation",
  "mountains",
  "Between the two you feel their crushing weight mentally upon you. A\n"+
  "deep shadow engulfs the pass as sunlight is blocked from both sides\n"+
  "by the two great giants",
  "pass",
  "A natural level area that allows for easy passage through the mountain\n"+
  "range",
  "trail",
  "A well used trail that leads through the mountain range" 
});

dest_dir = ({
  "/players/maledicta/castle/rooms/m2.c","west",
  "/room/ravine.c", "east",
});

}
