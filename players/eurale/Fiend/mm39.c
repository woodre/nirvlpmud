#include "DEFS.h"
inherit "room/room";

reset(arg) {
if(!present("kong")) {
  move_object(clone_object("players/eurale/Fiend/NPC/kong"),TO); }
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  You have reached the northern boundaries of this 'island-like'\n"+
	"structure surrounded by the deep ravine.  The path that winds\n"+
	"it's way though the ferns and palm trees is barely visible most\n"+
	"of the time.\n";

items = ({
	"ferns","Large, glossy leaves that grow in huge clumps",
	"palms","Tall, stoney-skinned Royal palms",
});

dest_dir = ({
	"players/eurale/Fiend/mm38.c","south",
});

}
init() {
  ::init();
  TP->set_fight_area();
}
