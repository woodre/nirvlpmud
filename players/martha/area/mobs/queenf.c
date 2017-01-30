#include "ansi.h"
inherit "/obj/monster";

reset(arg) {
	object gold;
	::reset (arg);
	if(arg) return;
	
	set_name("queen");
	set_alt_name("frostine");
	set_short("Queen Frostine");
	set_race("human");
	set_long(
"Queen Frostine sails on the Ice Cream Sea in an Ice Cream Float.\n"+
"A large sparkling crown on her head and a beautiful magic wand\n"+
"in her hand.  Queen Frostine feels the King will be found very\n"+
"soon.  She is prepared to make Candy Land sparkle once more when\n"+
"that time comes.\n");
	set_level(10);
	set_ac(8);
	set_wc(14);
	set_hp(150);
	set_al(642);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("Queen Frostine says 'Utter nonsense, Lord Licorice is a fool!\n");
	load_chat("Queen Frostine says 'Candy Land will sparkle again!'\n");
	load_a_chat("Queen Frostine bonks you on the head with her wand.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("Queen Frostine dips your head in the Ice Cream Sea.\n");
	set_spell_mess2("Queen Frostine points her wand your way and freezes you!\n");
	move_object(clone_object("/players/martha/area/weps/wand.c"), this_object());
	init_command("wield weapon");
	move_object(clone_object("/players/martha/area/weps/iccrown.c"), this_object());
	init_command("wear armor");
	
	gold = clone_object("obj/money");
	gold->set_money(200);
	move_object(gold,this_object());
}
