#include "DEFS.h"
inherit "room/room";
int LURK;

reset(arg) {
  if(arg) return;
LURK = 1;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  This small cutout in the rock ends abruptly.  The close ceiling\n"+
  "curves up about 18 inches and out to the open area to the north.  On\n"+
  "the rock floor are some rusted pieces of metal.  A small patch of\n"+
  "green, slimy matter also rests against the back wall.\n";

items = ({
  "cutout","Nothing more than a small cutout in the larger rock",
  "ceiling","Smooth, dark tan rock, probably from all the moisture",
  "pieces","They look like they once might have been hinges of some sort",
  "metal","Rusted and partly eaten away, could have been hinges",
  "matter","Some kind of sea weed",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Crawl","crawl");
  add_action("Search","search",1);
}

Crawl(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "north") {
  TP->move_player("crawling north#players/eurale/Lab/l16.c");
  return 1; }
}

Search(str) {
if(!str) { write("Search what?\n"); return 1; }
if(str == "ceiling" && LURK == 1) {
  write("As you look up toward the ceiling, a gray mass comes\n"+
        "falling down, right into your face.\n\n");
  move_object(clone_object("/players/eurale/Lab/NPC/lurker.c"),TO);
  LURK = 0;
  return 1; }
write("You search the "+str+" but find nothing of interest.\n");
return 1;
}
