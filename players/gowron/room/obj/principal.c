inherit "obj/monster";

object gold;

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("skinner");
	set_alias("principal");
	set_short("Principal Skinner");
	set_long(format("Principal Seymour Skinner of Spri"+
			"ngfield El.  He always harasses Bart "+
			"and sends him to detention.\n",75));
	set_level(18);
	set_wc(19);
	set_ac(14);
	set_hp(400+random(100));
	set_al(666);
	gold = clone_object("obj/money");
	gold->set_money(800+random(1000));
	move_object(gold,this_object());
}
