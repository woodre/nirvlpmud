inherit "room/room";

reset(arg) {
	object nel;
	if (arg) {
	   if (!present("nelson")) {
              nel = clone_object("players/gowron/room/obj/nelson");
	      move_object(nel, this_object());
	   }
	   return;
	}
	short_desc = "Springfield Road";
	long_desc = "You continue down Springfield Road.  You look around at your surroundings "+
		    "and see a rather large kid.  His name is Nelson, and he "+
		    "is the resident bully at Springfield Elementary School. "+
		    "Nelson is not a nice guy.  As you look to your north, you "+
		    "see Nelson's exact opposite.  You see the residence of the "+
		    "Flanders', and it looks as though there is an angelic "+
		    "aura around the house.  You "+
		    "feel the urge to explore this town some more.\n";
	long_desc = format(long_desc, 75);
	set_light(1);
	dest_dir = ({ "/players/gowron/room/flanders1.c", "north",
      "/players/gowron/room/road3.c", "east",
      "/players/gowron/room/road1.c", "west", });
      if (!present("nelson")) {
	nel = clone_object("/players/gowron/room/obj/nelson.c");
	move_object(nel, this_object());
	}
}
