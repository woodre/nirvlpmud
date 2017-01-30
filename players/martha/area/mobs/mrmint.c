#include "ansi.h"
inherit "obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	
	set_name("mint");
	set_alt_name("monster");
	set_short("Mr. Mint");
	set_race("candyman");
	set_long(
"The peppermint lumberjack and Keeper of the Royal Peppermint Forest\n"+
"is rather sad as of late.  Mr. Mint likes to cut down the peppermint\n"+
"trees and create sweet-sounding instruments with them.  He awaits the\n"+
"return of the King so his music will not sound so off key.\n");
	set_level(7);
	set_ac(6);
	set_wc(11);
	set_hp(105);
	set_al(35);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("Mr. Mint says 'My peppermint piccolo has been rather off key since the King left.'\n");
	load_chat("Mr. Mint whines 'I hope the King returns soon.'\n");
	load_a_chat("Mr. Mint rams his piccolo up your wazoo!\n");
	load_a_chat("Mr. Mint plays an off tune song that hurts your ears.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("Mr. Mint beats you with his candy flute.\n");
	set_spell_mess2("Mr. Mint jams you in the eye with his piccolo.\n");
	move_object(clone_object("/players/martha/area/weps/axe.c"), this_object());
	init_command("wield weapon");
	move_object(clone_object("players/martha/area/weps/piccolo.c"), this_object());
	
	gold = clone_object("obj/money");
	gold->set_money(62);
	move_object(gold,this_object());
}