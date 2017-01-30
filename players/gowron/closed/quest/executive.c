inherit "room/room";

int door;

realm() { return "NT"; }

get_worker() { 
	return clone_object("players/gowron/closed/quest/fworker");
}

dstat() {
	if (!door)
           return "closed";
	else
           return "open";
}

reset(arg) {
	if (arg) {
	   if (!present("worker")) 
	      move_object(get_worker(), this_object());
           return;
	}
	door = 0;
	set_light(1);
	short_desc = "Executive Hallway";
	long_desc = "As you walk down the Executive Hallway towards the "+
		    "imposing doors to office of Smithers & Burns.  You "+
		    "feel that the evil is emminating from behind those "+
		    "doors.  You notice an employee walking down the hall "+
		    "towards the hallways which you just left.  He looks "+
		    "kind of upset, and wonder what just went on in that "+
		    "office..\n"+
		    "You can 'enter' the office.\n";
	long_desc = format(long_desc, 75);
	items = ({ "doors", "They are about 20 feet tall and look very "+
			    "imposing.  They are "+dstat()+" right now.\n", });
	dest_dir = ({ "room/church", "back", });
	move_object(get_worker(), this_object());
}

move_me() {
	if (present("worker")) {
           write("The worker will not let you pass.\n");
	   return 1;
	}
	if (!door) {
           write("Ouch! You walk right into the door.  That hurt.\n");
	   this_player()->heal_self(-random(10));
	   return 1;
	}
	this_player()->move_player("into the office#"+
				   "players/gowron/closed/quest/floor2/br");
	return 1;
}

check_worker(str) {
	if ((!str) || (!str == "door")) {
	   write("Open what?\n");
	   return;
	}
	if (door != 0) {
           write("The door is already open.\n");
	   return 1;
	}
	door = 1;
	return 1;
}
	
	
init() {
	add_action("move_me", "enter");
	add_action("check_worker", "open");
}

