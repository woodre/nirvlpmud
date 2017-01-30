#include "/players/wocket/closed/ansi.h"
string name;

int level;
int hit_points;
int max_hit_points;
int spell_points;
int max_spell_points;
int wc,ac;
int exp;
int is_dead;
int dieing;
int healing;
int healtime;

object attacker_ob;
id(str){ return str == "orieka"; }

short(){ return "Orieka v0.001"; }

reset(){
hit_points = max_hit_points = 100;
is_dead = 0;
level = 1;
wc = 70;
ac = 10;
healtime = 10;
  enable_commands();
  set_heart_beat(1);
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
case 1: what = "tickled"; how = "in the stomach"; break;
case 2: what = "grazed"; how = ""; break;
case 3..4: what = "hit"; how = ""; break;
case 5..9: what = "hit"; how = "hard"; break;
case 10..19: what = "hit"; how = "very hard"; break;
case 20..29: what = "smashed"; how = "with a bone crushing sound"; break;
case 30..39: what = "massacred"; how = "into small fragments"; break;
default: what = "destroyed"; how = "with a single blow"; break;
}
if(!attacker_ob || attacker_ob->query_ghost()){
  attacker_ob = 0;
  return 0;
}
tell_object(attacker_ob,"Orieka "+what+" you "+how+".\n");
say("Orieka "+what+" "+attacker_ob->query_name()+" "+how+".\n",attacker_ob);
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

add_exp(int ammount){ exp = exp + ammount; }
stop_fight(){ attacker_ob = 0; }
attacked_by(obj){ attacker_ob = obj; }
query_attack(){ return attacker_ob; }

set_name(string n){ name = n; }
set_level(int l){ level = l; }
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
write("Wc: "+wc+"     Ac: "+ac+"\n");
write("Exp: "+exp+"\n");
return 1;
}
