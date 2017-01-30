#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("stahnk")) {
  move_object(clone_object("players/eurale/Keep/NPC/stahnk"),TO); }
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"You have come to a sort of room in the cave.  A stairway going\n"+
	"up and a stairway going down both leave this room as well as\n"+
	"the cave to the north taking you back toward where you began.\n"+
	"The light here is dim as the torches have almost burnt them-\n"+
	"themselves out.\n";

items = ({
	"stairway","Stone steps cut into the rock leading both up and\n"+
		"down from this room",
	"torches","Almost burnt wooden torches",
});

dest_dir = ({
	"players/eurale/Keep/k20.c","north",
	"players/eurale/Keep/k23.c","down",
	"players/eurale/Keep/k27.c","up",
});

}

init() {
  ::init();
  add_action("up","up");
  add_action("down","down");
}

up() {
if(present("stahnk")) {
  write("The stahnk growls and blocks your way...\n");
  say(capitalize(TPRN)+"'s way is blocked by the stahnk...\n");
  return 1; }
else {
  TP->move_player("up#players/eurale/Keep/k27.c");
  return 1; }
}

down() {
if(present("stahnk")) {
  write("The stahnk moves in front of the stairwell...\n");
  say("The stahnk blocks the stairwell..\n");
  return 1; }
else {
  TP->move_player("down#players/eurale/Keep/k23.c");
  return 1; }
}
