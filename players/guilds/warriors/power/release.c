#include "/players/guilds/warriors/sdefine.h"

main(string str, object gob, object player)
{
	object corpse;
	int cvalue;
	string extra;
	
	if(USER->query_ghost()) return 0;
	
   corpse = present("corpse", environment(USER));
   	
	if (!corpse) {
		tell_object(USER,"There is no corpse.\n");
		return 1;
	}
	
	if(corpse->query_corpse_level() < 1){
		tell_object(USER,"You cannot absorb that, it is useless.\n");
		return 1;
	}
	
	if (sscanf(file_name(corpse),"obj/corpse%s",extra)!=1) return 1;
	if(GOB->query_chosen_align() == "good"){
	tell_room(environment(USER),
		HIW+USER->query_name()+" places "+USER->POS+" hand on the body...\n"+
	   "The soul of the fallen erupts from the corpse and flies into the heavens!\n", ({USER}));
	tell_room(environment(USER),
		"The corpse disappears into a soft mist."+NORM+"\n", ({USER}));
	 tell_object(USER,
    HIW+"You place your palm on the body...\n"+
    "Calling forth the power of the heavens, you release the soul within.\n"+
    "It flies from the body, through you, and into the sky. \nYou are healed.\n"+NORM);
    }
   else{
   tell_room(environment(USER),
		HIW+USER->query_name()+" places "+USER->POS+" hand on the body...\n"+
	   "The soul of the fallen erupts from the corpse and into "+USERN+"!\n", ({USER}));
	 tell_object(USER,
    HIW+"You place your palm on the body...\n"+
    "Calling forth the dark powers, you tear the soul from its body.\n"+
    "It flies from the body and into your eyes filling you with energy!\n"+NORM);
    }
	cvalue = corpse->query_corpse_level() * 2;
   USER->add_hit_point(cvalue);
	destruct(corpse);
	return 1;
}
