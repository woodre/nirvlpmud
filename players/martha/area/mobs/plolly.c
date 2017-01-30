#include "ansi.h"
inherit "/obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	
	set_name("lolly");
	set_alt_name("princess");
	set_alt_name("monster");
	set_short("Princess Lolly");
	set_race("human");
	set_long(
"Beautiful, glowing Princess Lolly of the Lollipop Woods is the\n"+
"daughter of King Kandy.  She is sad that her father is missing,\n"+
"but she knows someone will find him safe and sound.  She knows\n"+
"that soon Candy Land will be free from the evil Lord Licorice.\n");
	set_level(9);
	set_ac(7);
	set_wc(13);
	set_hp(135);
	set_al(642);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("Princess Lolly says 'Please find my father!'\n");
	load_chat("Princess Lolly wonders if you'd like to lick her lollipop?\n");
	load_a_chat("Princess Lolly sticks her lollipop in your hair.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("Princess Lolly jabs you in the eye with her lollipop.\n");
	set_spell_mess2("Princess Lolly headbutts you with her pointy crown.\n");
	move_object(clone_object("/players/martha/area/weps/crown.c"), this_object());
	init_command("wear armor");
	
	gold = clone_object("obj/money");
	gold->set_money(100);
	move_object(gold,this_object());
}
