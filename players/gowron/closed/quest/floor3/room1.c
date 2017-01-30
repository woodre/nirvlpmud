inherit "room/room";

#define OCCUPANT quester->query_name() 

string dir_string;
int i;
object quester;

realm() { return "NT"; }

reset(arg) {
	if (arg)
	   return;
        set_light(1);
	short_desc = "Power Plant Floor 2";
	long_desc = "You are on the first floor of the power plant.  It "+
		    "is open to all directions.  You want to get where "+
		    "you're going ASAP before the leaking radiation gets "+
		    "you.\n"+
		    "You can *GO* north,east,south or west\n";
	long_desc = format(long_desc, 75);
}

move_dir(str) {
	if (i == 0) {
	   if (!(str == "e") && !(str == "east")) { 
	      tell_object(quester, long_desc);
	      return 1;
	   }
	   i++;
	   write("The radiation is starting to get to you...\n");
	   tell_object(quester, long_desc);
	   return 1;
	}
	if (i == 1) {
	   if (!(str == "s") && !(str == "south")) {
	      i = 0;
	      tell_object(quester, long_desc);
	      return 1;
	   }
	   i++;
	   write("The radiation is really starting to get to you..\n");
	   tell_object(quester, long_desc);
	   return 1;
	}
	if (i == 2) {
	   if (!(str == "e") && !(str == "east")) {
	      i = 0;
	      tell_object(quester, long_desc);
	      return 1;
	   }
	   i++;
	   write("The radiation is starting to get to you...\n");
	   tell_object(quester, long_desc);
	   return 1;
        }
	if (i == 3) {
	   if (!(str == "w") && !(str == "west")) {
	      i = 0;
	      tell_object(quester, long_desc);
	      return 1;
	   }	   
	   quester->move_player("west#players/gowron/closed/quest/floor3/room1");	   
	   write(format("You have finished the second floor, as you move "+
		        "onto the third floor, you know the final "+
			"showdown is near...\n", 75));
	   "players/gowron/closed/quest/floor3/room1"->long();
	   return 1;
	}
	return 0;
}
	   
clear_quester() {
	quester = 0;
}

init() {
	int ok_enter;
	ok_enter = 0;
	if (this_player()->query_real_name() == "gowron")
	   ok_enter = 1;
	if (this_player()->query_real_name() == "gowtest" || "wizardchild")
           ok_enter = 1;
     	if (this_player() == quester)
           ok_enter = 1;
	if (!quester) {
           quester = this_player();
	   i = 0;
	   ok_enter = 1;
	}
        if (!ok_enter)
           quester->move_player("church#room/church");
	add_action("move_dir", "go");
	add_action("query_status", "qstat");
}

query_status() {
	if (quester->query_real_name() == "gowron") {
	    write("Room "+i+" in the sequence.\n");
            return 1;
	}
	return 0;
}

