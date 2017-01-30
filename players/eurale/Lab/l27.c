#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("scorpion")) {
  move_object(clone_object("/players/eurale/Lab/NPC/scorpion.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  A narrow crevass in rock with barely enough room to turn around and\n"+
  "get out.  Sharp points of rock stick out of the walls, prohibiting\n"+
  "any further exploration.\n";

items = ({
  "points","The sharp ends of rock pieces, all pointing into the crack",
  "rock","Crystalline structure tinted reddish brown",
});

dest_dir = ({
  "players/eurale/Lab/l24.c","out",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("What?\n"); return 1; }
write("You search the "+str+" but find nothing of interest.\n");
return 1;
}
