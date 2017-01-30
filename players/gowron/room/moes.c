inherit "room/room";

reset(arg) {
	object barkeep;
	if (arg) {
	   if (!present("moe")) {
	      barkeep = clone_object("players/gowron/room/obj/moe");
	      move_object(barkeep, this_object());
	   }
	   return;
	}
	set_light(1);
	short_desc = "Moe's Tavern";
	long_desc = "You are in Moe's tavern.  This is where the men of the "+
		    "town come to unwind or just get smashed.  There is a "+
		    "door in the north end of the bar.  The man behind "+
		    "the bar must be Moe.  You think you can probably buy some "+
		     "heals here.\n";
	dest_dir = ({ "players/gowron/room/road4", "west", 
		      "players/gowron/closed/quest/bathroom", "north", });
	long_desc = format(long_desc, 75);
	if (!present("moe")) {
	   barkeep = clone_object("players/gowron/room/obj/moe");
	   move_object(barkeep, this_object());
        }
}
