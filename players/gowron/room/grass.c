inherit "room/room";

reset(arg) {
	object willie;
	if (arg) {
           if (!present("willie", this_object())) {
	      willie = clone_object("players/gowron/room/obj/willie");
	      move_object(willie, this_object());
	   }
           return;
	}
	set_light(1);
	short_desc = "Springfield Elementary Lawn";
	long_desc = "You are in the middle of an open field.  Willie is here. "+
		    "He appears to be taking a break from his lawn duties.  "+
		    "He is coming towards you.  I don't think he likes you "+
		    "walking on his freshly planted and mowed grass.  Willie "+
		    "tends to be quite aggressive about these things.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/school", "walkway", });
	if (!present("willie", this_object())) {
	   willie = clone_object("players/gowron/room/obj/willie");
	   move_object(willie, this_object());
	}
}
