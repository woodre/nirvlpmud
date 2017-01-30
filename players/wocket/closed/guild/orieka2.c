#include "/players/wocket/closed/ansi.h"
string name;

int level;
int hit_points;
int max_hit_points;
int spell_points;
int max_spell_points;
int wc,ac;
int exp;
int strength,stamina,will_power,magic,piety,stealth,luck,intelligence;
int is_dead;
int dieing;
int healing;
int healtime;

object attacker_ob;
id(str){ return (str == "orieka" || str == name); }

short(){ return "Orieka v0.002 ("+name+")"; }

reset(){
is_dead = 0;
level = 1;
wc = 3;
ac = 0;
strength = stamina = luck = intelligence = 8;
magic = will_power = piety = stealth = 8;
healtime = 10;
  enable_commands();
  set_heart_beat(1);
  hit_points = max_hit_points;
  spell_points = max_spell_points;
}

refigure(){
max_hit_points = 42+(level*8)+((stamina-8)*8);
if(max_hit_points < 5) max_hit_points = 5;
max_spell_points = 42+(level*8)+((magic-8)*8);
if(max_spell_points < 0) max_spell_points = 0;
wc = ((level+strength+3)/2)+(random(luck)/5);
ac = ((level+stealth)/4)+(random(luck)/5);
save_me();
}

save_me(){
save_object("players/wocket/closed/guild/members/"+name);
return 1;
}

restore_me(){
if(!restore_object("players/wocket/closed/guild/members/"+name))
save_me();
return 1;
}

init(){
  add_action("okill","okill");
  add_action("oadvance","oadvance");
  add_action("oaction");add_xverb("o");
}

oaction(string str){
if(command(str)) return 1;
return 0;
}

okill(string tar){
write("You command Orieka to attack.\n");
attacker_ob = present(tar,environment(this_object()));
return 1;
}

heart_beat(){
  if(!healing && hit_points != max_hit_points){
    healing = 1;
    call_out("autoheal",healtime);
  }
  if(attacker_ob && present(attacker_ob,environment(this_object()))){
    attack();
  }
}

hit_player(int dam){
  dam = dam - random(ac);
if(dam > 0) hit_points = hit_points - dam;
if(hit_points < 1){
    is_dead = 1;
    attacker_ob->stop_fight();
    attacker_ob->stop_fight();
    stop_fight();
say ("Orieka dies.\n");
  }
return 1;
}

attack(){
int dam;
string what,how;
dam = call_other(attacker_ob,"hit_player",random(wc));
switch(dam){
case 0: what = "missed"; how = ""; break;
case 1: what = "tickled"; how = " in the stomach"; break;
case 2: what = "grazed"; how = ""; break;
case 3..4: what = "hit"; how = ""; break;
case 5..9: what = "hit"; how = " hard"; break;
case 10..19: what = "hit"; how = " very hard"; break;
case 20..29: what = "smashed"; how = " with a bone crushing sound"; break;
case 30..39: what = "massacred"; how = " into small fragments"; break;
default: what = "destroyed"; how = " with a single blow"; break;
}
if(!attacker_ob || attacker_ob->query_ghost()){
  attacker_ob = 0;
  return 0;
}
tell_object(attacker_ob,"Orieka "+what+" you"+how+".\n");
say("Orieka "+what+" "+attacker_ob->query_name()+how+".\n",attacker_ob);
}

autoheal(int ammount){
  hit_points++;
  if(hit_points != max_hit_points)
    call_out("autoheal",healtime);
  else
  healing = 0;
}

move_player(string dest_dir){
string dest,dir;

if(!dest_dir) return 0;
if(sscanf(dest_dir,"%s#%s",dir,dest) != 2) return 0;

say("Orieka leaves "+dir+".\n");
move_object(this_object(),dest);
say("Orieka enters.\n");
return 1;
}

query_attrib(string atr){
switch(atr){
case "str":  return strength; break;
case "sta":  return stamina; break;
case "wil":  return will_power; break;
case "mag":  return magic; break;
case "pie":  return piety; break;
case "ste":  return stealth; break;
case "luc":  return luck; break;
case "int":  return intelligence; break;
default: return 0;
}}

raise_strength(arg){ strength = strength+arg; refigure(); }
raise_stamina(arg){ stamina = stamina+arg; refigure();}
raise_will_power(arg){ will_power = will_power+arg; refigure(); }
raise_magic_aptitude(arg){ magic = magic+arg; refigure(); }
raise_piety(arg){ piety = piety+arg; refigure();}
raise_stealth(arg){ stealth = stealth+arg; refigure();}
raise_luck(arg){ luck = luck+arg; refigure();}
raise_intelligence(arg){ intelligence = intelligence+arg; refigure(); }


set_attrib(string atr,int arg){
switch(atr){
case "str":  strength = arg; break;
case "sta":  stamina = arg; break;
case "wil":  will_power = arg; break;
case "mag":  magic = arg; break;
case "pie":  piety = arg; break;
case "ste":  stealth = arg; break;
case "luc":  luck = arg; break;
case "int":  intelligence = arg; break;
}
}
add_exp(int ammount){ exp = exp + ammount; }
stop_fight(){ attacker_ob = 0; }
attacked_by(obj){ attacker_ob = obj; }
query_attack(){ return attacker_ob; }

set_name(string n){ name = n; }
set_level(int l){ level = l; refigure(); }
set_max_hp(int n){ max_hit_points = n; }
query_name(){ return "Orieka"; }
query_level(){ return level; }
query_exp(){ return exp; }
query_hp(){ return hit_points; }
query_mhp(){ return max_hit_points; }
query_sp(){ return 10; }
query_msp(){ return 10; }
query_ghost(){ return is_dead; }
query_npc(){ return 1; }
is_npc(){ return 1; }

show_stats(){
if(this_player() != find_player("wocket")){
  write("Orieka has no stats.\n");
  return 1;
}
write("Name: "+query_name()+".\n");
write("Level: "+level+"\n");
write("Hp: "+hit_points+"/"+max_hit_points+"\n");
write("Sp: "+spell_points+"/"+max_spell_points+"\n");
write("Wc: "+wc+"     Ac: "+ac+"\n");
write("Exp: "+exp+"\n");
write("Str: "+strength+"\tSta: "+stamina+"\tWil: "+will_power+"\tMag: "+magic+"\n");
write("Pie: "+piety+"\tSte: "+stealth+"\tLuc: "+luck+"\tInt: "+intelligence+"\n");
return 1;
}
