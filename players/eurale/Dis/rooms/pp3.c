#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Piglet Parkway";
long_desc =
	"  You have wandered onto Piglet Parkway.  It is a shady, dirt \n"+
	"path that meanders through a small forest.  The coolness of \n"+
	"the shade is a welcome relief from the blistering sun.  Wild \n"+
	"flowers grow along the edge of the parkway.  In a well-manicured \n"+
	"clearing to the west sits a small brick house.\n";

items = ({
	"flowers","Wild flowers of all kinds and colors.  They make the \n"+
		"air smell sweet and fresh",
	"forest","A small stand of aged hardwoods",
});

dest_dir = ({
	"players/eurale/Dis/rooms/pp4.c","north",
	"players/eurale/Dis/rooms/pp2.c","south",
	"players/eurale/Dis/rooms/pp14.c","west",
});

}
