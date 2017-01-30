inherit "obj/monster";
#include "ex.h"
reset(arg){
	object weapon,gold,armor;
	::reset(arg);
	if(arg) return;
	set_name("professor");
	set_race("human");
	set_short("Professor");
	set_long("\n"+
	"	This is one of the many professors you will find at\n"+
	"Grey University.  They all seem to look the same...\n");
	set_level(17);
	set_hp(425);
	set_wc(24);
	set_ac(14);
	set_al(0);
	set_chat_chance(3);
	load_chat("Professor looks at you with contempt.\n");
	load_chat("Professor says: There are ways to get an A *wink* *wink*.\n");
	gold=clone_object("obj/money");
	gold->set_money(random(1000));
	move_object(gold,TOB);
}
