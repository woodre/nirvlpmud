#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Memory Lane";
long_desc =
	"  This red cobblestone road has been worn smooth by the passage \n"+
	"of travelers.  The carriages of nobles find the going easy along\n"+
	"this highway that leads to the castle up on the hill.  To the \n"+
	"south is an English tudor house with multi-paned windows.  The\n"+
	"yard is well kept and looks lovely.\n";

items = ({
	"road","Red cobblestones, hand-laid and fitted so that the surface\n"+
		"is level and smooth",
	"house","A traditional tudor style house",
});

dest_dir = ({
	"players/eurale/Dis/rooms/ml3.c","north",
	"players/eurale/Dis/rooms/ml12.c","in",
});

}
