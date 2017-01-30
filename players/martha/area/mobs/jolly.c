#include "ansi.h"
inherit "/obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	
	set_name("jolly");
	set_alt_name("monster");
	set_short("Jolly");
	set_race("gumdrop");
	set_long(
"The Official Gumdrop Mountain Greeter, Jolly is soft and gooey.\n"+
"He is distressed because the disappearance of the King has made\n"+
"his pastel, sugar crested range look paler as each day goes by.\n");
	set_level(9);
	set_ac(7);
	set_wc(13);
	set_hp(135);
	set_al(150);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("Jolly says 'My mountains just don't glisten and glow the way they used to.'\n");
	load_chat("Jolly says 'The King made life brighter on the mountain.'\n");
	load_a_chat("Jolly squishes your head between two gumdrops.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("Jolly gums your arm.\n");
	move_object(clone_object("/players/martha/area/weps/gloves.c"), this_object());
	init_command("wear armor");
	move_object(clone_object("/players/martha/area/heals/gumdrop.c"), this_object());

	gold = clone_object("obj/money");
	gold->set_money(90);
	move_object(gold,this_object());
}
	