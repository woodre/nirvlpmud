inherit "room/room";

reset(arg) {
	set_light(1);
	short_desc = "Springfield Elementary";
	long_desc = "Your are standing in front of Springfield Elementary "+
		    "School.  You can see a large yellow bus with a strange "+
		    "looking driver parked in front of the building.  The "+
		    "man who is riding on his john deere tractor in front of "+
		    "the school must be Willie the maintence man.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/bus", "bus",
		       "players/gowron/room/road5", "west",
		       "players/gowron/room/grass", "grass", });
}
