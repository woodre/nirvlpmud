inherit "room/room";

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
		   "It's in your best interest to read it.\n"+
		   "You can either start the quest or get outta here. to "+
		   "the west\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/closed/quest/floor1/room1", "east",
		      "players/gowron/closed/quest/start_room", "west", });
	items = ({ "sign", "By entering the power plant you agree "+
		 	   "to blend with the workforce and follow "+
			   "Mr. Burns' motto - 'you're never getting "+
			   "out of here'.  Or, in nirvanese, the onl"+
		  	   "y way out is to quit\n", });
}
	
init() {
	::init();
	destruct(present("card", this_player()));
}

