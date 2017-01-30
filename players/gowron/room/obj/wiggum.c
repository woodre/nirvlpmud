/* Changed ac from 12 to 16, wc from 25 to 30. -Snow */

inherit "obj/monster";

object gold,donut;

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("wiggum");
	set_alias("chief");
	set_short("Police Chief Wiggum");
	set_long(format("Police Chief Wiggum is a very "+
			"fat guy.  He is not exactly your "+
			"boy scout cop either.  Kind of cor"+
			"rupt, really.\n",75));
	set_level(20);
	set_wc(30);
	set_ac(16);
	set_hp(550+random(80));
	set_al(-200);
	gold = clone_object("obj/money");
	gold->set_money(random(190));
	move_object(gold, this_object());
	donut = clone_object("players/gowron/room/obj/donut");
	move_object(donut,this_object());
}
