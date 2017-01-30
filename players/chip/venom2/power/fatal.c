/*
Level 3 Combat Spell: Fatal - Kills off a mob at 0/10 and less than 50 hps.
Cost: 1/3 remaining opponents hps in hps.
*/

#include "/players/chip/venom2/sdefine.h"

main(string str, object gob, object player)
{
	object target, comp;
	int spamount;
	int cost;
	
	if(USER->query_ghost()) return 0;
	if(COM < 3) return 0;
	if(!USER->query_attack()){
		tell_object(USER,
		COLOR+"You can only do this in combat!"+NORM+"\n");
		return 1;
	}
	target = USER->query_attack();
	if(!target->query_npc() || !living(target)){
		tell_object(USER,
		"You cannot do this to players!\n");
		return 1;
	}
	cost = target->query_hp()/3;
	if(cost > USER->query_hp()){
		tell_object(USER,
		"You are too weak.\n");
		return 1;
	}
	
	if(USER->query_attack() && ATT->query_hp() < 50){
		if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1){
			
			switch(random(3) + 1){
				case 3:
				tell_room(environment(USER),
					BOLD+ "<"+NORM+COLOR+"crush"+NORM+BOLD+">  "+NORM+USER->query_name()+" reaches out with "+USER->POS+" open hand.\n"+
				"        "+HIK+"Dark Matter"+NORM+" forms and lashes out, wrapping around "+ATTN+".\n");
				tell_room(environment(USER),
			   "        "+ATTN+" is quickly crushed to death and sent to the ground\n"+
				"        in a lifeless lump of flesh.\n");
				break;
				case 2:
				tell_room(environment(USER),
					BOLD+"<"+NORM+COLOR+"eviscerate"+NORM+BOLD+"> "+NORM+USER->query_name()+" holds out "+USER->POS+" hand.\n"+
				"             A horde of tentacles lash out towards "+ATTN+".\n");
				tell_room(environment(USER),
				"             "+ATTN+"'s bowels spill out onto the ground as\n"+
            "             they fall to the ground lifeless.\n");
				break;
				case 1:
				tell_room(environment(USER),
					BOLD+ "<"+NORM+COLOR+"behead"+NORM+BOLD+">  "+NORM+USER->query_name()+" swings "+USER->POS+" arm.\n"+
				"          A giant scythe forms from "+HIK+"Dark Matter"+NORM+".\n");
				tell_room(environment(USER),
				"          "+ATTN+"'s head rolls to the ground as the body tumbles over lifeless.\n");
				break;
			}
			USER->add_hit_point(-cost);
			target->heal_self(-(target->query_hp()));
			target->hit_player(COM * 20);
			return 1;
		}
		tell_object(USER, "Your opponent is still too strong.\n");
		return 1;
	}
	tell_object(USER, "Your opponent is still too strong.\n");
	return 1;
}

