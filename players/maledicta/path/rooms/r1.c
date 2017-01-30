#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a mountain trail";
long_desc =
"  This is a winding path that leads up the side of the huge mountain\n"+
"before you.  It curves upward, often at a steep angle and disappears\n"+
"over the lowest crest.  Several scraggly bushes line the path with a\n"+
"couple of small trees along the way.  The trail continues up the\n"+
"mountain or back down to the ravine.\n";  

items = ({
  "path",
  "A winding rocky path that leads up the mountain or down to the\n"+
  "ravine below",
  "mountain",
  "A large mountain range that spans a great distance into the north\n"+
  "and west",
  "crest",
  "The lowest crest of the mountain, and probably the only way to pass\n"+
  "over the mountain",
  "bushes", 
  "Scraggly bushes that somehow survive in the bare rock terrain",
  "trees", 
  "A couple of trees with strong roots and the ability to somehow survive",
  "ravine", 
  "A large ravine that cuts through the center of the two mountains",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r2.c","up",
  "/players/maledicta/castle/rooms/m2.c", "down",
});

}


