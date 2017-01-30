#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  The tunnel has opened up into a huge crack.  To the west is a small\n"+
  "opening leading toward the outside. High above the jagged walls of\n"+
  "this huge fissure, small beams of light shine down.  The floor is\n"+
  "covered with dirt and small patches of greenery grow wild.\n";

items = ({
  "crack","This oblong area leading through the rock must have been\n"+
          "caused millions of years ago during some rough upheaval",
  "tunnel","A small hole in the rock to the east",
  "opening","A small, dark hole leading back into the rock",
  "beams","Pencil-like shafts of light coming down from above",
  "floor","Dark, nearly black, maybe the result of centuries of erosion",
  "ledge","You seem to be too far away to tell anything",
});

dest_dir = ({
  "players/eurale/Lab/l19.c","east",
  "players/eurale/Lab/l24.c","west",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
  add_action("Climb","climb");
}

Search(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "walls") {
  write("You squint and search the jagged walls carefully. Above your\n"+
        "head is some sort of ledge you might be able to climb up on.\n");
  return 1; }
write("You search the "+str+" but find nothing of interest.\n");
return 1;
}

Climb(str) {
if(!str) { write("Climb what?\n"); return 1; }
if(str == "ledge" || str == "wall") {
  write("You carefully grab hold of pieces of the jagged wall and\n"+
        "climb up to the ledge.\n");
  TP->move_player("up the wall#players/eurale/Lab/l23.c");
  return 1; }
write("You try to climb the "+str+" but are unsuccessful.\n");
return 1;
}
