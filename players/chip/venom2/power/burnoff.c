/*  Level 3 Control Spell: Burnoff - Removes intox, stuff, and soaked over time.
Toggleable - 15 sps to start, 5 mp.  This requires a tentacle in order to
function, 1 tenticle = 8% chance per round, and depending on how many
you put into it, this takes away from attack and defense. */

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	object ob;
	int bonus;
	
	if(USER->query_ghost()) return 0;
	if(CON < 3) return 0;
	
	if(GOB->query_burnoff()){
		tell_object(USER, "Stopping the burnoff process...\n");
		GOB->set_burnoff(0);
		return 1;
	}
	if(USER->query_sp() < 15 || GOB->query_mp() < 5){
		tell_object(USER,
		"Your symbiotic link is too weak for that.\n");
		return 1;
	}
	if(USER->query_hp() < 50){
		tell_object(USER, "Your body is too weak to begin this process.\n");
		return 1;
	}
	GOB->set_burnoff(1);
	USER->add_spell_point(-15);
	GOB->add_mp(-5);
	tell_object(USER,
	COLOR+"You concentrate and force "+GOB->query_venom_name()+" to burnoff the toxins in your body"+NORM+".\n");
	return 1;
}

