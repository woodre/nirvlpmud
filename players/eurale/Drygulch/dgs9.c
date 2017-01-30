#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You are following an east/west roadway in Drygulch.  The land \n"+
	"is hard and the vegetation scarce.  There is a hardy cactus off \n"+
	"the side of the road and what appears to be fresh droppings.  To \n"+
	"the north is a sturdy looking building. \n";

items = ({
	"droppings","These droppings seem to be from a horse and from \n"+
		"the looks of them, they're pretty fresh",
	"cactus","This is a hardy and old barrel cactus",
	"building","The building looks like the sherrif's office",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs11.c","north",
	"/players/eurale/Drygulch/dgs10.c","east",
	"/players/eurale/Drygulch/dgs8.c","west",
});

}
