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
	"to your inability to navigate.  The wall here has begun to\n"+
	"deteriorate with long cracks running between the stones.\n";

items = ({
	"wall","A high stone wall, too high to climb that has some mysterious\n"+
	"looking cracks, almost as if it were a secret panel that you\n"+
	"could push",
	"bushes","Dense, tall bushes with 2 inch thorns on it's branches",
	"trees","Old trees with branches that reach the ground",
	"shrubbery","Various bushes and vines, all out of control",
	"cracks","Strange looking, too perfect.. a secret panel perhapss",
});

dest_dir = ({
	"players/eurale/Fiend/mm13.c","north",
	"players/eurale/Fiend/mm11.c","south",
});

}
init() {
  ::init();
  add_action("push","push");
  tp->set_fight_area();
}

push(str) {
if(!str) { write("What are you pushing?\n"); return 1; }
if(str == "wall" || str == "panel") {
  this_player()->move_player("disappears#players/eurale/Fiend/pub.c");
  return 1; }
}
