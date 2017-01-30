/*  a teleporting maze for higher level players  */

#define tp this_plaher()->query name()
inherit "room/room";

reset(arg) {
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
	"/players/eurale/Maze/tun14.c","south",
	"/players/eurale/Maze/tun9.c","east",
	"/players/eurale/Maze/tun12.c","west",
});

}
realm() { return "NT"; }
