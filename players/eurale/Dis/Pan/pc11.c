#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Picadilly Circle";
long_desc =
	"  This is in one of London's older sections.  The cobblestone\n"+
	"street passes through a neighborhood of old brownstone buildings.\n"+
	"There is a park off to the south with large statues of lions \n"+
	"and historical figures that the children enjoy climbing.\n";

items = ({
	"park","Hyde Park, the most famous of the Royal Parks.  It \n"+
		"covers 360 acres and contains the famous 'Speakers \n"+
		"Corner' near Marble Arch",
	"buildings","Beautiful 2-story residential buildings",
	"statues","You can see the Achilles statue and the Albert \n"+
		"memorial",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc10.c","west",
	"players/eurale/Dis/Pan/pc12.c","southeast",
	"players/eurale/Dis/Pan/pch6.c","enter",
});

}
