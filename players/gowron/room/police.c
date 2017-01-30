inherit "room/room.c";

reset(arg) {
	object chief;
	if (arg) {
	   if (!present("chief", this_object())) {
	      chief = clone_object("players/gowron/room/obj/wiggum");
	      move_object(chief, this_object());
	   }
	   return;
	}
	set_light(1);
	short_desc = "Springfield PD";
	long_desc = "You are in the headquarters of the Springfield Police "+
		    "Dept.  You see many of the 'boys in blue' kicking back "+
		    "with some donuts and coffee.  You hear a phone ringing "+
		    "incesently in the background.  Wonder why nobody is "+
		    "answering it??  A big fat guy, probably the police chief "+
		    "is sitting directly in front of you, he has a maple bar in "+
		    "his left hand and a cup of coffee in the other.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/road4", "east", });
	if (!present("chief", this_object())) {
	   chief = clone_object("players/gowron/room/obj/wiggum");
	   move_object(chief, this_object());
	}
}

