#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("catoblepas")) {
  move_object(clone_object("/players/eurale/Lab/NPC/catoblepas.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  Dark, rippled water surrounds your head as you tread water in this\n"+
  "small cavern.  About 3 inches above the water line is a fairly flat\n"+
  "stone shelf.  There is about 2 feet of air space above your head\n"+
  "here and the echoes of your breathing is all that can be heard.\n";

items = ({
  "water","Black and deep, the pool is about 4 feet in diameter here\n"+
          "in this hidden cavern",
  "pool","Dark water that looks deep enough to dive into",
  "shelf","A low rock formation, nearly at water level that looks as\n"+
          "though it would provide a place to get out of the pool if\n"+
          "one climbed up on it",
  "cavern","A small space hallowed out of the rock",
});

dest_dir = ({
  "players/eurale/Lab/l12.c","shore",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("climb","climb");
}
climb(str) {
if(!str) { write("Climb?\n"); return 1; }
if(str == "shelf" || str == "stone shelf") {
  write("You pull yourself out of the water onto the "+str+".\n");
  TP->move_player("out of the water#players/eurale/Lab/l16.c");
  return 1; }
}
