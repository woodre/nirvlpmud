gtp(int i){
	int one;
	int two;
	one = skill_tier[i] * 100;
	two = get_skill_tier(skills[i]);
	if(one == 0 || two == 0) return 0;
	else if(one/two > 100) return 100;
	else return one/two;
}

get_skill(int i){
	return skills[i];
}

query_glvl(){ return glvl; }
get_etl(int i){  return exp_to_level[i]; }
query_gxp(){ return gxp; }
query_skill_pts(){ return skill_pts; }

ast(int i){  skill_tier[i] += 1; }
reset_skill_tier(int i){ skill_tier[i] = 0; }
query_skill_tier(int i){ return skill_tier[i]; }

query_healing(){ return healing; }
set_healing(int i){ healing = i; }
set_heal_room(str){ heal_room = str; }
query_heal_room(){ return heal_room; }
