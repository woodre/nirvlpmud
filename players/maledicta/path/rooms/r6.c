#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "the hills";
long_desc =
"  The hills stand tall all around as their sides turn into sheer\n"+
"cliffs on both sides.  Trees dot the upper portion of the hills\n"+
"and hang over the edges in short arches.  The path continues to\n"+
"the north and south.\n";  

items = ({
  "hills", 
  "Large hills that fill the valley",
  "cliffs",
  "Steep cliffs that are carved into the face of the\n"+
  "hills around you",
  "trees",
  "Medium sized trees that stand at the top of the hills",
  "path",
  "A winding path that leads from north to south",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r5.c","north",
  "/players/maledicta/path/rooms/r7.c", "south",
});

}


