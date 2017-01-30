#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Drygulch Hotel";
long_desc =
	"  You stand in the entranceway of what used to be a very \n"+
	"fine hotel.  Unfortunately, it has seen better days.  The \n"+
	"woodwork has weathered severely and the place looks gener- \n"+
	"ally run down.  You can make out a large open area to the \n"+
	"north and south takes you back out into the street. \n";

items = ({
	"woodwork","The wooden trim, once painted, has peeled and \n"+
		   "is generally dry-rotted",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh2.c","north",
	"/players/eurale/Drygulch/dgs1.c","south",
});

}
