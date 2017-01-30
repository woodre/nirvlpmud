#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("wendy")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/wendy"),TO); }
if(!present("peter pan")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/peter"),TO); }

  if(arg) return;
set_light(1);

short_desc = "A Hiding Place";
long_desc =
	"  As you thump on the stump, the insides quickly fall away and\n"+
	"you tumble in.  You find yourself in the hiding place of the\n"+
	"Lost Boys of the island.  It is a warm and safe haven from \n"+
	"whatever might be chasing you.\n";

items = ({
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc17.c","leave",
});

}
