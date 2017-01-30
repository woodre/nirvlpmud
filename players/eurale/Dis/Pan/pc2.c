#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Westminster Bridge";
long_desc =
	"  You stand in the middle of the Westminster Bridge.  The mighty\n"+
	"Thames River runs underneath you.  To the east you can see\n"+
	"Westminster Bridge Road disappear into the city and to the\n"+
	"west between the houses you can see patches of a park.\n";

items = ({
	"bridge","An old and majestic bridge",
	"river","An angry, greenish, fast-flowing river",
	"houses","Typical, two-story brownstone buildings",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc3.c","west",
	"players/eurale/Dis/Pan/pc1.c","east",
});

}
