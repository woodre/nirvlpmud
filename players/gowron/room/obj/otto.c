inherit "obj/monster";

reset(arg) {
	object gold;
	if (arg) return;
	::reset(arg);
	set_name("Otto");
	set_alias("otto");
	set_short("Otto, the bus driver");
	set_long(format("Otto the bus driver looks no older than 20.  He is "+
		 	"pretty dazed.  You wouldn't want to go anywhere with "+
		 	"him driving.\n", 75));
	set_al(100);
	set_wc(15);
	set_level(16);
	set_hp(350);
	gold = clone_object("obj/money");
	gold->set_money(500+random(550));
	move_object(gold, this_object());
	move_object(clone_object("players/gowron/room/obj/headphone"), this_object());
	init_command("wear headphones");
	set_ac(random(12));
}
