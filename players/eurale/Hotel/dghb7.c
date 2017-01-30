#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Drygulch Hotel basement";
long_desc =
	"  As you lean against the rack, the wall gives way allowing you \n"+
	"to pass beyond into a secret room.  It is unfinished and hides \n"+
	"a steep tunnel going down into the darkness.  The wall has swung \n"+
	"back into position but might allow you to leave the way you came \n"+
	"in.  The smell of musty air lingers.  \n";

items = ({
	"tunnel","A cave, large enough to stand in and decending into the \n"+
		"the darkness below",
});

dest_dir = ({
	"/players/eurale/Hotel/dghb6.c","west",
	"/players/eurale/Maze/tun1.c","down",
});

}
