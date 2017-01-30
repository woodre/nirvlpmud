static int num;
drop(){ return 1; }
get(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

set_dark_ass(int i){ dark_ass = i; }
query_dark_ass(){ return dark_ass; }

set_shadowcloak(int i){ shadowcloak = i; }
query_shadowcloak(){ return shadowcloak; }

set_rage(int i){ rage = i; }
query_rage(){ return rage; }

query_siphon(){ return siphon; }
set_siphon(){ siphon = 1; }

set_sshield(i){ shadow_shield = i; }
query_sshield(){ return shadow_shield; }

set_end_mon(x){ endurance_monitor = x; }
query_end_mon(){ return endurance_monitor; }

set_weave(x){ weave = x; }

set_focus(x,y){
  focus = x; duration = y;
  if(focus > 24) focus = 24;
  if(duration > 15) duration = 15;
}
add_focus(x,y){ 
  focus += x; duration += y; 
  if(focus > 24) focus = 24;
  if(duration > 15) duration = 15;
}
query_focus(){ return duration; }

add_endurance(x){ endurance += x; }
set_endurance(x){ endurance = x; }
query_endurance(){ return endurance; }
set_max_endurance(x){ max_endurance = x; }
query_max_endurance(){ return max_endurance; }
display_endurance(){
  int j;
  j = (10 * endurance) / (max_endurance * 10);
  if(j < 0) j = 0;
  if(j > 100) j = 100;
  return j; 
}

set_guild_exp(int i){ guild_exp = i; }
query_guild_exp(){ return guild_exp; }
rm_guild_exp(int i){  guild_exp -= i; }
add_guild_exp(i){  guild_exp += i;  }

set_vigor(int i){ vigor = i; }
query_vigor(){ return vigor; }
set_vigor_level(int i){ vigor_level = i; }
set_vigor_bonus(int i){ vigor_bonus = i; }
query_vigor_bonus(){ return vigor_bonus; }

query_combat_method(){ return 2; }
query_paladin_shield(){ return 1; }

query_Skills(){ return Skills; }

query_skills(str){
  if(member_array(str, Skills) < 0) return 0;
  else return 1;
}	

set_skills(string str){ Skills += ({ str }); }
remove_skills(string str){ Skills -= ({ str }); }

set_special_title(y){  special_title = y; }
query_special_title(){ return special_title; }

set_perc(x){  percent = x;  }
query_percent(x){
  if(x)
    return percent;
  else
  {
    if(guild_exp >= 8000000)
      return "Master";
    else if(percent == 0)
      return "Zero";
    else if(percent < 35)
      return "Low";
    else if(percent < 65)
      return "Medium";
    else if(percent >= 65)
      return "High";
  }
}

int getit(int hp_sp, int max){
	int x, z;
	z = ((hp_sp * 100) / max);
	for(x = 100; x > 0; x -= 5)
	{
		if(z >= x)
			return x;
	}
}

set_custom_monitor(m) { custom_monitor = m; }
query_custom_monitor() { return custom_monitor; }

int query_casting(){ return casting; }
void set_casting(int x){ casting = x; }
int interrupt_casting(int x){
  if(!casting || !x) return 0;
  if(x == 1) /* embrace interupt */
  {
    USER->add_hit_point(-50);
    USER->add_spell_point(-20);
    endurance -= 10;
  }
  tell_object(USER, 
    "You feel pain in your head as your casting is interrupted.\n");
  destruct(previous_object());
  return 1;
}
int casting_check(){
  if(casting)
  {
    tell_object(USER, "You are currently casting a spell.\n");
    return 1;
  }
  return 0;
}
