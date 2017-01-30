#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a stone path";
long_desc =
"  The path slopes down the hill, its uneven stones leading down to a small\n"+
"patch of trees. The path leads back to the outcropping, and continues down\n"+
"the hill.\n";

items = ({
  "outcropping",
  "A small jutting mound that extends from the mountain to the east",
  "path",
  "An uneven path made of stone, it continues down the hill or back\n"+
  "up to the outcropping",
  "stones",
  "Weathered and uneven, they were placed here a long time ago by\n"+
  "a now unknown craftsman",
  "trees",
  "A small grouping of pine trees. They are very tall and seem\n"+
  "strong",
  "hill",
  "A downward slope that flows from the mountain"
  });

dest_dir = ({
  "/players/maledicta/castle/rooms/m6.c","west",
  "/players/maledicta/castle/rooms/m3.c","east",
  });
}
