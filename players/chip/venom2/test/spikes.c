
#include "/players/maledicta/venom2/sdefine.h"

main(string str, object gob, object player)
{
	object target, comp;
   object pob;
	int spamount;
	int cost;
	object uncon_mob;
	
	if(USER->query_ghost()) return 0;
	if(CRE < 4) return 0;

	cost = 30;
	if(cost > USER->query_sp() || GOB->query_mp() < 10){
		tell_object(USER,
		"You are too low on energy for an attack of that sort.\n");
		return 1;
	}
	if(GOB->query_spikes()){
      tell_object(USER,
      "You already have your spikes extended!\n");
      return 1;
      }
   tell_room(environment(USER),
   HIW+"<>"+COLOR+"<>"+HIW+"<>"+NORM+" Spikes emerge from"+
   " "+USER->query_name()+"'s body!\n");
   GOB->extend_spikes(GOB->query_glvl() + random(GOB->query_glvl()));
	USER->add_spell_point(-cost);
   GOB->add_mp(-10);
   return 1;
	}

