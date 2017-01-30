#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Memory Lane";
long_desc =
	"  This red cobblestone road has been worn smooth by the passage \n"+
	"of travelers.  The carriages of nobles find the going easy along\n"+
	"this highway that leads to the castle up on the hill.\n";

items = ({
	"road","Red cobblestones, hand-laid and fitted so that the surface\n"+
		"is level and smooth",
});

dest_dir = ({
	"players/eurale/Dis/rooms/ml5.c","south",
	"players/eurale/Dis/rooms/ml7.c","north",
});

}
