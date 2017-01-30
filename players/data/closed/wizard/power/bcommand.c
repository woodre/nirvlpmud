

#include "/players/maledicta/closed/w/sdefine.h"

main(string str, object gob, object player)
{
	int i;
	object bonbon;
	object woo;
	object pobj;
	string pname;
	
	if(USER->query_ghost()) return 1;
	if(GOB->query_bcommand_delay()){
		tell_object(USER, "You cannot command again so soon!\n");
		return 1;
	}
   if(GOB->query_end() < 10){ 
      tell_object(USER, "Your endurance is too low.\n");
      return 1;
      }

	if(USER->query_sp() < 30){
		tell_object(USER,
		"You are too weak to give commands!\n");
		return 1;
	}
	pobj = present("party_object", USER);
	if(!pobj){
		tell_object(USER, "You are not in a party!\n");
		return 1;
	}
	if(!ATT){
		tell_object(USER, "It is hard to give a Battle Command when not in battle!\n");
		return 1;
	}
	
	GOB->set_bcommand_delay(10 + random(4));
	pname = pobj->QPartyName();
	tell_object(USER,
		HIW+"[ "+NORM+BOLD+"Battle Command"+HIW+" ]"+NORM+"\n"+
	HIW+"You issue Battle Commands to all those present!\n"+NORM);
	
	woo = users();
	
	for(i = 0; i < sizeof(woo); i++){
     if(woo[i] != USER){
		if(environment(woo[i])){
			if(environment(woo[i]) == environment(USER)){
				if(present("party_object", woo[i])){
					if(present("party_object", woo[i])->QPartyName() == pname){
						if(!present("knight_command_bonus", woo[i])){
							bonbon = clone_object("/players/maledicta/closed/w/OBJ/cbonus.c");
							bonbon->set_power(GOB->query_skills(104), USERRN);
							move_object(bonbon, woo[i]);
                     bonbon->start();
							tell_object(woo[i], USERN+" issues battle orders to you!\n");
						}
					}
				}
			 }
        }
		}
	}
   GOB->add_end(-10);
	USER->add_spell_point(-30);
	return 1;
}

