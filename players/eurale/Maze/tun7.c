/*  a teleporting maze for higher level players  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("wolf 1")) {
  move_object(clone_object("players/eurale/Maze/NPC/wolf1"),TO); }
if(!present("wolf 2")) {
  move_object(clone_object("players/eurale/Maze/NPC/wolf2"),TO); }

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
	"/players/eurale/Maze/tun8.c","north",
	"/players/eurale/Maze/tun3.c","south",
	"/players/eurale/Maze/tun2.c","east",
	"/players/eurale/Maze/tun6.c","west",
});

}
realm() { return "NT"; }

init() {
  ::init();
  add_action("north","north"); }

north() {
object ob;
  ob = present("wolf");
  if(present("wolf")) {
  write("The wolf stops you from going that way!\n");
  say("The wolf stops "+capitalize(TPRN)+" from going that way!\n");
return 1; }
}
