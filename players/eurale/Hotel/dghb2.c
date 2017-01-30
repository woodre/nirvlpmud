#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Drygulch Hotel basement";
long_desc =
	"  The basement is a cool and musty place.  Cobwebs hanging from \n"+
	"the beams indicate that there have not been many visitors here \n"+
	"in the recent past. More doorways lead to other parts of the \n"+
	"basement from here. \n";

items = ({
	"cobwebs","Intricate and delicate and very large.  From the size \n"+
		"it would seem to have taken a long time to make",
	"doorways","It is too dark to see through the doorways from here",
});

dest_dir = ({
	"/players/eurale/Hotel/dghb1.c","north",
	"/players/eurale/Hotel/dghb6.c","east",
	"/players/eurale/Hotel/dghb4.c","west",
});

}
