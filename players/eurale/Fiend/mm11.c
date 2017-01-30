#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  This is an eerie place.  The shrubbery has been left unattended\n"+
	"for so long that you can't see through or over it.  The gravel\n"+
	"path that works it's way along the wall is somewhat overgrown\n"+
	"and hard to see.  Thorn bushes grow in abundance.  The gnarly\n"+
	"weeping willow trees with their drooping branches further add\n"+
	"to your inability to navigate.  To the east is a large building\n"+
	"that has obviously fallen into disrepair.\n";

items = ({
	"wall","A high stone wall, too high to climb here",
	"bushes","Dense, tall bushes with 2 inch thorns on it's branches",
	"trees","Old trees with branches that reach the ground",
	"shrubbery","Various bushes and vines, all out of control",
	"building","This stately old build has seen better days.  A \n"+
		"number of the windows have been broken out and there\n"+
		"are some broken boards in the floor of what was once\n"+
		"a marvelous porch",
});

dest_dir = ({
	"players/eurale/Fiend/mm12.c","north",
	"players/eurale/Fiend/mm33.c","east",
	"players/eurale/Fiend/mm10.c","west",
});

}
init() {
  ::init();
  tp->set_fight_area();
}
