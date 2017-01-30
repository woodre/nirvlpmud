inherit "room/room";

reset(arg) {
	object grandpa;
	if (arg) {
	   if (!present("grandpa", this_object())) {
	      grandpa = clone_object("players/gowron/room/obj/grandpa");
	      move_object(grandpa, this_object());
	   }
	   return;
	}
	set_light(1);
	short_desc = "Springfield Retirement Castle";
	long_desc = "You have entered the Springfield Retirement castle.  "+
		    "Amazingly it takes you right into Grandpa Simpson's "+
		    "room.  This is where his family dumped him because "+
		    "they didn't want to take care of him.  He is sitting "+
		    "on his bed, he looks like he wants some attention.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/road6", "east", });
	if (!present("grandpa", this_object())) {
	   grandpa = clone_object("players/gowron/room/obj/grandpa");
	   move_object(grandpa, this_object());
        }
}
