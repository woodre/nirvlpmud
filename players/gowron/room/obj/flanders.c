inherit "obj/monster";

object gold;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("Flanders");
	set_alias("flanders");
	set_short("Ned Flanders");
	set_long(format("Ned Flanders.  The man who Homer is jealous of.  "+
			"Also the most naive next door neighboor ever.  "+
			"He is a strongly religious family man.\n", 75));
	set_level(18);
	set_wc(17);
	set_ac(10);
	set_hp(350+random(50));
	gold = clone_object("obj/money");
	gold->set_money(900+random(200));
	move_object(gold, this_object());
	set_al(500);
	set_chat_chance(10);
	load_chat("Flanders greets you: Hidily Ho neighbor!\n");
	load_chat("Flanders agrees: Okily Dokily\n");
	load_chat("Flanders says: That BBQ smells scrum-didily umptious!\n");
}
