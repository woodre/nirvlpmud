#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("minion 1")) {
move_object(clone_object("players/eurale/Keep/NPC/fire_minion1"),TO); }
if(!present("minion 2")) {
move_object(clone_object("players/eurale/Keep/NPC/fire_minion2"),TO); }
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You stand at the top of a long, curved stairway.  Before you\n"+
	"is the grand room of the Death Knight.  It is rumored that few\n"+
	"who enter ever come out alive.\n";

items = ({
	"room","It is too dark to make anything out clearly",
	"stairway","Dual descending stairways",
});

dest_dir = ({
	"players/eurale/Keep/k63.c","enter",
	"players/eurale/Keep/k61.c","southwest",
	"players/eurale/Keep/k61.c","southeast",
});

}

init() {
  ::init();
  add_action("enter","enter");
}

enter() {
if(present("minion")) {
  write("The flame flares up and you step back...\n");
  say(capitalize(TPRN)+" steps back from the flame...\n");
  return 1; }
else {
  this_player()->move_player("grand room#players/eurale/Keep/k63.c");
  return 1; }
}
