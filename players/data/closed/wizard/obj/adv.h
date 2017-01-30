convert_xp(int i){
	int expcost,minexp,woo;
	
	if(glvl > 39){ write("You are maxed as a Warrior.\n"); return 1; }
	if(!i){ write("convert how many experience points?\n"); return 1; }
	sscanf(i, "%d", woo);
	if(USER->query_level() > 19) return 1;
	
	if(woo < 1){
		write("You must convert a positive number of experience points.\n");
	return 1; }
	if(woo > 1000000){ write("Please limit conversion to a maximum of one million.\n");
		return 1;
	}
	expcost = woo;
	
	if(USER->query_extra_level() < 1 && USER->query_level() < 21)
	minexp = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",
	(this_player()->query_level()) - 1);
	
	if(USER->query_extra_level() > 0 && USER->query_level() < 21)
	minexp = USER->query_exp() - call_other("room/exlv_guild", "get_next_exp",
	USER->query_extra_level() - 1);
	
	if(expcost > minexp) {
		write("You do not have enough available experience to convert.\n");
		return 1;
	}
	
	USER->add_exp(-expcost);
	write("You convert "+i+" experience towards your profession.\n");
	write_file("/players/maledicta/closed/w/logs/adv",
	this_player()->query_real_name()+"::"+USER->query_exp()+"::"+woo+"::"+gxp+"::"+USER->query_exp()+"\n");
	if(gxp < 0){
		write_file("/players/maledicta/closed/w/logs/adv",
		HIR+this_player()->query_real_name()+"::"+gxp+""+NORM+"\n");
	}
	check_advance(expcost);
	return 1;
}



check_advance(exp){
	
	if(glvl > 39) return;
	
	gxp += exp;
	
	if(exp_to_level[glvl] <= gxp){
		gxp = gxp - exp_to_level[glvl];
		glvl += 1;
		skill_pts += 1;
		
		if(gxp < 0){
			write_file("/players/maledicta/closed/w/logs/adv",
			HIR+this_player()->query_real_name()+"::"+gxp+""+NORM+"\n");
		}
		
		if(glvl == 5) raise_or(10);
		else if(glvl == 8) raise_or(15);
		else if(glvl == 12) raise_or(18);
		else if(glvl == 18) raise_or(20);
		else if(glvl == 23) raise_or(25);
		else if(glvl == 29) raise_or(30);
		else if(glvl == 33) raise_or(40);
		else if(glvl == 37) raise_or(45);
		else if(glvl == 40){ raise_or(50); raise_or(50); }
		
		tell_object(USER,
			"\n"+HIR+"  ------ ---- "+HIW+"You Gain a Level"+HIR+" ---- ------ "+NORM+"\n"+
		"       You are now level "+glvl+".\n");
		if(glvl < 40)
		if(exp_to_level[glvl + 1] < gxp) check_advance(0);
		silent_save();
		return 1;
	}
	return 1;
}

raise_skill(str){
	if(!str){
		write("Raise which skill? type 'skills' for a listing.\n");
		return 1;
	}
	if(!skill_pts){
		write("You do not have skill points to spend.\n");
		return 1;
	}
	if(!get_skill_num(str)){
		write("You are unable to train "+str+".\n");
		return 1;
	}
	if(skills[get_skill_num(str)] >= get_skill_max(str)){
		write("You have already maxed "+str+".\n");
		return 1;
	}
	if(skill_tier[get_skill_num(str)] < get_skill_tier(skills[get_skill_num(str)]) && str != "blindfight"){
		write("You have not used that skill enough to raise it.\n");
		return 1;
	}
	
	skills[get_skill_num(str)] += 1;
	write("You raise "+str+" to skill level "+get_skill(get_skill_num(str))+".\n");
	skill_pts -= 1;
	do_add(str);
	skill_tier[get_skill_num(str)] = 0;
	silent_save();
	return 1;
}

int strup;
int steup;
int staup;

get_strup(){ return strup; }
get_steup(){ return steup; }
get_staup(){ return staup; }

