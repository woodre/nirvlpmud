inherit "obj/monster";

object gold,shot;

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("Bart");
	set_alias("bart");
	set_short("Bart Simpson");
	set_long(format("Bart Simpson, Springfield's resident troublemaker.  "+
			"He is an underachiever and proud of it.  He has many friends "+
			"but he has enemies as well.\n",75));
	set_level(9);
	set_hp(150+random(50));
	set_ac(6);
	set_al(-30);
	set_chat_chance(10);
	load_chat("Bart asks: I'm Bart Simpson, who the hell are you?\n");
	load_chat("Bart thinks of a devious prank call to Moe.\n");
	gold = clone_object("obj/money");
	gold->set_money(random(250));
	move_object(gold,this_object());
	shot = clone_object("/players/gowron/room/obj/slingshot.c");
	move_object(shot, this_object());
	init_command("wield slingshot");
	set_wc(10+random(6));
}
