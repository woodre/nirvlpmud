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
"  This is the top of the southern mountain, at it's lowest\n"+
"crest.  A path winds down to the ravine or continues to the\n"+
"south and then down the side of the mountain.  To both sides\n"+
"the mountain range rises up and casts a long shadow over this\n"+
"narrow pass.\n";  

items = ({
  "path",
  "A winding rocky path that curves along the mountain and runs through\n"+
  "a small pass at its crest",
  "mountain",
  "A large mountain range that spans a great distance into the north\n"+
  "and west",
  "crest",
  "The lowest crest of the mountain, and probably the only way to pass\n"+
  "over the mountain. A path leads through it",
  "ravine", 
  "A large ravine that cuts through the center of the two mountains",
  "shadow",
  "A long shadow cast by the mountains",
  "pass", 
  "A small pass at the top of the mountain. It is the lowest point of the\n"+
  "range",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r3.c","south",
  "/players/maledicta/path/rooms/r1.c", "down",
});

}


