/*  a teleporting maze for higher level players  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {

if(!present("messenger")) {
move_object(clone_object("players/eurale/Cave/mess4.c"),
	this_object()); }

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
	"/players/eurale/Cave/cav5.c","south",
	"/players/eurale/Cave/cav3.c","east",
});

}
