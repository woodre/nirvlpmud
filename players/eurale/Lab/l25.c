#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("abishai")) {
  move_object(clone_object("/players/eurale/Lab/NPC/abishai.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  A small pocket in the rock situated just under the land surface\n"+
  "above.  Roots of varius sizes criss-cross their way through the\n"+
  "air space and then redig themselves into oblivion on the other\n"+
  "side.  The air is fresher and sweeter smelling up here closer to\n"+
  "the sunlight.\n";

items = ({
  "pocket","Left by falling dirt and rock, it is well hidden from below",
  "roots","Tree roots with hair-like strings hanging off, all looking\n"+
          "for water",
});

dest_dir = ({
  "players/eurale/Lab/l24.c","down",
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
