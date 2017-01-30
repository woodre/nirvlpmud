inherit "obj/monster";

object gold;

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("grandpa");
	set_alias("simpson");
	set_short("Grandpa Simpson");
	set_long(format("This is Abraham Simpson, father of "+	
			"Homer J. Simpson.  He lives here at"+
			" the Springfield retirement castle "+
			"in his old age.  He seems like a ni"+
			"ce guy.\n",75));
	set_level(10);
	set_wc(15);
	set_hp(200);
	set_ac(8);
	set_al(100);
	set_chat_chance(10);
	load_chat("Grandpa Simpson falls asleep\n");
	load_chat("Grandpa says: Where are my pills???\n");
	load_chat("Grandpa says: My dentures!!!!!\n");
	gold = clone_object("obj/money");
	gold->set_money(500);
	move_object(gold, this_object());
}
