inherit "obj/monster";

object gold;
reset(arg) {
	object hair;
	::reset(arg);
	if (arg) return;
	set_name("Marge");
	set_alias("marge");
	set_short("Marge Simpson");
	set_long(format("You are looking at a woman standing about 10 feet "+
		        "tall.  Although her hair makes up most of that "+
			"height, she is still pretty tall.  She is Marge "+
			"Simpson, the leader of this particular family.\n",75));
	set_level(16);
	set_wc(14+random(4));
	set_al(350);
	set_chat_chance(25);
	load_chat("Marge says: No violence on TV.  Ban Itchy & Scratchy!\n");
	load_chat("Marge says: Do you want to end the evil? Talk to me.\n");
	gold = clone_object("obj/money");
	gold->set_money(700+random(200));
	move_object(gold,this_object());
	hair = clone_object("/players/gowron/room/obj/hair");
	move_object(hair, this_object());
	init_command("wear hair");
	set_ac(10);
}


init() {
	add_action("talk_to", "talk");
}

talk_to(str) {
	if ((!str) || (!str == "to marge")) {
	   write("Talk to whom?\n");
	   return 1;
	}
	say("Marge says: Thank you, Thank you!\n");
	say("            There is a great evil pervading this town.\n");
	say("            Mr. Burns and Smithers are destroying the\n");
	say("            very fabric of our town.  You must stop them.\n");
	say("            You will need an ID card to get into the power\n");
	say("            plant.  Chances are a worker probably was drunk\n");
	say("            and forgot it at some bar.  Please, hurry.  I\n");
	say("            don't want anything to happen to my Homey!\n");
	say("                        Thank you!\n");
	return 1;
}

