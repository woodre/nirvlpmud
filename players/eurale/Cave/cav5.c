/*  a teleporting maze for higher level players  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("hellhound 1")) {
  move_object(clone_object("players/eurale/Cave/NPC/hellhound"),TO); }
if(!present("messenger")) {
  move_object(clone_object("players/eurale/Cave/mess5"),TO); }

  if(arg) return;
set_light(0);

short_desc = "a dark cave";
long_desc =
	"  You stand in a carved out tunnel through the rocks.  The air \n"+
	"is cool and smells fairly musty like there isn't much movement \n"+
	"inside the cave.  The darkness is penetrating and you can just \n"+
	"make out the sides of the tunnel as you inch along.  Your foot- \n"+
	"steps echo slightly as you walk. \n";

items = ({
	"sides","The shadows make the sides of the cave appear and then \n"+
		"seem to disappear into the blackness",
});

dest_dir = ({
	"/players/eurale/Cave/cav4.c","north",
	"/players/eurale/Cave/cav6.c","west",
});

}

init() {
  ::init();
  add_action("west","west"); }

west() {
  object ob;
    ob = present("hellhound");
  if(present("hellhound")) {
  write("The hellhound blocks your path. \n");
  say(capitalize(TPRN)+" is forbidden to pass by the hellhound. \n");
  return 1; }
}
