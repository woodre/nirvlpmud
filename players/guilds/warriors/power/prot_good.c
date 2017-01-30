/* Protection from Evil */

#include "/players/guilds/warriors/sdefine.h"

main(object gob, object player, int damage, object enemy)
{
	int i;
	int all;
	int aln;
	int aln2;
	int bonus;
	
	if(!ATT) return;
	if(GOB->query_end() < 3) return;
	if(enemy->query_alignment() < 41) return;
	if(!GOB->check_align("good")) return;	
	switch(enemy->query_alignment()){
		case 800..100000: bonus = 3; break;
		case 500..799:    bonus = 2; break;
		case 200..499:    bonus = 1; break;
		case 40..199:     bonus = 0; break;
		default:          bonus = 1; break;
	}
	
	
	tell_object(USER,
	HIW+"Your aura of protection "+HIY+"flashes"+NORM+HIW+"!"+NORM+"\n");
	if(!enemy->query_npc()){
		tell_object(enemy,
			HIW+"You fall back in pain as you attack "+USERN+"!\n"+
		USERN+"'s aura "+HIY+"Burns"+HIW+" your flesh!\n"+NORM);
		enemy->add_hit_point(-(random(GOB->get_skills(90)) + bonus));
	}
	else{
		enemy->heal_self(-(random(GOB->get_skills(90)) + bonus));
	}
	GOB->add_end(-3);
}
