/*
Level 4 Combat Spell: KO - Knocks a mob unconscious at 0/10, placing its variables
into an object. No exp gained.
*/

#include "/players/chip/venom2/sdefine.h"

main(string str, object gob, object player)
{
	object target, comp;
   object pob;
	int spamount;
	int cost;
	object uncon_mob;
	
	if(USER->query_ghost()) return 0;
	if(COM < 4) return 0;
	if(!USER->query_attack()){
		tell_object(USER,
		COLOR+"You can only do this in combat!"+NORM+"\n");
		return 1;
	}
	target = USER->query_attack();
	if(!target->query_npc()){
		tell_object(USER,
		"You cannot do this to players!\n");
		return 1;
	}
	cost = target->query_hp()/3;
	if(cost > USER->query_sp()){
		tell_object(USER,
		"You are too low on energy for an attack of that sort.\n");
		return 1;
	}
	if(target->webbed() || target->confused()){
		tell_object(USER,
		"Something is keeping you from being able to knock it unconscious.\n");
		return 1;
	}
	if(USER->query_attack() && ATT->query_hp() < 90){
		if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1){
			target->stop_con_shadow();  /* In case it is webbed */
                  uncon_mob = clone_object("/players/chip/venom2/OBJ/uncon_mob.c");
                  uncon_mob->store_gender(target->query_gender());
			uncon_mob->store_name(target->query_name());
			uncon_mob->store_level(target->query_level());
		   uncon_mob->store_short(target->short());
			uncon_mob->store_spell_dam(target->query_spell_dam());
			uncon_mob->store_spell_chance(target->query_spell_chance());
			uncon_mob->store_heal_rate(target->query_heal_rate());
			uncon_mob->store_heal_intv(target->query_heal_intv());
			uncon_mob->store_mhp(target->query_mhp());
			uncon_mob->store_ac(target->query_ac());
			uncon_mob->store_wc(target->query_wc());
			move_object(uncon_mob, environment(USER));
			target->transfer_all_to(environment(target));
if(pob = present("party object", USER)){
         pob->share_exp(target->calculate_worth());
         }
         else{
			USER->add_exp(target->calculate_worth());
         }
			tell_object(USER,
				"You reach out and wrap tentacles around the neck of "+target->query_name()+"...\n"+
			"Other tentacles lash out and knock them unconscious,\n"+
         "leaving them lying on the ground.\n");
			tell_room(environment(USER),
				USER->query_name()+" reaches out with tentacles of "+HIK+"Dark Matter"+NORM+"...\n"+
			target->query_name()+" is strangled to the ground and left lying unconscious.\n", ({ USER }));
			USER->add_spell_point(-cost);
         target->second_life();
			destruct(target);
         return 1;
		}
		tell_object(USER, "Your opponent is still too strong.\n");
		return 1;
	}
	tell_object(USER, "Your opponent is still too strong.\n");
	return 1;
}

