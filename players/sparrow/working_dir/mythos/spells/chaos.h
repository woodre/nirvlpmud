#include "/players/mythos/closed/guild/def.h"
chaos() {
object fool;
int m, rnd;
write("this spell is disabled. -Bp\n");
return 1;
if(qtf < 12) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 70) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 400) { write("The darkness calls for a sacrifice.\n"); return 1;}
tp->add_spell_point(-70);
pp->add_sacrifice(-400);
write("You pour all the hate, the violence, the fear, \n"+
      "the pain, all that you have experenced into this spell!\n"+
      "And from it you bring forth "+HIR+"CHAOS!\n"+NORM);
say(capitalize(tpn)+" suddenly screams!  Hate and rage echo through the room!\n\n"+
    "And you know that "+HIR+"CHAOS"+NORM+" has begun its rule!\n\n");
	fool=all_inventory(environment(this_player()));
	for(m=0;m<sizeof(fool);m++) {
		if(living(fool[m]) && fool[m]->query_ghost() !=1 &&
		(fool[m]->query_npc() || dpp) && !call_other(fool[m],"id","messenger") &&
		(fool[m] != tp) ){
		rnd = random(sizeof(fool));
		if(living(fool[rnd]) && !(fool[rnd]->query_ghost()) && 
		   fool[m] != fool[rnd] && !call_other(fool[rnd],"id","messenger")) {
			fool[m]->attack_object(fool[rnd]);
			tell_object(fool[m],capitalize(tpn)+
	    " calls the rage and violence from within you!\n"+
			HIR+"\t   Chaos Erupts!\n"+NORM); }
	    else { m = m - 1; }
		}
		}
	return 1;}
