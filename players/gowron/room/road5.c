inherit "room/room";

reset(arg) {
	if (arg)
           return;
	set_light(1);
	short_desc = "Springfield Road";
	long_desc = "You continue traveling down Springfield Road.  "+
		    "There are still more businesses to your left and "+
		    "right.  As you look east you see Springfield "+
		    "Elementary School.  To your west you see Abu's "+
		    "Kwik-E-Mart convience store.  The twin towers are "+
		    "appearing bigger and bigger as you draw closer to the "+
		    "Nuclear power plant to the south.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/road4", "north",
		      "players/gowron/room/school", "east",
		      "players/gowron/room/kwik", "west",
		      "players/gowron/room/road6", "south", });
}
