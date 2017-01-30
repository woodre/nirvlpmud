#include "/players/maledicta/closed/w/sdefine.h"


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


	if(GOB->get_skill(117) && random(100) < GOB->get_skill(117) * 3 && ATT){
		if(GOB->query_end() > 3){
			switch(random(GOB->get_skill(117) * 20) + 1){
		case 95..1000: 
			bonus2 += 5;
			tell_object(USER,
				BOLD+"("+HIR+"C"+NORM+BOLD+")"+
				" You make a precision strike against "+ATT->query_name()+".\n"+NORM); 
            break;
		case 80..94:
			bonus2 += 4;
            tell_object(USER,
				BOLD+"("+RED+"C"+NORM+BOLD+")"+
				" You find an opening in "+ATT->query_name()+"'s defenses.\n"+NORM);
			break;
		case 60..79:
			bonus2 += 3;
			tell_object(USER,
				BOLD+"("+RED+"C"+NORM+BOLD+")"+
				" You slide under "+ATT->query_name()+"'s attack and strike.\n"+NORM);
			break;
		case 30..59:
			bonus2 += 2;
            tell_object(USER,
				BOLD+"("+HIW+"C"+NORM+BOLD+")"+
				" You deliver a precise attack against "+ATT->query_name()+".\n"+NORM);
			break;
		case 1..29:
			bonus2 += 1;
			tell_object(USER,
				BOLD+"(C) You lash out at "+ATT->query_name()+", and manage to hit.\n"+NORM);
			break;
		default:
			bonus2 += 0;
			break;
			}
			GOB->add_end(-3);
		}
	}
	return bonus2;
}