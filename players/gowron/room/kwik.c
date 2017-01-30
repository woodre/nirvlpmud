inherit "room/room";

reset(arg) {
	object abu;
	if (arg) {
	   if(!present("abu", this_object())) {
             abu = clone_object("players/gowron/room/obj/abu");
	     move_object(abu, this_object());
	   }
           return;
	}
	set_light(1);
	short_desc = "Kwik-E-Mart";
	long_desc = "You have entered the Springfield Kwik-E-Mart.  You "+
		    "look around and see what is in any convience store.  "+
		    "As you look towards the counter you see a man behind "+
		    "the counter.  He is hawking his company's new squishee.  "+
		    "He can probably sell you some products that will help "+
		    "with your journeys ahead.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/road5", "east" });
	if (!present("abu", this_object())) {
	   abu = clone_object("players/gowron/room/obj/abu");
	   move_object(abu, this_object());
	}
}



