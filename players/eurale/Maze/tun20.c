/*  a teleporting maze for higher level players  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("diablo")) {
  move_object(clone_object("players/eurale/Maze/NPC/diablo"),TO); }

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
	"/players/eurale/Drygulch/dgs7.c","south",
	"/players/eurale/Maze/tun19.c","east",
});

}

init() {
  ::init();
  add_action("south","south");
  add_action("search","search");
}

south() {
  object ob;
    ob = present("diablo");
    if(present("diablo")) {
    write("Diablo blocks your way! \n");
    say(capitalize(TPRN)+" is blocked by Diablo! \n");
  return 1; }
}

search(str) {
string s1,s2;
object ob;
  ob = present("corpse",this_object());
  if(!present("diablo") && present("corpse")) {
	if(!str) { write("The area reveals nothing.....\n"); return 1; }
 	if(str == "body") {
   move_object(clone_object("players/eurale/Maze/OBJ/rood"),TP);
	write("You find a tiny silver crucifix.\n");
	destruct(ob);
	return 1; }
  return 1; }
}
