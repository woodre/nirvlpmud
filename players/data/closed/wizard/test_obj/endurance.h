/****** Endurance is used by advanced professions **/


monitor(str){
	if(!str){
		this_player()->print_monitor();
		return 1;
	}
	else{
		this_player()->cmd_monitor(str);
		return 1;
	}
	return 1;
}

print_monitor(){
	tell_object(USER,
		HIW+"["+HIR+USER->query_hp()+NORM+"/"+HIR+USER->query_mhp()+NORM+HIW+"]"+
	" ["+HIB+USER->query_sp()+NORM+"/"+HIB+USER->query_msp()+NORM+HIW+"]"+NORM+" ");
	if(USER->query_stuffed())
	tell_object(USER,
	HIW+"F "+HIG+USER->query_stuffed()*100/(USER->query_level()*8)+NORM+"% ");
	if(USER->query_soaked())
	tell_object(USER,
	HIW+"S "+HIG+USER->query_soaked()*100/(USER->query_level()*8)+NORM+"% ");
	if(USER->query_intoxination())
	tell_object(USER,
	HIW+"I "+HIG+USER->query_intoxination()*100/(USER->query_level()+3)+NORM+"% ");
	if(USER->query_infuse())
	tell_object(USER,
	HIW+"T "+HIG+USER->query_infuse()*100/(USER->query_level()*9)/2+NORM+"% ");
	if(USER->query_attack())
	tell_object(USER,
	HIM+"AHP "+HIW+"["+HIM+ATT->query_hp()*10/ATT->query_mhp()+HIW+"/"+HIM+"10"+HIW+"]"+NORM+"\n");
	else tell_object(USER, "\n");
	if(glvl > 40){
		if(monk || paladin || knight || assassin || berserker) show_end();
	}
	return 1;
}

guild_monitor_only(){ return 1; }

/********************** ENDURANCE ****************************/
query_end(){ return endurance; }
query_max_end(){ return ((glvl - 40) * 15) + 10 + USER->query_attrib("wil"); }

set_end(int i){
	endurance = i;
	if(endurance > query_max_end()) endurance = query_max_end();
	if(endurance < 0) endurance = 0;
}

add_end(int i){
	endurance += i;
	if(endurance > query_max_end()) endurance = query_max_end();
	if(endurance < 0) endurance = 0;
}

perc_end(){ return (query_end() * 10) / query_max_end(); }

show_end(){
	int calmt;
	if(glvl < 41) return;
	calmt = (query_end() * 10) / query_max_end();
	tell_object(USER,
	HIR+"["+HIW+"X POWER"+HIR+"] "+NORM);
	if(calmt >= 10){ tell_object(USER, HIR+"|||"+HIY+"||||"+HIG+"|||"+NORM+"\n"); }
	else if(calmt == 9){ tell_object(USER, HIR+"|||"+HIY+"||||"+HIG+"||"+NORM+"\n"); }
	else if(calmt == 8){ tell_object(USER, HIR+"|||"+HIY+"||||"+HIG+"|"+NORM+"\n"); }
	else if(calmt == 7){ tell_object(USER, HIR+"|||"+HIY+"||||"+NORM+"\n"); }
	else if(calmt == 6){ tell_object(USER, HIR+"|||"+HIY+"|||"+NORM+"\n"); }
	else if(calmt == 5){ tell_object(USER, HIR+"|||"+HIY+"||"+NORM+"\n"); }
	else if(calmt == 4){ tell_object(USER, HIR+"|||"+HIY+"|"+NORM+"\n"); }
	else if(calmt == 3){ tell_object(USER, HIR+"|||"+NORM+"\n"); }
	else if(calmt == 2){ tell_object(USER, HIR+"||"+NORM+"\n"); }
	else if(calmt == 1){ tell_object(USER, HIR+"|"+NORM+"\n"); }
	else{ tell_object(USER, HIR+"DEPLETED"+NORM+"\n"); }
	return 1;
}


