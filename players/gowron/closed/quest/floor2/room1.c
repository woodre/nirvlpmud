inherit "room/room";

#define OCCUPANT quester->query_name() 
#define ADVANCE	write("The radiation is getting to you...\n")
#define IS_WORKER present("worker", this_object())

string dir_string;
int i;
object quester;

realm() { return "NT"; }

get_worker() {
	return clone_object("players/gowron/closed/quest/worker");
}

reset(arg) {
	if (arg) {
	   if (!IS_WORKER) 
	      move_object(get_worker(), this_object());
	   return;
	}
        set_light(1);
	short_desc = "Power Plant Floor 2";
  long_desc = "You are on the second floor of the power plant. It "+
		    "is open to all directions.  You want to get where "+
		    "you're going ASAP before the leaking radiation gets "+
		    "you.\n"+
		    "You can *leave* north,east,south or west\n";
	long_desc = format(long_desc, 75);
	move_object(get_worker(), this_object());
}

move_dir(str) {
	int dam;
	if (!present("suit", this_player())) {
	   dam = random(25)+1;
	   this_player()->heal_self(-dam);
	   write("The radiation leaks are damaging you.\n");
	   write("If only you had a radiation protection suit.\n");
	}
	if (i == 0) {
	   if (!(str == "e") && !(str == "east")) { 
	      write(long_desc);
	      return 1;
	   }
	   i++;
	   write("The radiation is starting to get to you...\n");
	   write(long_desc);
	   return 1;
	}
	if (i == 1) {
	   if (!(str == "s") && !(str == "south")) {
	      i = 0;
	      write(long_desc);
	      return 1;
	   }
	   i++;
	   write("The radiation is really starting to get to you..\n");
	   write(long_desc);
	   return 1;
	}
	if (i == 2) {
	   if (!(str == "e") && !(str == "east")) {
	      i = 0;
	      write(long_desc);
	      return 1;
	   }
	   i++;
	   write("The radiation is REALLY starting to get to you...\n");
	   write(long_desc);
	   return 1;
        }
	if (i == 3) {
	   if (!(str == "w") && !(str == "west")) {
	      i = 0;
	      write(long_desc);
	      return 1;
	   }
	   i++;
           write("Damn the radiation is getting to you.\n");
	   write(long_desc);
	   return 1;
	}
	if (i == 4) {
	   if (!(str == "n") && !(str == "north")) {
	      i = 0;
              write(long_desc);
	      return 1;
	   }
	   if (IS_WORKER) {
              write("The worker will not let you pass.\n");
	      return 1;
	   }	   
	   this_player()->move_player("west#players/gowron/closed/quest/"+
				"executive");   
	   write(format("You have finished the second floor, as you move "+
		        "on you know the showdown is near...\n", 75));
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
	if (this_player() == IS_WORKER) 
	   ok_enter = 1;
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
	add_action("move_dir", "leave");
	add_action("query_status", "qstat");
}

query_status() {
	    write("Room "+i+" in the sequence.\n");
            return 1;
}

