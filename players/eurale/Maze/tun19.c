/*  a teleporting maze for higher level players  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("hellhound 1")) {
  move_object(clone_object("players/eurale/Maze/NPC/hellhound1"),TO); }
if(!present("hellhound 2")) {
  move_object(clone_object("players/eurale/Maze/NPC/hellhound2"),TO); }

  if(arg) return;
set_light(0);

short_desc = "a dark cave";
long_desc =
	"  You stand in a carved out tunnel through the rocks.  The air \n"+
	"is damp and musty and it is very hard to see.  The floor is \n"+
	"covered with sand to make it as flat and smooth as possible. \n"+
	"The jagged rocks sticking out along the sides pose a serious \n"+
	"threat of injury if you continue.  The tunnel looks like it has \n"+
	"been used recently. \n";

items = ({
	"sand","It appears the sand came from another portion of the tunnel \n"+
		"or from outside altogether",
});

dest_dir = ({
	"/players/eurale/Maze/tun18.c","north",
	"/players/eurale/Maze/tun4.c","south",
	"/players/eurale/Maze/tun10.c","east",
	"/players/eurale/Maze/tun20.c","west",
});

}
realm() { return "NT"; }

init() {
  ::init();
  add_action("west","west"); }

west() {
  object ob;
    ob = present("hellhound");
  if(present("hellhound")) {
  write("The hellhound blocks your way.\n");
  say(capitalize(TPRN)+" is blocked by the hellhound.\n");
  return 1; }
}
