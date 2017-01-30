inherit "room/room";

reset(int arg) {
	object mil;
	if (arg) {
	   if (!present("milhouse")) {
	      mil = clone_object("players/gowron/room/obj/milhouse");
	      move_object(mil, this_object());
	   }
	   return;
	}
	set_light(1);
	short_desc = "Springfield Road";
	long_desc = "You are traveling along Springfield Road.  Springfield is"+
		    " a small town.  Everybody seems to know everybody else. "+
		    "Glancing to your north and south you see many houses.  "+
		    "Presumably low-cost housing for families.  You can faintly "+
		    "make out the sound of saxophone music in that same direction.  "+
		    "Some gut feeling of yours urges you to investigate.  "+
		    "A ways down the road to the east, you can see the main "+
		    "business district of town.  You also see the famous "+
		    "'twin towers' of Springfield Nuclear Power Plant off "+
		     "to the southeast...\n";
	long_desc = format(long_desc, 75);
	items = ({ "house", "It appears the house of the Simpson family." });
	dest_dir = ({ "/players/gowron/room/simpson1.c", "north",
		      "/players/gowron/room/entrance.c", "west",
		      "/players/gowron/room/road2.c", "east", });
	mil = clone_object("players/gowron/room/obj/milhouse");
	move_object(mil, this_object());
}
