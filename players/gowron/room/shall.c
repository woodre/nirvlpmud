inherit "room/room";

reset(arg) {
	set_light(1);
	short_desc = "Upstairs hall";
	long_desc = "Your climb up the stairs was certainly perilous.  You "+
		    "had your life flash before your eyes as you narrowly "+
		    "avoided Bart's skateboard which he had left in the middle "+
		    "of the staircase. Having made it safely up the stairs, "+
		    "you can clearly hear the saxophone music, without the "+
		    "background noise of the TV.  It is blues music.  Whoever "+
		    "is playing it must be depressed about something.  It is "+
		    "coming from behind the door.  You feel compelled to take "+
		    "a look and see who this aspiring musician is.  Behind "+
		    "another door you can see a boy, about 10 years old "+
		    "laying in his bed gazing in an almost comatose state "+
		    "straightforward.  Something compels you to "+
		    "investigate\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "/players/gowron/room/lisaroom.c", "door1",
		      "/players/gowron/room/bart_room", "door2",
		      "/players/gowron/room/shouse1.c", "down" });
}
