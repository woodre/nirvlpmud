inherit "room/room";

string realm() { return "NT"; }

reset(arg) {
	if (arg) 
	   return;
	set_light(1);
	short_desc = "Power Plant";
	long_desc = "As you entered the power plant, you are immediately "+
		    "overwhelmed with not only toxic radiation but a very "+
		    "strong sense that there is something afoot.  There must "+
		   "be great evil around here.  You only wonder - where?\n"+
		   "There is a sign next to the door on the east.. "+
		   "It's in your best interest to check it out.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/closed/quest/start_room", "out",
		      "players/gowron/closed/quest/floor1/room1", "start" });
	items = ({ "sign", format("By entering the main power plant, you agree "+
			 "to blend with the workforce and follow Mr. "+
			 "Burns' motto - 'You're never getting out of "+
		         "here.  Or in Nirvanaese - The only way out is "+
			 "to quit", 75)
                   });
}

init() {
	add_action("cmd_start", "start");
	add_action("cmd_leave", "out");
}

cmd_start() {
	write("Good luck... you'll need it!\n");
	this_player()->move_player("start#players/gowron/closed/quest/floor1"+
				   "/room1");
	return 1;
}

cmd_leave() {
	write("Loser...\n");
	this_player()->move_player("leave#players/gowron/closed/quest/"+
				   "start_room");
	return 1;
}


