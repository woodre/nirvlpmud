inherit "obj/monster";

object gold;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("krusty");
	set_alias("clown");
	set_short("Krusty the Clown");
	set_long(format("This Krusty the clown.  Although he can't read, and he "+
		 "drinks a lot, he is still revered as a great entertainer. "+
		 "He looks like he is on his way to do his show "+
		 "right now.\n",75 ));
	set_level(15);
	set_wc(15);
	set_hp(300+random(69));
	set_ac(10);
	set_al(2);
	gold = clone_object("obj/money");
	gold->set_money(random(800));
	move_object(gold, this_object());
}
