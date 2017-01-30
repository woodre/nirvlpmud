inherit "obj/monster";

object gold;

reset(arg) {
	::reset(arg);
	if (arg) 
	   return;
	set_name("homer");
	set_alias("simpson");
	set_short("Homer J. Simpson");
	set_long( format("You are looking at Homer J. Simpson.  The "+
			 "patriarch of the Simpson family.  He works "+
			 "as a safety inspector in Sector 7G of this "+
			 "plant.  He is a simple man, and has simple "+
			 "desires in life.  Be careful though, he has "+
			 "a short temper.\n") );
	set_level(18);
	set_hp(400);
	set_wc(18);
	set_ac(10);
	set_al(500);
	set_chat_chance(8);
	load_chat("Homer says: Mmmmm beer\n");
	load_chat("Homer says: Mmmmm Marge\n");
	load_chat("Homer says: Doh!\n");
	load_chat("Homer says: Why you little!!!!\n");
	gold = clone_object("obj/money");
	gold->set_money(1000);
	move_object(gold,this_object());
}


