#include "ansi.h"
inherit "obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	
	set_name("lord");
	set_alt_name("monster");
	set_alt_name("licorice");
	set_short("Lord Licorice");
	set_race("human");
	set_long(
"The evil Lord Licorice has a heart of rock candy.  Always gloomy\n"+
"and grim, Lord Licorice has hidden the King so all of Candy Land\n"+
"will be his and his alone.\n");
	set_level(10);
	set_ac(8);
	set_wc(14);
	set_hp(150);
	set_al(640);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("Lord Licorice cackles and says 'They'll never find the King or his Castle!'\n");
	load_a_chat("Lord Licorice wraps a long black sting of licorice around your neck.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("Lord Licorice whips you with licorice.\n");
	move_object(clone_object("/players/martha/area/weps/cape.c"), this_object());
	init_command("wear armor");
	move_object(clone_object("/players/martha/area/weps/shield.c"), this_object());
	init_command("wear armor");
	
	gold = clone_object("obj/money");
	gold->set_money(150);
	move_object(gold,this_object());
}
