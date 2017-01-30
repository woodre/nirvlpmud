inherit "room/room";

#define ME this_player()

status card;

reset(arg) {	
	if (arg)
           return;
	card = 1;
	set_light(1);
	short_desc = "Bathroom in Moe's Tavern";
	long_desc = "You have entered the Bathroom in Moe's Tavern.  "+
		    "Immediately you are hit with the foul stench of "+
		    "vomit, alcohol and an uncleaned bathroom.  As you "+
		    "look around, you see that a bathroom stall is open "+
		    "and you can see one of the unsanitary toilets.  You "+
                    "know this is a public health code violation, and you "+
                    "also know that the Public Health Dept. won't care. "+
		    "To exit this filth, type 'leave'.\n";
        long_desc = format(long_desc, 70);
	items = ({ "toilet", "As you look at the toilet you see why "+
			     "nobody in there right mind uses public "+
			     "restrooms.  As you look more carefully "+
			     "you notice something on the floor next "+
			     "to the toilet",
		    "floor", "You see a springfield power plant ID" });
}

search_room(str) {
	if (!str) 
           return 0;
	if (str != "floor") 
	   return 0;
	if (card) {
	   move_object(clone_object("players/gowron/room/idcard"), ME);
	   card = 0;
	   say(ME->query_name()+" gropes through whatever the hell that "+
	       "is on the floor and finds and ID card.\n");
	   write("You search through the filth on the floor and find an "+
		 "ID card.\n");
	}
	else 
	   write("You flail around searching and find nothing.\n");
        return 1;
}
cmd_leave() {
	this_player()->move_player("away#players/gowron/room/moes");
	return 1;
}

init() {
	add_action("search_room", "search");
        add_action("get_card","take");
	add_action("cmd_leave", "leave");
}
get_card(str) {
 
   if(str!="ID" && str!="id" && str!="card") return 0;
   move_object(clone_object("players/gowron/room/idcard"), ME);
   return 1;
}

