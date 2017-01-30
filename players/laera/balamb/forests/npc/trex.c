#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"
inherit "obj/monster.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

set_name("t-rexaur");
set_alias("creature");
set_race("trex");
set_gender("creature");
set_short(HIW + "T-Rexaur" + OFF);
set_long(
"Large and ferocious, T-Rexaur wanders the forests of Balamb, searching\n" +
"for food.  Carefully he sniffs out his prey, waiting for movement,\n" +
"before swiftly striking with powerful jaws.  It's huge, razor sharp teeth\n" +
"can crush a human in a single bite.\n");

set_level(24 + random(5));
set_hp(1200 + random(225));
set_al(-70);
set_wc(46 + random(14));
set_ac(24 + random(5));
set_heal(4,20);
set_aggressive(1);
set_dead_ob(this_object());
set_wc_bonus(21);
set_chat_chance(3);
load_chat("T-Rexaur roars mightily and sniffs the air.\n");
load_chat("T-Rexaur lifts his head as he hears a noise in the distance.\n");
set_a_chat_chance(8);
load_a_chat(HIW+"T-Rexaur sinks his teeth into your body, leaving deep, gaping wounds!\n"+OFF);

set_chance(25);
set_spell_dam(50 +random(40));
set_spell_mess1(
     HIW + "T-Rexaur bites hard, ripping off a limb!\n" + OFF);
set_spell_mess2(
     HIW + "T-Rexaur bites hard, tearing off a limb!\n" + OFF);
}

heart_beat()
{
     int x; object *inv; int time; int level;
     ::heart_beat();
     if(attacker_ob)
     {
		time = random(100);
		if((time > 59) && (time < 71))
		{
     		inv = all_inventory(environment(this_object()));
        	for(x=0;x<sizeof(inv);x++)
        	{
           		if((inv[x]-> is_player()) && living(inv[x]))
           		{
			   		tell_room(environment(this_object()),
               		HIW + "T-Rexaur turns around, swinging his tail around and " + OFF
               		+ HIR + "SMASHING " + OFF + HIW + inv[x]->query_name() + " to the ground!.\n" + OFF);
               		tell_object(inv[x], HIW + "You are " + OFF +
               		HIR + "SLAMMED " + OFF + HIW + "to the ground by T-Rexaur's tail!\n" + OFF);
               		inv[x]->hit_player(50 + random(60));
           		}
        	}
     	}
     	if((time > 20) && (time < 30))
     	{
			int target;
			inv = all_inventory(environment(this_object()));
			target = random (sizeof(inv));
			if((inv[target]-> is_player()) && (inv[target]-> query_level() > 10) && living(inv[target]))
			{
				tell_room(environment(this_object()),
				HIW + "T-Rexaur picks " + inv[target]->query_name() + " up by the neck and " + OFF + HIR +
				"SHAKES " + OFF + HIW + "hard trying to rip off " + inv[target]->query_possessive() +
				" head.\n" + OFF);
				tell_object(inv[target], HIW + "Your neck " + OFF + HIR + "CRACKS " + OFF + HIW + "as " +
				"T-Rexaur picks you up by the neck and shakes hard!\n" + OFF);
				attack_object(inv[target]);
				inv[target]->hit_player(30 + random(30));
				return 1;
			}
		}
	}
}

monster_died()
{
	move_object(clone_object("/players/laera/balamb/forests/obj/bone.c"),
      environment(this_object()));
   	tell_room(environment(this_object()),
     HIW+"The earth shakes as T-Rexaur roars for the last time and crumples to the ground.\n"+OFF);
   return 0;
}
