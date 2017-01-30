#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(!present("louis")) 
  move_object(clone_object("players/softly/point/mobs/louis"),this_object());
  if(arg) return;
set_light(1);

short_desc = "Forest Edge";
long_desc ="  An abrupt edge of densely crowded trees touches a small\n"+
           "beach almost devoid of vegetation.  The earth is sandy and pale.\n"+
           "Heavy mist hangs in the air but to the east in the distance\n"+
           "a vast blue-green sea is visible.  The edge of the forest\n"+
           "continues to the southwest.\n";

items = ({
  "trees","Scrub pines and a few oaks stop abruptly",
  "edge", "The forest suddenly stops at the edge of a sandy beach",
  "earth", "The grey brown earth is light and sandy.  It is soft\n"+
           "underfoot",
  "sea","The blue-green sea stretches as far as the eye can see",
  "mist","The air is white with mist, which hangs heavily over\n"+
         "the sand and the surface of the sea",
  "forest","The forest is has many pine and oak trees.  It seems\n"+
           "very old",
  });

dest_dir = ({
  "/players/softly/point/rooms/for9.c","southwest",
  "/players/softly/point/rooms/for11.c","east",
  });
}




