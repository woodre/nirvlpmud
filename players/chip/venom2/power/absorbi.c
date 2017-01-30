/*  Level 2 Control Spell: Absorb Item - Gives mp by items weight
(maxes at Control skill level)  */

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	object ob;
	int bonus;
	
	if(USER->query_ghost()) return 0;
	if(CON < 2) return 0;
	if(!str){ tell_object(USER, "Absorb which item?\n"); return 1; }
	ob = present(str, environment(USER));
	
	if(!ob){ tell_object(USER, "You do not see that here.\n"); return 1; }
	
	if(!ob->get() || ob->query_weight() > 15 || ob->query_value() < 1 || living(ob)){
		tell_object(USER, "You cannot absorb that.\n");
		return 1;
	}
	bonus = ob->query_weight();
	if(bonus > CON) bonus = CON;
	GOB->add_mp(bonus + 2); /* added the + 2 to the mp gain from items, as it was very low and the MP pool is quite large for bigger neos -Chip(4-17-09)*/
	tell_object(USER,
		COLOR+"< > "+NORM+"You lean over the "+str+" and place your hand over it...\n"+
	"    Tentacles lash out and absorb it, leaving no trace of the "+str+".\n");
	destruct(ob);
	return 1;
}


