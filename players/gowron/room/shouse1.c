inherit "room/room";

reset(arg) {
	if (arg) 
	   return;
	short_desc = "The Simpson's Living Room";
	long_desc = "As you step into the Simpson house, the first thing you "+
		    "see is the TV set is gone!! The kitchen is to the north.  "+
		    "The saxophone music which initially drew you into this "+
		    "house is coming from the upstairs floor.  "+
		    "Go up to find out the source of this music.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "/players/gowron/room/shall.c", "up",
		      "/players/gowron/room/simpson1.c", "out",
		      "/players/gowron/room/skitchen", "north", });
	set_light(1);
}

