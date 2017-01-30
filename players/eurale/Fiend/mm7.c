#include "DEFS.h"
inherit "room/room";
int dr;

reset(arg) {
if(!present("messenger")) {
  move_object(clone_object("players/eurale/Fiend/NPC/mess26"),TO); }
dr = 0;
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  This is an eerie place.  The shrubbery has been left unattended\n"+
	"for so long that you can't see through or over it.  The gravel\n"+
	"path that works it's way along the wall is somewhat overgrown\n"+
	"and hard to see.  Thorn bushes grow in abundance.  The gnarly\n"+
	"weeping willow trees with their drooping branches further add\n"+
    "to your inability to navigate.  To the east is a flat, white\n"+
    "building.\n";

items = ({
	"wall","A high stone wall, too high to climb here",
	"bushes","Dense, tall bushes with 2 inch thorns on it's branches",
	"trees","Old trees with branches that reach the ground",
	"shrubbery","Various bushes and vines, all out of control",
	"building","This white, stucco building has bars on the windows\n"+
		"and looks as through it might be a lab of some kind",
});

dest_dir = ({
	"players/eurale/Fiend/mm6.c","south",
	"players/eurale/Fiend/mm31.c","east",
	"players/eurale/Fiend/mm8.c","west",
});

}

init() {
  ::init();
  add_action("open","open");
  add_action("east","east");
  TP->set_fight_area();
}

open(str) {
if(str == "door") {
  if(dr == 1) { write("The door is already open..\n"); return 1; }
  write("The heavy door swings open.....\n");
  say(capitalize(TPRN)+" opens the heavy door....\n");
  dr = 1;
 return 1; }
}

east() {
if(dr == 0) { write("The door is closed..\n"); return 1; }
if(dr == 1) { TP->move_player("east#players/eurale/Fiend/mm31.c");
	return 1; }
}
