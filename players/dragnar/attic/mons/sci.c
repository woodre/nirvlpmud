/*
	Changelog:
	Bal 1996-03-15:
	+ moved inherit to top of file
*/

inherit "obj/monster";

short () { return 0; }

reset(arg){
	object gold, book, card;
	::reset(arg);
	if (arg) return;
	set_name("man");
	set_race("man");
	set_alias("scientist");
	set_long(
"This is a scientist that is hiding from you in the darkness.\n"+
"He seems to be very weary of what you want from him.\n");
	set_level(20);
	set_hp(random(200)+400);
	set_al(200);
	set_wc(30);
	set_ac(17);
	set_chance(20);
	set_spell_dam(50);
	set_spell_mess1("The scientist screams in rage.\n");
	set_spell_mess2("Scientist screams in rage at you!\n");
	set_a_chat_chance(25);
	set_chat_chance(5);
	load_chat("You hear something move in the darkness.\n");
	load_a_chat("Scientist says: It was my fault I could have stopped the destruction!\n");
	load_a_chat("Scientist says: Kill me chosen one, I no longer deserve to live.\n");
    card=clone_object("/players/dragnar/items/quest/card.c");
	move_object(card, this_object());
	gold = clone_object("obj/money");
	gold->set_money(random(2000)+1000);
	move_object(gold,this_object());
}
