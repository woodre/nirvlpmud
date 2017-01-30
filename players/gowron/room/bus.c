inherit "room/room";

reset(arg) {
	object otto;
	if (arg) {
	   if (!present("otto", this_object())) { 
	      otto = clone_object("players/gowron/room/obj/otto");
	      move_object(otto, this_object());
	   }
	   return;
	}
	set_light(1);
	short_desc = "Springfield Elementary Bus";
	long_desc = "As you climb into the bus you immediately take notice "+
		    "of the disorder in the place.  There is loud music, kids "+
		    "being wild and a bus driver who is oblivious to it all "+
		    "who appears to be immersed in his own music on his "+
		    "walkman.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/school", "out", });
	if (!present("otto", this_object())) {
	   otto = clone_object("players/gowron/room/obj/otto");
	   move_object(otto, this_object());
        }
}
