#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You step off the road to the south and up on the porch of the \n"+
	"Drygulch Saloon.  You can hear laughter and shouting coming from \n"+
	"within... over the tinkling of the player piano.  The swinging \n"+
	"doors to the south are an invitation to what sounds like a good \n"+
	"time. \n";

items = ({
	"porch","A long covered porch, open to the street",
	"doors","The swinging doors are more for ornament than function",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs8.c","north",
	"/players/eurale/Drygulch/saloon.c","south",
});

}
