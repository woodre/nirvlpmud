#include "ansi.h"
inherit "obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	
	set_name("gramma");
	set_alt_name("monster");
	set_alt_name("nut");
	set_short("Gramma Nut");
	set_race("human");
	set_long(
"Warm and loving Gramma Nut is ever hopeful that someone will be able\n"+
"to find the King.  She is a plump, older woman who loves to keep the\n"+
"children of Candy Land happy and full.\n");
	set_level(7);
	set_ac(6);
	set_wc(11);
	set_hp(105);
	set_al(641);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("Gramma Nut says 'Oh, do cheer up!'\n");
	load_a_chat("Gramma Nut pelts you with peanuts.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("Gramma sticks a nut up your nose.\n");
	set_spell_mess2("Gramma Nut leaves a granny shoe print on your face.\n");
	move_object(clone_object("/players/martha/area/weps/shoes.c"), this_object());
	init_command("wear armor");
	move_object(clone_object("/players/martha/area/heals/peanutbrittle.c"), this_object());
	
	gold = clone_object("obj/money");
	gold->set_money(75);
	move_object(gold,this_object());
}

	
	