#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("shadow dragon")) {
  move_object(clone_object("/players/eurale/Lab/NPC/shadow.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  This small cutout in the rock ends abruptly.  The close ceiling\n"+
  "curves up about 18 inches and out to the open area to the east.  On\n"+
  "the rock floor are some rusted pieces of metal.  A small path of\n"+
  "green, slimy matter also rests against the back wall.\n";

items = ({
  "cutout","Nothing more than a small cutout in the larger rock",
  "ceiling","Smooth, dark tan rock, probably from all the moisture",
  "pieces","They look like they once might have been hinges of some sort",
  "matter","Some kind of sea weed",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Crawl","crawl");
}

Crawl(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "east") {
  TP->move_player("crawling east#players/eurale/Lab/l16.c");
  return 1; }
}
