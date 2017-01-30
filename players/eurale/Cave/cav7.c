#include "defs.h"
inherit "room/room";

reset(arg) {
if(!present("dontayne")) {
  move_object(clone_object("players/eurale/Cave/NPC/dontayne"),TO); }
  if(arg) return;
set_light(0);

short_desc = "a dark cave";
long_desc =
  "This crack has widened enough to resemble a very tiny room cut\n"+
  "into the solid stone.  A few pieces of charred wood lay on the\n"+
  "stone floor.  The blackness surrounding you prevents nearly all\n"+
  "visibility.\n";

items = ({
  "pieces","Burnt wood, possibly from a small fire",
  "wood","Blackened sticks, all that remains from a small fire",
});

dest_dir = ({
	"/players/eurale/Cave/cav6.c","out",
});

}
