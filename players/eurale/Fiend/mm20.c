#include "DEFS.h"
inherit "room/room";

reset(arg) {
if(!present("gremlin 2")) {
  move_object(clone_object("players/eurale/Fiend/NPC/gremlin2"),TO); }
if(!present("gremlin 3")) {
  move_object(clone_object("players/eurale/Fiend/NPC/gremlin3"),TO); }
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  This is an eerie place.  The shrubbery has been left unattended\n"+
	"for so long that you can't see through or over it.  The gravel\n"+
	"path that works it's way along the wall is somewhat overgrown\n"+
	"and hard to see.  Thorn bushes grow in abundance.  The gnarly\n"+
	"weeping willow trees with their drooping branches further add\n"+
	"to your inability to navigate.\n";

items = ({
	"wall","A high stone wall, too high to climb here",
	"bushes","Dense, tall bushes with 2 inch thorns on it's branches",
	"trees","Old trees with branches that reach the ground",
	"shrubbery","Various bushes and vines, all out of control",
});

dest_dir = ({
	"players/eurale/Fiend/mm19.c","north",
	"players/eurale/Fiend/mm21.c","east",
});

}
init() {
  ::init();
  TP->set_fight_area();
}
