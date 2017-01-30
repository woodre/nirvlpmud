inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("billings");
	set_alt_name("brandy");
	set_race("human");
	set_alias("secretary");
	set_short(HIW+"Mrs. Billings, Guidance Office Secretary"+NORM);
	set_long("\
	This is Brandy Billings. She is a tall, heavier\n\
	set, middle-aged woman. She has shoulder length,\n\
	dark brown hair with blonde highlights and a very\n\
	beautiful smile. She has some wrinkles starting \n\
	to appear on her face but that does not take away\n\
	from her breath taking body.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_heal(25, 1);
	set_dead_ob(this_object());
	set_al(-7000);
}

monster_died()
{
	object attacker;
	
	attacker = this_object()->query_attack();
	
	if(!attacker)
	{
		return;
	}
	
	attacker->hit_player(25 + random(11));
	tell_object(attacker, HIR+"		Mrs. Billings lunges at you in a final attempt to kill you!\n"+NORM);
}