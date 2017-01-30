inherit "room/room";

get_homer() {
	object ho;
	ho = clone_object("players/gowron/room/obj/homer");
	move_object(ho, this_object());
}

reset(arg) {
	if (arg) {
	   if (!present("homer", this_object()))
              get_homer();
	   return;
	}
	set_light(1);
	short_desc = "Parking Lot";
	long_desc = "You are in the parking lot of the Springfield "+
		    "Nuclear Power Plant.  Getting past the security "+
		    "guard was easy.  You didn't really want to disrupt "+
		    "his sleep.  As you get closer and closer to the "+
		    "plant you notice how poorly maintained and "+
		    "contaminated this place actually is.  You see a trail "+
		    "that seems to go back behind the cooling tower as well. "+
		    "You now know "+
		    "why Burns has to funnel so much money to the safety "+
		    "inspectors.  You know that inspectors job paid good, "+
		    "but you didn't know they could drive a different car "+
		    "every day of th week.\n"+
		    "Oh look.. Here comes one of the workers.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/road6", "west",
		      "players/gowron/closed/quest/path1", "trail", 
		      "players/gowron/closed/quest/start_room", "east", });
	get_homer();
}

	
