int monk;

/******************** Monk Schtuff ***************/
static int meditate;
int touch;

/* Disciplines */
int blood;
int time;
int mind;

query_monk(){ return monk; }
set_monk(int i){ monk = i; }

query_meditate(){ return meditate; }
set_meditate(int i){ meditate = i; }


query_blood(){ return blood; }
set_blood(int i){ blood = i; }
query_mind(){ return mind; }
set_mind(int i){ mind = i; }



catch_all(str){
	if(meditate > 0 && str != "meditate"){ write("You are meditating.\n"); return 1; }
	else return;
}


/*************************** CMDS FOR MONK    ***************/
xpunch_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[21]){ "/players/maledicta/closed/w/power/xpunch.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

xkick_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[22]){ "/players/maledicta/closed/w/power/xkick.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

meditate_cmd(str){
	if(skills[85]){ "/players/maledicta/closed/w/power/meditate.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}







touch(){
	if(!skills[81]) return;
	if(touch){
		write("You will no longer attempt touch attacks.\n");
		touch = 0;
		return 1;
	}
	else{
		write("You will now attempt touch attacks.\n");
		touch = 1;
		return 1;
	}
}


meditate_vision(){
	object *ppl;
	object *ppl2;
	int booya;
	int i;
	
	ppl = users();
	for(i = 0; i < sizeof(ppl); i++){
		if(environment(ppl[i]) && ppl[i]->query_level() < 20){
			if(!ppl2) ppl2 = ({ ppl[i] });
			else ppl2 += ({ ppl[i] });
		}
	}
	booya = random(sizeof(ppl2));
	tell_object(USER, BOLD+"Your mind wanders...\n\n"+NORM);
	tell_object(USER,
	ppl2[booya]->query_name()+" is located at...\n");
	tell_object(USER, call_other(environment(ppl2[booya]), "short")+"\n");
	tell_object(USER, "The vision fades...\n");
	return;
}



monk_bonus(){
	string one,two,three,four,five;
	int samt;
	int samt2;
	int bonus;
	
	bonus = 0;
	samt = skills[80];
	samt2 = skills[81];
	if(!ATT) return;
	if(USER->query_weapon()) return;
	if(samt){
		
		if(perc_end() >= 9) bonus = 16 + random(samt * 2);
		else if(perc_end() > 1) bonus = 13 + random(samt * 2);
		else bonus = 5 + random(samt);
		
		/***** Touch attacks *****/
		if(samt2 && touch){
			if((random(samt2) + 1) * 5 >= ATT->query_level() + random(ATT->query_level()/3)){
				if(USER->query_sp() > 5){
					if(random(100) < 50){ if(ATT->query_ac() > 4) lower_ac(); }
					else{ if(ATT->query_wc() > 8) lower_wc(); }
					USER->add_spell_point(-5);
				}
			}
		}
		
		three = 0;
		four = 0;
		
		/** Power **/
		if(perc_end() >= 4){
			switch(random(8) + 1){
				case 8:  three = BLU+"                       ___  ___\n"+
				"                       ________\n"+
				"                       ________"+NORM+"\n";
				four = BLU+"Lake";  bonus += 2;   break;
				case 7:  three = HIR+"                       ________\n"+
				"                       ___  ___\n"+
				"                       ________"+NORM+"\n";
				four = HIR+"Fire";  bonus += 4;   break;
				case 6:  three = HIW+"                       ________\n"+
				"                       ________\n"+
				"                       ___  ___"+NORM+"\n";
				four = HIW+"Wind";  bonus += 4;   break;
				case 5:  three = GRN+"                       ________\n"+
				"                       ___  ___\n"+
				"                       ___  ___"+NORM+"\n";
				four = GRN+"Mountain"; bonus += 1; break;
				case 4:  three = HIB+"                       ___  ___\n"+
				"                       ________\n"+
				"                       ___  ___"+NORM+"\n";
				four = HIB+"Water";  bonus += 3;  break;
				case 3:  three = HIY+"                       ___  ___\n"+
				"                       ___  ___\n"+
				"                       ________"+NORM+"\n";
				four = HIY+"Thunder"; bonus += 5; break;
				case 2:  three = YEL+"                       ___  ___\n"+
				"                       ___  ___\n"+
				"                       ___  ___"+NORM+"\n";
				four = YEL+"Earth";  bonus += 1;  break;
				case 1:  three = MAG+"                       ________\n"+
				"                       ________\n"+
				"                       ________"+NORM+"\n";
				four = MAG+"Heaven"; bonus += 3;  break;
			}
		}
		/** Where **/
		switch(random(15) + 1){
			case 15: five = "head"; bonus += 2; break;
			case 14: five = "forehead"; bonus += 2; break;
			case 13: five = "neck"; bonus += 1; break;
			case 12: five = "shoulder"; break;
			case 11: five = "chest"; break;
			case 10: five = "stomach"; bonus += 1; break;
			case 9:  five = "ribs"; break;
			case 8:  five = "kidney"; bonus += 2; break;
			case 7:  five = "arm"; break;
			case 6:  five = "groin"; bonus += 2; break;
			case 5:  five = "upper-leg"; break;
			case 4:  five = "shin"; break;
			case 3:  five = "chin"; bonus += 1; break;
			case 2:  five = "forearm"; break;
			case 1:  five = "chest"; break;
		}
		
		/** Style **/
		if(!random(2)){
			switch(random(10) + 1){
				case 10: one = HIR+"Dragon "; bonus += 3; break;
				case 9:  one = HIY+"Cat ";    bonus += 2; break;
				case 8:  one = HIM+"Wolf ";   bonus += 1; break;
				case 7:  one = YEL+"Crane ";  bonus += 2; break;
				case 6:  one = NORM+BOLD+"Wraith "; bonus += 1; break;
				case 5:  one = MAG+"Golem ";  bonus += 3; break;
				case 4:  one = RED+"Monkey "; bonus += 1; break;
				case 3:  one = HIB+"Hawk ";   bonus += 2; break;
				case 2:  one = HIG+"Snake ";  bonus += 2; break;
				case 1:  one = GRN+"Roc ";    bonus += 2; break;
			}
		}
		else{ one = ""; }
		
		if(random(skills[17]) >= random(skills[18])){
			two = "Punch";
			bonus += skills[17];
		}
		else{
			two = "Kick";
			bonus += skills[18];
		}
		
		if(!random(10) && three){
			tell_object(USER, three+"\n");
			bonus += 4;
		}
		
		if(four)
		tell_object(USER,
		BOLD+"You draw on the power of - "+NORM+four+NORM+BOLD+" -"+NORM+"\n");
		
		tell_object(USER,
		HIW+"You strike "+ATTN+" with a "+one+HIW+""+two+" to the "+five+"."+NORM+"\n");
		
		if(USER->query_level() > 19)
		tell_object(USER, HIR+bonus+NORM+" <> BONUS FROM MONK\n");
		return bonus;
	}
	return 0;
}

lower_ac(){
	if(!ATT) return;
	if(!ATT->query_npc()) return;
	if(endurance < 3) return;
	ATT->set_ac(ATT->query_ac() - 1);
	add_end(-3);
	tell_object(USER, BOLD+"[ Touch ]"+NORM+" ");
	
	switch(random(4) + 1){
		case 4:
		tell_object(USER, "You reach out and touch "+ATTN+".\n"+
		"          "+ATTN+" falls back, slowed.\n");
		break;
		case 3:
		tell_object(USER, "You move in low and touch "+ATTN+".\n"+
		"          "+ATTN+" gasps in pain.\n");
		break;
		case 2:
		tell_object(USER, "You reach through "+ATTN+"'s attack and touch "+ATT->OBJ+"...\n"+
		"          "+ATTN+" is partially stunned by the skilled move.\n");
		break;
		case 1:
		tell_object(USER, "You duck and come up behind "+ATTN+".\n"+
		"          "+ATTN+" is slowed as you touch "+ATT->OBJ+".\n");
		break;
	}
	tell_object(USER, NORM+"");
	return;
}

lower_wc(){
	if(!ATT) return;
	if(!ATT->query_npc()) return;
	if(endurance < 3) return;
	ATT->set_wc(ATT->query_wc() - 1);
	add_end(-3);
	tell_object(USER, BOLD+"[ Touch ]"+NORM+" ");
	
	switch(random(4) + 1){
		case 4:
		tell_object(USER, "You touch "+ATTN+".\n"+
		"          "+ATTN+" begins to swing slower.\n");
		break;
		case 3:
		tell_object(USER, "You move in low and touch "+ATTN+".\n"+
		"          "+ATTN+" gasps in pain and looks unsteady.\n");
		break;
		case 2:
		tell_object(USER, "You reach through "+ATTN+"'s attack and touch "+ATT->OBJ+"...\n"+
		"          "+ATTN+" gasps in pain and "+ATT->POS+" weapon lowers.\n");
		break;
		case 1:
		tell_object(USER, "You duck and come up behind "+ATTN+".\n"+
		"          "+ATTN+" is slowed as you touch "+ATT->OBJ+".\n");
		break;
	}
	tell_object(USER, NORM+"");
	return;
}
