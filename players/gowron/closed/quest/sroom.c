inherit "room/room";

status gotsuit,can;
object suit;

reset(arg) {
	if (arg)
           return;
	set_light(1);
	short_desc = "Behind the cooling tower";
	long_desc = "You are now behind the cooling tower.  You "+
		    "successfully made it past the leak.  As you "+
		    "look around you see an old garbage can pretty "+
		    "close to you.  Kind of strange finding it here. "+
		    "You sense that it is in your health interests to leave "+
		    "this plant ASAP.\n"+
		    "You can go 'back' to the path if you'd like.\n";
	long_desc = format(long_desc, 75);
	items = ({ "can", "It is a garbage can.  Pretty normal.  A "+
			  "can with a lid on top" });
	can = 0;
	gotsuit = 0;
}

open_can(str) {
	if (!str) 
           return 0;
	if (str != "can") 
           return 0;
	if (!can) {
	   write("You take the lid off the can.\n");
           can = 1;
	   return 1;
	}
	else {
	   write("The can is already open!\n");
	   return 1;
	}
}

object ob;

search_can(str) {
	int i;

	if (!str)
           return 0;
	if (!str == "can") 
           return 0;
	if (!can) {
	   write("How can you search the can? The lid is still on!\n");
	   return 1;
	}
	if (gotsuit) {
           write("You search the can and find nothing.\n");
	   return 1;
	}
	i = random(9);
	i++;
	if (i > 8) {
	   write("You search the can and find nothing.\n");
	   return 1;
	}
	ob = clone_object("players/gowron/closed/quest/rsuit");
        gotsuit = 1;
	move_object(ob, this_player());
	write("You search through the can and find a radiation suit.\n");
	write("You then quickly put the lid back on the can..\n");
	can = 0;
	return 1;
}

	   
init() {
	add_action("open_can", "open");
        add_action("leave_room", "back");
	add_action("search_can", "search");
}	

leave_room() {
        this_player()->move_player("leaves#players/gowron/closed/quest/path1");
        return 1;
}
