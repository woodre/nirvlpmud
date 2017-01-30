inherit "room/room";

object get_marge() {
	return clone_object("players/gowron/room/obj/marge");
}

reset(arg) {
	object marg;
	if (arg) {
	   if (!present("marge")) 
	      move_object(get_marge(), this_object());
	   return;
	}
	set_light(1);
	short_desc = "The Simpson's Kitchen";
	long_desc = "You have entered the Simpson's kitchen.  Directly in "+
		    "front of you is the kitchen table where the family eats "+
		    "its meals.  You see Marge Simpson over by the stove "+
		    "she is frying  something.  Perhaps if you took a closer look at the stove you "+
		    "could see what she is cooking, because it sure smells good.  "+
		    "Homer is expected home soon, and obviously he will be hungry.\n";
	long_desc = format(long_desc, 75);
       dest_dir = ({ "/players/gowron/room/shouse1.c", "south", });
	move_object(get_marge(), this_object());
}
