#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You've traveled a long ways to get here.  To the north is a large \n"+
	"building with a sign on the front.  The makeshift, rutted path \n"+
	"that serves as a road leads off to the south, east and west. \n";

items = ({
	"sign","The weathered sign reads:  Drygulch Hotel",
	"building","A fairly well-kept building with a nice porch and \n"+
		"lots of windows",
	"path","They call this path a road although it hasn't seen much \n"+
		"traffic lately",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh1.c","north",
	"/players/eurale/Drygulch/dgs2.c","south",
	"/players/eurale/Drygulch/dgs8.c","east",
	"/players/eurale/Drygulch/dgs14.c","west",
});

}
