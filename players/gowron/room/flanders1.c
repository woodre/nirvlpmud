inherit "room/room";

reset(arg) {
	object ned;
	if (arg) {
	   if (!present("flanders", this_object())) {
	      ned = clone_object("players/gowron/room/obj/flanders");
	      move_object(ned, this_object());
	   }
	   return;
	}
	set_light(1);
	short_desc = "Ned Flanders' house.";
	long_desc = "As you approach the Flanders' residence the feeling of "+
		    "overpowers you.  As you look around the yard, you see "+
		    "Ned Flanders, the patriarch of this family standing "+
		    "over a very nice looking BBQ grill.  He is apparently "+
		    "preparing some of his famous Flander-burgers.  They "+
		    "smell really good.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "/players/gowron/room/road2.c", "south", });
	if (!present("flanders")) {
	   ned = clone_object("/players/gowron/room/obj/flanders.c");
	   move_object(ned, this_object());
	}
}
