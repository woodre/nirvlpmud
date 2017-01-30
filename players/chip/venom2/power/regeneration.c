/*  Level 6 Control Spell: Regen - Sps to Hps at a loss.  Cost is 10 sps and 1 mp to
start.  Takes 1 sp to heal 1 hp after that. Toggleable. Chance of happening each
round is based on how many tentacles you put into it. 1 tentacle = 10%.  Of course
this means taking them away from attacking or defending.  */

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	int woot;
	
	if(USER->query_ghost()) return 0;
	if(CON < 6) return 0;
	if(GOB->query_regen()){
		tell_object(USER,
		"You call the "+HIK+"Dark Matter"+NORM+" to stop regenerating your body.\n");
		GOB->set_regen(0);
		return 1;
	}
	
	if(USER->query_sp() < 10 || GOB->query_mp() < 1){
		tell_object(USER,
		"Your symbiotic link is too weak for that.\n");
		return 1;
	}
	
	tell_object(USER,
	COLOR+"-- --"+NORM+" You concentrate and call "+HIK+"Dark Matter"+NORM+" to seal your wounds.\n");
	GOB->set_regen(1);
	USER->add_spell_point(-10);
	GOB->add_mp(-1);
	return 1;
}
