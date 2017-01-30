#include "ansi.h"
inherit "obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	
	set_name("kandy");
	set_alt_name("king");
	set_short("King Kandy");
	set_race("human");
	set_long(
"The Imperial Head Bonbon and Grand Jujube of Candyland.  King\n"+
"Kandy rules Candy Land with a smile on his face and a twinkle\n"+
"in his eye.  King Kandy wears a suit made of candy and carries\n"+
"a giant candy staff.\n");
	set_level(10);
	set_ac(8);
	set_wc(14);
	set_hp(150);
	set_al(642);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("King Kandy exclaims 'Thank you for finding me!'\n");
	load_chat("King Kandy shouts 'Candy Land will once again be great!\n");
	load_a_chat("King Kandy pelts you with assorted candies.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("King Kandy jabs you in the ear with his staff.\n");
	set_spell_mess2("King Kandy throws you into the candy coated wall.\n");
	move_object(clone_object("/players/martha/area/weps/suit.c"), this_object());
	init_command("wear armor");
	move_object(clone_object("/players/martha/area/weps/staff.c"), this_object());
	init_command("wield weapon");
	
	gold = clone_object("obj/money");
	gold->set_money(400);
	move_object(gold,this_object());
}
