inherit "obj/monster";

object gold;

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("Milhouse");
	set_alias("milhouse");
	set_short("Milhouse");
	set_long(format("This is Milhouse.  The best friend of Bart Simpson."+
		 	" He wears glasses and is kind of "+
			"accident prone.\n",75));
	set_level(10);
	set_al(100);
	set_wc(13);
	set_ac(5);
	set_hp(170+random(50));
	gold = clone_object("obj/money");
	gold->set_money(400+random(200));
	move_object(gold,this_object());
}
