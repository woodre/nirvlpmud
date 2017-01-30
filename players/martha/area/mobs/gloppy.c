#include "ansi.h"
inherit "obj/monster";

reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	
	set_name("gloppy");
	set_alt_name("monster");
	set_short("Gloppy");
	set_race("blob");
	set_long(
"The kindly Molasses Monster, Gloppy oozes around the Molasses\n"+
"Swamp patiently awaiting the Kings return.  Gloppy is more\n"+
"'goosome' than he is gruesome and he loves his molasses.\n");
	set_level(6);
	set_ac(5);
	set_wc(10);
	set_hp(90);
	set_al(40);
	set_aggressive(0);
	set_chat_chance(10);
	set_a_chat_chance(10);
	
	load_chat("Gloppy says 'Molasses for the masses stick to your asses!'\n");
	load_a_chat("Gloppy pours molasses over your head.\n");
	
	set_chance(10);
	set_spell_dam(0);
	
	set_spell_mess1("Gloppy spits molasses in your face.\n");
	move_object(clone_object("/players/martha/area/heals/molasses.c"), this_object());
}
