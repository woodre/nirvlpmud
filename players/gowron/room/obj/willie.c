inherit "obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if (arg) return;
	set_name("willie");
	set_alias("groundskeeper");
	set_short("Groundskeeper Willie");
	set_long(format("This is Groundskeeper Willie.  He is "+
			"well-built and would probably inflict "+
			"some damage upon you if you piss him off.\n",75));
	set_level(18);
	set_hp(400);
	set_al(150);
	set_wc(19);
	set_ac(11);
	gold = clone_object("obj/money");
	gold->set_money(random(1200));
	move_object(gold, this_object());
}
