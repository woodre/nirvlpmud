#include "/players/guilds/warriors/sdefine.h"

main(object gob, object player, int damage, object enemy)
{
	int totdam;
    int doback;
    string mess;
	string mess2;
	if(!ATT) return;
	if(!damage) return;
	if(!USER->query_pl_k()){
		 return;
	}
	if(!GOB->query_riposte()) return;
	if(random(100) > GOB->get_skill(114) * 3) return;
	if(GOB->query_end() < 8) return;
    
totdam = damage/8;
/*
switch(totdam){
	case 50..100000000: doback = random(6) + 3; break;
	case 40..49:        doback = random(4) + 2; break;
	case 25..39:        doback = random(3) + 1; break;
	case 15..24:        doback = random(2) + 1; break;
	default:            doback = 0;             break;
}
*/
totdam = random(totdam) + 1;
if(totdam > 6) totdam = 6;
doback = totdam;

if(!doback) return;
switch(doback){
	case 7..8:    
		mess  = HIR+"Devastate"+NORM; 
		mess2 = HIR+"Devastated"+NORM; 
		break;
	case 5..6:    
		mess  = RED+"Massacre"+NORM;  
		mess2 = RED+"Massacred"+NORM;
		break;
	case 2..4:    
		mess = HIW+"Hit";                
		mess2 = HIW+"Hit";
		break;
	case 1:       
		mess = HIW+"Graze";
		mess2 = HIW+"Grazed";
		break;
	default:      
		mess = HIW+"graze";  
		mess2 = HIW+"Grazed";
		break;
}

if(!enemy->query_npc()){
		tell_object(enemy,
		HIW+"You are "+NORM+mess2+HIW+" by "+USERN+"'s riposte attack.\n"+NORM);
		tell_object(USER,
		HIW+"["+HIR+"Riposte"+HIW+"] "+
		"You "+NORM+mess+HIW+" "+enemy->query_name()+" with a riposte attack!\n"+NORM);
		enemy->add_hit_point(-doback);
	}
	else{
		tell_object(USER,
		HIW+"["+HIR+"Riposte"+HIW+"] "+
		"You "+NORM+mess+HIW+" "+enemy->query_name()+" with a riposte attack!\n"+NORM);
		enemy->heal_self(-doback);
	}
	GOB->add_end(-8);
}