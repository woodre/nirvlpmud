/*  a teleporting maze for higher level players  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("jesse")) {
  move_object(clone_object("players/eurale/Maze/NPC/jesse"),TO); }

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
	"/players/eurale/Maze/tun1.c","north",
	"/players/eurale/Maze/tun11.c","south",
	"/players/eurale/Maze/tun13.c","east",
	"/players/eurale/Maze/tun9.c","west",
});

}
realm() { return "NT"; }

init() {
  ::init();
  add_action("east","east"); }

east() {
  object ob;
    ob = present("jesse");
  if(present("jesse")) {
    write("Jesse blocks your way. \n");
    say(capitalize(TPRN)+" is blocked by Jesse. \n");
  return 1; }
}
