inherit "room/room";

object li;
reset(arg) {
	if (arg) {
	   if (!present("lisa", this_object())) {
	      li = clone_object("players/gowron/room/obj/lisa");
	      move_object(li, this_object());
	   }
	   return;
	}
	set_light(1);
	short_desc = "Lisa Simpson's room";
	long_desc = "As you enter the room the first thing you notice is the "+
		    "sharp contrast to the rest of the house.  This room is "+
		    "spotless.  Sitting on the bed is a young girl, about "+
		    "eight years old.  She is responsible for the saxophone "+
		    "music that lured you into the house in the first place.\n";
	long_desc = format(long_desc, 75);
	long_desc = format(long_desc, 75);
	dest_dir = ({ "/players/gowron/room/shall.c", "hall" });
	if (!present("lisa")) {
	   li = clone_object("/players/gowron/room/obj/lisa.c");
           move_object(li, this_object());
	}
}
