inherit "room/room";

realm() { return "NT"; }

reset(arg) {
	object ob;
	set_light(1);
	short_desc = "Springfield Power Plant 1";
	long_desc = "You have ventured through the maze of corridors and "+
		    "arrived at the elevator to floor two.  As you look "+
		    "around you see a candy machine with a lot of workers "+
		    "gathered around it.\n"+
		    "You can leave via the 'elevator'\n";
	long_desc = format(long_desc, 75);
	items = ({ "machine", "It is a candy machine, and it is a shrine for the slackers here.\n", });
	if (!present("worker", this_object())) {
	ob = clone_object("players/gowron/closed/quest/floor1/lenny");
	move_object(ob, this_object());
	}
}
init() {
	add_action("advance_floor", "elevator");
}

advance_floor() {
	if (present("worker", this_object())) {
	   write("Lenny won't let you pass.\n");
	   return 1;
	}
	else {
           "players/gowron/closed/quest/floor1/room1"->clear_quester();
	   tell_object(this_player(), "The elevator moves you up to the "+
				      "2ndfloor.\n"); 
	   this_player()->move_player("to the next floor#"+
			"players/gowron/closed/quest/floor2/room1"); 
	}
	return 1;
}

