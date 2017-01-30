#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "the base of the mountain";
long_desc =
"  This is the base of a large mountain range that lies directly\n"+
"to the north.  A path winds up its face or continues to the south\n"+
"between the lower portions of the hills.  Trees are gathered about\n"+
"the top and sides of the hills.\n";  

items = ({
  "base",
  "The large base of the mountain range to the north",
  "mountain",
  "A tall mountain that stands to the north",
  "range",
  "A long mountain range that extends to the east and west",
  "path",
  "A rocky path that leads up the face of the mountain or south\n"+
  "into the hills",
  "hills",
  "Steep hills that extend outward to the south",
  "trees",
  "Medium sized trees that decorate the tops of the hills and where\n"+
  "ever they can find a foothold on the sides",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r3.c","up",
  "/players/maledicta/path/rooms/r5.c", "south",
});

}


