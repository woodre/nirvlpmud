inherit "room/room";

reset(arg) {
	object krusty;
	if (arg) {
	   if (!present("krusty")) {
              krusty = clone_object("players/gowron/room/obj/krusty");
	      move_object(krusty, this_object());
	   } 
	   return;
	}
	set_light(1);
	short_desc = "Springfield Road";
	long_desc = "The road seems to come to a stop here...  You can go "+
		    "and see the awes and wonders of Springfield Nuclear "+
		    "Power Plant to the east, or you could visit the old "+
		    "folks at the Springfield Retirement castle on the west. "+
		    "You also notice Krusty the Clown, one of Springfield's "+
		    "foremost entertainers walking by.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/road5", "north",
		      "players/gowron/room/rcastle", "west",
		      "players/gowron/room/plot", "east", });
	krusty = clone_object("players/gowron/room/obj/krusty");
	move_object(krusty, this_object());
}
