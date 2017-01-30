/*  Drygulch stable  */

#define tp this_plaher()->query name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch Stable";
long_desc =
	"  You have reached the southern end of the building.  The shaded \n"+
	"coolness is a welcome relief from the heat outside.  The smell \n"+
	"of hay and manure is stronger here, away from the door.  The \n"+
	"stalls have run the entire length of the building on both sides. \n";

items = ({
});

dest_dir = ({
	"/players/eurale/Stable/sta3.c","north",
	"/players/eurale/Stable/sta12.c","east",
	"/players/eurale/Stable/sta8.c","west",
});

}
