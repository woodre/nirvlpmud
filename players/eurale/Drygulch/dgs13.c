#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You have traveled a short distance to the north and now stand \n"+
	"in front of the Drygulch Barber Shop to the north.  You can make \n"+
	"out the sherrif's office to the west and the stable to the south. \n"+
	"The barber shop has a small sign tacked to the front by the door.\n";

items = ({
	"sign","The sign reads:  Haircut/Shave - 5 cents",
});

dest_dir = ({
	"/players/eurale/Drygulch/barber.c","enter",
	"/players/eurale/Drygulch/dgs10.c","south",
});

}
