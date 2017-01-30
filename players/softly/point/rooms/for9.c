#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Forest Edge";
long_desc ="  An abrupt edge of densely crowded trees touches a small\n"+
           "beach almost devoid of vegetation.  The earth is sandy and\n"+
           "pale.  Heavy mist hangs in the air but to the east in the\n"+
           "distance a vast blue-green sea is visible.\n";

items = ({
  "trees","Scrub pines and a few oaks stop abruptly",
  "forest","The forest has many pine and oak trees.  It seems\n"+
           "very old",
  "edge", "The forest suddenly stops at the edge of a sandy beach",
  "earth", "The grey brown earth is light and sandy.  It is soft\n"+
           "underfoot",
  "sea","The blue-green sea stretches as far as the eye can see",
  "mist","The air is white with mist, which hangs heavily over\n"+
         "the sand and the surface of the sea",
  "beach","The narrow beach of grey brown sand reaches from the\n"+
          "the edge of the forest to the sea",
  });

dest_dir = ({
  "/players/softly/point/rooms/for4.c","south",
  "/players/softly/point/rooms/for12.c","east",
  "/players/softly/point/rooms/for10.c","northeast",

  });
}




