#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "the southern forest";
long_desc =
"  The hills flatten out here and turn into a thick forest of\n"+
"beautiful trees.  The path continues south deeper into the\n"+
"forest or to the north towards the hills.\n";  

items = ({
  "hills",
  "The hills here are lower than those to the north and are\n"+
  "covered with thicker vegetation and trees",
  "vegetation",
  "Thick grasses and shrubs",
  "trees",
  "Tall trees with thick green canopies",
  "path",
  "A straight path that continues south to the forest and north\n"+
  "back into the tall hills",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r8.c","north",
  "/room/south/sforst24.c","south",
});

}


