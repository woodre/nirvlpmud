#include "/players/data/closed/wizard/sdefine.h"


main(string str, object gob, object player)
{
	int bonus;
	int bonus2;
	bonus = GOB->query_backstab();
	if(bonus){
		tell_object(USER,
		HIR+"\n\n          <  <<  "+HIW+"B A C K S T A B"+HIR+"  >>  >\n\n"+NORM);
		if(ATT->is_npc()){
			if(ATT->query_hp() > 50)
			ATT->heal_self(-random(GOB->query_backstab() / 4));
		}
		GOB->set_backstab(0);
		return bonus;
	}
}
