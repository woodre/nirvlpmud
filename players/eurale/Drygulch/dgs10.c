#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You have come to the end of road.  It stops in front of a fairly \n"+
	"large building with some lettering on the front.  The large front \n"+
	"opening with it's swinging doors would make it a secure place if \n"+
	"it ever came under attack.  You can hear the sound of horses \n"+
	"pawing and snorting in the building.  Off to the north is another \n"+
	"small building. \n";

items = ({
	"lettering","The lettering reads:  Drygulch Stables",
	"opening","The inside of the building is too dark to make anything out",
	"doors","Sturdy, plank doors on large hinges that will swing shut \n"+
		"to seal the structure",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs13.c","north",
	"/players/eurale/Stable/sta1.c","south",
	"/players/eurale/Drygulch/dgs9.c","west",
});

}
