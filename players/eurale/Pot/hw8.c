#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Edge of Forbidden Forest";
long_desc =
  "  Immediately to the north looms the forbidden forest.  Eerie sounds eminate\n"+
  "from within the thick stand of old trees.  A creeping darkness that makes it\n"+
  "nearly impossible to see into the forest seems to blanket the entire area.\n"+
  "Under foot the ground is littered with branches.\n";

items = ({
  "forest","Dark and foreboding, the large trees grow thick and close together",
  "trees","Various kinds of tall oaks and elm",
  "branches","Whip-like and long from a large willow",
});

dest_dir = ({
  "players/eurale/Pot/hw8.c","north",
  "players/eurale/Pot/hw6.c","south",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
  add_action("North","north");
}

North() {
  write("An invisible force stops you from entering the forest.\n");
  return 1; }

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
