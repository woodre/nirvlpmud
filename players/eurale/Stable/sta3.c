/*  Drygulch stable  */

#define tp this_plaher()->query name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch Stable";
long_desc =
	"  This is a very big building.  You've walked past the center \n"+
	"and there is more building yet to your south.  The place looks \n"+
	"kept.  There are small beams of sunlight coming through the \n"+
	"knotholes in the wooden walls and dust particles play in their \n"+
	"light. \n";

items = ({
	"sunlight","You must be kidding...... you'll burn your corneas",
	"dust","Little, tiny specks of dirt, dancing in the sun",
});

dest_dir = ({
	"/players/eurale/Stable/sta2.c","north",
	"/players/eurale/Stable/sta4.c","south",
	"/players/eurale/Stable/sta11.c","east",
	"/players/eurale/Stable/sta7.c","west",
});

}
