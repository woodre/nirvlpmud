inherit "obj/monster";

status carded,must_bribe;

void reset(int arg) {
   ::reset(arg);
	if (arg)
           return;
	set_name("guard");
	set_alias("security guard");
	set_short("A plant security guard");
	set_long("This guy is a plant security guard.   He obviously "+
		 "doesn't care too much for his job.\n");
	set_level(15);
	set_hp(10000);
	set_wc(50);
	set_ac(25);
	carded = 0;
}

int enter_plant() {
	if (carded) {
	   this_player()->move_player("into plant#"+
				"players/gowron/closed/quest/lobby");
	   carded = 0;
	   return 1;
	}
	if (!present("card", this_player())) {
	   write("Guard says: Hey you don't work here!\n");
	   return 1;
	}
	if (!carded) {
	   write("Guard says: Hey let's see some ID!\n");
	   return 1;
	}
}

int show_id(string str) {
	int i;

	if ((!str) || (str != "id")) {
	   write("Show what?\n");
	   return 1;
	}
	if (!present("card", this_player())) {
           write("You don't have a card!\n");
	   return 1;
	}
	i = random(10)+1;
	if (must_bribe) {
	   write("Where are your donuts for me?\n");
	   return 1;
	}
	if (i > 7) {
	   write("Guard says: Not so fast, that's not you on the card.\n");
	   write("Guard says: To pass it's gonna cost you a box of donuts\n");
	   must_bribe = 1;
	   return 1;
	}
	else {
	   write("Guard says: okay, you're good...\n");
	   destruct(present("card", this_player()));
	   this_player()->move_player("into plant#"+
			"players/gowron/closed/quest/lobby");
	}
	return 1;
}

int bribe_me() {
	if (!present("donuts", this_player())) {
	   write("You don't have any donuts!\n");
	   return 1;
	}
	else {
	   write("Okay, I guess I'll let you pass...\n");
	   carded = 1;
	   must_bribe = 0;
	   destruct(present("donuts", this_player()));
	   
           return 1;
	}
}

void init() {
	add_action("show_id", "show");
	add_action("enter_plant", "in");
	add_action("bribe_me", "bribe");
}