do_add(str){
	if(str == "blunt"){ strup += 1; }
	else if(str == "edged"){ strup += 1; }
	else if(str == "polearm"){ strup += 1; }
	else if(str == "archery"){ steup += 1; }
	else if(str == "exotic"){ strup += 1; }
	else if(str == "small"){ steup += 1; }
	else if(str == "throw"){ steup += 1; }
	else if(str == "strike"){ steup += 1; }
	else if(str == "punch"){ strup += 1; steup += 1; }
	else if(str == "kick"){ strup += 1; steup += 1; }
	else if(str == "charge"){ strup += 1; }
	else if(str == "bash"){ strup += 1; }
	else if(str == "dodge"){ steup += 1; }
	else if(str == "parry"){ steup += 1; }
	else if(str == "offhand"){ steup += 1; }
	else if(str == "block"){ steup += 1; }
	else if(str == "pummel"){ strup += 1; }
	else if(str == "finish"){ steup += 1; }
	else if(str == "firstaid"){ return 1; }
	else if(str == "run"){ staup += 1; }
	else if(str == "blindfight"){ return 1; }
	return 1;
}

raise_or(int i){
	int one;
	int two;
	if(random(100) < i){
		if(steup)
		one = random(steup) + 1;
		if(strup)
		two = random(strup) + 1;
		if(one == two){ if(random(100) < 50) strength_bonus += 1; else stealth_bonus += 1; }
		else if(one > two){ if(one) stealth_bonus += 1; }
		else{ if(two) strength_bonus += 1; }
		if(random(100) < 23){ skill_pts += 1; }
		if(random(100) < 25){ stamina_bonus += 1; }
	}
	else return;
}


get_skill_tier(int i){
	if(!i) return 0;
	else if(i == 1) return 50;
	else if(i == 2) return 100;
	else if(i == 3) return 200;
	else if(i == 4) return 400;
	else if(i == 5) return 800;
	else if(i == 6) return 1200;
	else if(i == 7) return 1500;
	else if(i == 8) return 2000;
	else if(i == 9) return 4000;
	else return 5000;
}

get_skill_num(str){
	if(str == "blunt"){ return 1; }
	else if(str == "edged"){ return 2; }
	else if(str == "polearm"){ return 3; }
	else if(str == "archery"){ return 4; }
	else if(str == "exotic"){ return 5; }
	else if(str == "small"){ return 6; }
	else if(str == "throw"){ return 15; }
	else if(str == "strike"){ return 16; }
	else if(str == "punch"){ return 17; }
	else if(str == "kick"){ return 18; }
	else if(str == "charge"){ return 19; }
	else if(str == "bash"){ return 20; }
	else if(str == "dodge"){ return 30; }
	else if(str == "parry"){ return 31; }
	else if(str == "offhand"){ return 32; }
	else if(str == "block"){ return 33; }
	else if(str == "pummel"){ return 40; }
	else if(str == "finish"){ return 41; }
	else if(str == "firstaid"){ return 50; }
	else if(str == "run"){ return 60; }
	else if(str == "blindfight"){ return 70; }
	return 0;
}

get_skill_max(str){
	if(str == "blunt"){ return 10; }
	else if(str == "edged"){ return 10; }
	else if(str == "polearm"){ return 10; }
	else if(str == "archery"){ return 10; }
	else if(str == "exotic"){ return 10; }
	else if(str == "small"){ return 10; }
	else if(str == "throw"){ return 5; }
	else if(str == "strike"){ return 5; }
	else if(str == "punch"){ return 5; }
	else if(str == "kick"){ return 5; }
	else if(str == "charge"){ return 5; }
	else if(str == "bash"){ return 5; }
	else if(str == "dodge"){ return 5; }
	else if(str == "parry"){ return 5; }
	else if(str == "offhand"){ return 5; }
	else if(str == "block"){ return 5; }
	else if(str == "pummel"){ return 5; }
	else if(str == "finish"){ return 3; }
	else if(str == "firstaid"){ return 5; }
	else if(str == "run"){ return 3; }
	else if(str == "blindfight"){ return 2; }
	return 0;
}
