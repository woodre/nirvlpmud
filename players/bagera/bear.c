inherit "obj/treasure";
reset(arg) {
set_id("teddybear");
set_alias("bear");




	set_short("A cute beyond belief teddybear");
        set_long("This is the cutest teddybear you've ever seen.  It has a smiling mouth,\n" +
        "two little marble eyes, and the cutest little ears you ever\n" +
        "saw!  A small tag on the tuft of tail reads:\n" +
        "\n" +
		  "--------------------------------\n" +
		 "| To my love, Bagera:          |\n" +
		 "| Love you!                    |\n" +
		 "|                              |\n" +
		 "| If you get lonely, type      |\n" +
		 "| 'rump' or 'bhug'.            |\n" +
		  "--------------------------------\n" +
        "\n");
}

init()
{ add_action("rump","rump");
  add_action("hug","bhug");
}

rump() {
	write("Rumplemintz appears in a puff of smoke.\n");
	write("Rumplemintz says: Hiya Daun!!\n");
	write("Rumplemintz says: Hope your thinkin of me!\n");
	write("Rumplemintz kisses you.\nRumplemintz hugs you.\n");
	write("Rumplemintz turns around, sticks it out, and wiggles it(just a lil' bit).\n");
	write("Rumplemintz says: Let's Chill...\n");
	say(call_other(this_player(),"query_name") + " hugs her teddy bear.\n");
	return 1;
	}
hug() {
	write("I miss you Daun, just pretend i'm there. *kiss*\n");
	return 1;
	}
query_auto_load() {return "/players/rumplemintz/closed/bear:";}
