inherit "obj/monster";

object gold;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("nelson");
	set_alias("bully");
	set_short("Nelson, the bully");
	set_long(format("Nelson, the bully.  He steals younger "+
			"kids lunch money and is a general, all"+
			"-purpose asshole.\n",75));
	set_level(14);
	set_hp(200+random(75));
	set_wc(15);
	set_al(-150);
	set_ac(6);
	set_chat_chance(10);
	load_chat("Nelson cackles out loud: Ha Ha.\n");
	load_chat("Nelson orders you to fork over your money.\n");
	gold = clone_object("obj/money");
	gold->set_money(550+random(250));
	move_object(gold, this_object());
}
