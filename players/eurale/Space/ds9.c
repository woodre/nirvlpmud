#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("hamster")) {
  move_object(clone_object("players/eurale/Space/NPC/hamster"),TO); }
set_light(0);

short_desc = "Deep Space";
long_desc =
  "  You step back into the deepest shadows of the crater.  The bottom\n"+
  "seems to be wider than the crater itself, providing a sort of over-\n"+
  "hang that you can get back under and hide.\n";

items = ({
	"overhang","Rock that has been cut away....search?\n",
});

dest_dir = ({
	"players/eurale/Space/ds6.c","west",
});

}

init() {
  ::init();
  add_action("search","search");
}

search(str) {
if(!str) { write("You search the crater floor carefully... and find\n"+
  		"nothing at all of significance...\n"); return 1; }
if(str == "overhang") {
  write("You carefully run your hands along the underside of the over-\n"+
	"hang and find nothing...\n");
  return 1; }
}
