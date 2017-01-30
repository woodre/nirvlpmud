/*  Drygulch stable  */

#define tp this_plaher()->query name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch Stable";
long_desc =
	"  You are near the center of the building.  The straw-covered \n"+
	"floor muffles your footsteps.  The large doorway to the north \n"+
	"cuts a large sillouette in the wall which provides the only \n"+
	"light in the building.  The stalls on either side could provide \n"+
	"ample hiding for those with dastardly ideas. \n";

items = ({
	"stalls","The shaddowed stalls play tricks on your eyes",
});

dest_dir = ({
	"/players/eurale/Stable/sta1.c","north",
	"/players/eurale/Stable/sta3.c","south",
	"/players/eurale/Stable/sta10.c","east",
	"/players/eurale/Stable/sta6.c","west",
});

}
