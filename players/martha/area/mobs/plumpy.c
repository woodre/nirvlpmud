#include "ansi.h"
inherit "/obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	
	set_name("plumpy");
	set_alt_name("monster");
	set_short("Plumpy");
	set_race("troll");
	set_long(
"Plumpy, the last of the Plumpa Trolls, is the caretaker of the\n"+
"Gingerbread Plum Trees.  His job is to make sure the plums that\n"+
"fall from the trees are gathered quickly so they do not spoil.\n"+
"Plumpy looks as if he was at one time a jolly old troll. However,\n"+
"recent events involving the King have left him glum.  The more\n"+
"glum he gets, the more plums he eats.\n");
	set_level(5);
	set_ac(5);
	set_wc(9);
	set_hp(75);
	set_al(35);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("Plumpy says 'A lost King is so distressing.'\n");
	load_chat("Plumpy squeals 'These plums are quite tasty!'\n");
	load_a_chat("Plumpy gnaws on your cheek, biting it like a plum.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("Plumpy chews on your arm.\n");
	set_spell_mess2("Plumpy smashes a rotten plum on your head.\n");
	move_object(clone_object("/players/martha/area/weps/necklace.c"), this_object());
	init_command("wear armor");
	move_object(clone_object("/players/martha/area/heals/plum.c"), this_object());
	
	gold = clone_object("obj/money");
	gold->set_money(50);
	move_object(gold,this_object());
}
 