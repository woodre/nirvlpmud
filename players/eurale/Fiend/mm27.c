#include "DEFS.h"
inherit "room/room";

reset(arg) {
if(!present("messenger")) {
  move_object(clone_object("players/eurale/Fiend/NPC/mess27"),TO); }
if(!present("werewolf")) {
  move_object(clone_object("players/eurale/Fiend/NPC/werewolf"),TO); }
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  This is an eerie place.  The shrubbery has been left unattended\n"+
	"for so long that it's grown out of control.  Thorny bushes grow\n"+
	"in abundance everywhere.  The huge weeping willow trees cast\n"+
	"long, dark shadows... making it impossible to see.\n";
	

items = ({
	"bushes","Dense, tall bushes with 2 inch thorns on it's branches",
	"trees","Old trees with branches that reach the ground",
	"shrubbery","Various bushes and vines, all out of control",
});

dest_dir = ({
	"players/eurale/Fiend/mm28.c","north",
	"players/eurale/Fiend/mm26.c","south",
});

}
init() {
  ::init();
  TP->set_fight_area();
}
