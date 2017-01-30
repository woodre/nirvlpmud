/*  This is called each round from the main heart_beat() */

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{
int hideskill;
hideskill = GOB->get_skill(113);

if(!hideskill || hideskill == 1) return;

	if(hideskill == 2){
		if(USER->query_invis() && 
			GOB->query_end() > 3 &&
			!random(4)) 
			GOB->add_end(-3);
		if(USER->query_invis() && 
			GOB->query_end() < 3){
				tell_object(USER, 
					"You become too tired to continue hiding..."+NORM+"\n\n");
				USER->visible();
			}
	}
	else if(hideskill == 3){
		if(USER->query_invis()) USER->set_invs_sp();
	}


}
