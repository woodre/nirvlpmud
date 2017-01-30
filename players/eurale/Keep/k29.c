#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("dragon")) {
move_object(clone_object("players/eurale/Keep/NPC/white_dragon"),TO); }
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You find yourself at the end of a large crack in the stone.\n"+
	"The crack is just wide enough to be able to turn around and\n"+
	"small pieces of the rock that have fallen as the crack widened\n"+
	"have filled in enough of the crack to provide a makeshift floor.\n"+
	"A close look at the floor reveals scattered bones and other\n"+
	"items.\n";

items = ({
	"pieces","Small pieces of stone that have chipped away as the\n"+
		"earth widened the crack",
	"floor","An uneven, stone-filled crack",
	"bones","They appear to be from assorted prey, both human and\n"+
		"animal.  Some even look fairly fresh...",
	"items","Pieces of gold scattered about",
});

dest_dir = ({
	"players/eurale/Keep/k28.c","out",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("out","out");
}

out() {
if(TP->query_attrib("luc") > random(35)) {
  TP->move_player("crack#players/eurale/Keep/k28.c");
  return 1; }
else {
  write("You try to squeeze into the crack but fail in your haste..\n");
  return 1; }
}
