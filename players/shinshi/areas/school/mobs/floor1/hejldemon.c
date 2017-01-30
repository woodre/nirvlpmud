inherit "/obj/monster";
int hp, x;

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name(HIK+"A large black demon"+NORM);
	set_alt_name("demon");
	set_race("demon");
	set_short(HIK+"A large black demon"+NORM);
	set_long("\
	This large black demon stands before you\n\
	with large black wings and glowing red\n\
	eyes. The face and body resemble that of\n\
	Mrs. Hejl\'s. The large demon glares darkly\n\
	at you, taunting you.\n");
	x = random(15);
	set_level(23);
	set_hp(800 + random (200));
	set_ac(24 + random (10));
	set_wc(40 + random(10));
	set_al(-7000);
	set_chat_chance(1);
	set_dead_ob(this_object());
	load_chat(query_name()+" snarls loudly, showing its long fangs.\n");
	load_chat(query_name()+" emits a loud growl, making you shrink in fear.\n");
	add_spell("fireball", "#MN# summons a ball of $HR$demonic fire$N$ and hurls it towards you.\n",
		"#MN# hurls a ball of $HR$demonic fire$N$ at #TN#'s head.\n",
	15,250,"other|fire");
}

heart_beat()
{
	::heart_beat();

	if(!environment()) return;
	
	if(!attacker_ob) return;
	
	if(x < 15)
	{
		hp = attacker_ob->query_hp();
		if(hp < 100)
		{

			tell_room(environment(this_object()),
					"\n"+
					"\n"+
					"The demon roars in anger and lounges at "+attacker_ob->query_name()+".\n"+
					"The demon tears its claws into "+attacker_ob->query_name()+"'s chest, rips\n"+
					"out their heart and devours it while it still attempts to pump blood.\n"+
					"\n"+
					"\n");
			attacker_ob->hit_player(200, "other|physical");
			return 1;
		}
		return 1;
	}
}