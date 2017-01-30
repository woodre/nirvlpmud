/*  a teleporting maze for higher level players  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
if(!present("messenger")) {
move_object(clone_object("players/eurale/Maze/mess1.c"),this_object()); }
  if(arg) return;
set_light(0);

short_desc = "a dark cave";
long_desc =
	"  You stand in a carved out tunnel through the rocks.  The air \n"+
	"is damp and musty and it is very hard to see.  The floor is \n"+
	"covered with sand to make it as flat and smooth as possible. \n"+
	"The jagged rocks sticking out along the sides pose a serious \n"+
	"threat of injury if you continue.  The tunnel looks like it has \n"+
	"been used recently.  There is a wooden board with some lettering \n"+
	"scrawled on it sticking in the sand. \n";

items = ({
	"sand","It appears the sand came from another portion of the tunnel \n"+
		"or from outside altogether",
	"board","The scribbled handwriting reads:  Beware those who would \n"+
		"be foolish enough to enter these tunnels.  Many have tried \n"+
		"to find the treasure supposedly kept here and their bones \n"+
		"can still be found along the way.  Turn back while you \n"+
		"still can.... \n",
});

dest_dir = ({
	"/players/eurale/Maze/tun2.c","north",
	"/players/eurale/Hotel/dghb7.c","up",
});

}
