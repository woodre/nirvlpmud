#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You finish the long walk out of town to the Indian camp.  They \n"+
	"have come to trade and buy goods.  There are teepees set up in \n"+
	"a sort of circle about this center fire pit.  Each teepee has \n"+
	"drawings depicting special events of the owner's life painted \n"+
	"on the side. \n";

items = ({
	"pit","This fire pit, located in the center of the teepees, is \n"+
		"a place where people meet, cook, and smoke peace pipe",
	"drawings","Crude pictures telling the life story of the owner",
});

dest_dir = ({
	"/players/eurale/Drygulch/tent1.c","northeast",
	"/players/eurale/Drygulch/tent2.c","north",
	"/players/eurale/Drygulch/tent3.c","northwest",
	"/players/eurale/Drygulch/tent4.c","west",
	"/players/eurale/Drygulch/tent5.c","southwest",
	"/players/eurale/Drygulch/dgs14.c","southeast",
});

}
