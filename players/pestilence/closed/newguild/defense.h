venom_defense(){
	int def;
	def = random(USER->query_attrib("ste") * 5);
	defense_bonus = 0;
	if(!attack) return 0;
	if(def > 85){
		tell_object(USER,
			"<"+HIB+"defend"+NORM+"> Tentacles lash out from you.\n"+
			"         "+attack->query_name()+" fights for control of "+attack->POS+" weapon.\n"+
		"         "+attack->query_name()+" is slowly over powered.\n");
		tell_room(environment(USER),
			"Tentacles lash out from "+capitalize(symb_name)+".\n"+
			""+attack->query_name()+" fights for control of "+attack->POS+" weapon.\n"+
		""+attack->query_name()+" is slowly over powered.\n", ({USER}));
		defense_bonus = 14;
	}
	else if(def > 64){
		tell_object(USER,
			"<"+HIB+"defend"+NORM+"> You headbutt the oncoming attack.\n"+
			"         You then screech in ecstasy.\n"+
		"         "+attack->query_name()+" cringes.\n");
		tell_room(environment(USER),
			capitalize(symb_name)+" headbutts the on coming attack.\n"+
			capitalize(symb_name)+" screeches in ecstasy.\n"+
		""+attack->query_name()+" cringes.\n", ({USER}));
		defense_bonus = 4;
		
	}
	else if(def > 55){
		tell_object(USER,
		"<"+HIB+"defend"+NORM+"> You smack the attack aside.\n");
		tell_room(environment(USER),
		capitalize(symb_name)+" smacks the attack aside.\n", ({USER}));
		defense_bonus = 3;
		
	}
	else if(def > 35){
		tell_object(USER,
		"<"+HIB+"defend"+NORM+"> You tense up absorbing most of the impact.\n");
		tell_room(environment(USER),
		capitalize(symb_name)+" tenses up absorbing most of the impact.\n", ({USER}));
		defense_bonus = 2;
		
	}
	else if(def > 5){
		tell_object(USER,
		"<"+HIB+"defend"+NORM+"> You leap aside.\n");
		tell_room(environment(USER),
		capitalize(symb_name)+" leaps aside.\n", ({USER}));
		defense_bonus = 1;
	}
	return defense_bonus;
}
