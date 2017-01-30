#include "../../defs.h"
#define SPCOST 3

inherit "/obj/monster.c";

string master;
string name;
int lev;
int guildlev;
int mlev;
int follow;
int autoattack;

id(str){ return str == "zombie" || str == "dead" || str == "undead" || str == "necro_zombie"; } 
 

short(){ return "A rotting zombie"; }
long(){  
  write(capitalize(master)+"'s zombie.\n");
  return 1;
}

reset(arg){
  ::reset();
  if(arg) return; 
    name = "zombie";
    master = "wocket";
    follow = 1;
}

setup(){
  set_hp(lev*8);
  set_wc(30);
  set_ac(9);
}

heart_beat(){
object mas;
::heart_beat();
mas = find_player(master);
  if(!mas){ destruct(this_object()); }
  if(environment(mas) != environment(this_object()) && follow){
    tell_room(environment(this_object()),cap_name+" leaves following "+capitalize(master)+".\n");
    move_object(this_object(),environment(mas));
    tell_room(environment(this_object()),cap_name+" arrives following "+capitalize(master)+".\n");
  }
  if(autoattack && mas->query_attack() && !this_object()->query_attack()){
    tell_room(environment(this_object()),cap_name+" moves to assist "+capitalize(master)+"'s battle.\n");
    this_object()->attack_object(mas->query_attack());
  }
  if(mas->query_sp() < SPCOST){
    say(BOLD+"zombie falls apart.\n"+OFF);
    destruct(this_object());
  }    
  if(!random(10)){
    tell_object(mas,GRN+"A green mist of your energy floods into your zombie.\n"+OFF);
  }
  mas->add_spell_point(-SPCOST);
}

init(){
::init();
  add_action("youtalkntome","zombie");
  add_action("you talkntome","z");
}

decay(){
  remove_call_out("decay");
  say("zombie falls apart.\n");
  destruct(this_object());
}

hit_player(){
  if(!random(20)){
    say(BOLD+cap_name+" just lost some body part!\n"+OFF);
  }
}

youtalkntome(str){
string arg;
object pres;
int which;
  if(tprn != master){
    notify_fail("The zombie ignores you.\n");
    return 0;
  }
  if(!str){
    notify_fail("What would you like your zombie to do?\n");
    return 0; 
  }
  sscanf(str,"%d %s",which,arg);
  if(!arg){
    if(!which){ which = 1; arg = str; }
  }
  pres = present("necro_zombie "+which,environment(this_object())); 
  if(!pres){
    notify_fail("You do not have that many zombies.\n");
    return 0;
  }
  if(!arg){
    notify_fail("What would you like your number "+which+" zombie to do?\n");
    return 0;
  }
  if(present(pres,environment(this_object())) == this_object()){
    write(which+"\n");
    if(ohhcommandme(arg)) return 1; else return 0;
  }
  return 0;
}
 
ohhcommandme(arg){
string cmd,str;
  if(!arg){
    notify_fail("(This shouldn't happen.  Notify Wocket.)\n");
    return 0;
  }
  sscanf(arg,"%s %s",cmd,str);
  if(!str) cmd = arg;

  switch(cmd){
    case "attack":      return do_attack(str);                  break; 
    case "stop":        return do_stop(str);                    break;
    case "follow":      return do_follow(str);                  break;
    case "autoattack":  return do_autoattack(str);              break;
    case "whither":     return do_whither(str);                 break;
    default:  notify_fail("Your zombie looks at you funny\n");  return 0;
  }
  return 1;
}

do_whither(){
  write("You tell your zombie to whither.\n");
  say(cap_name+" falls to the ground and whithers away.\n");
  destruct(this_object());
  return 1;
}

do_autoattack(str){
  if(autoattack){
    notify_fail("Your zombie is already autoattacking.\n");
    return 0;
  }
  write("With your unspoken connection you tell your zombie to autoattack.\n");
  write("Your zombie nods.\n");
  say(cap_name+" nods.\n");
  autoattack = 1;
  return 1;
}

do_attack(str){
object meat;
  if(!str){
    notify_fail("Who do you want your zombie to attack?\n");
    return 0;
  }
  meat = present(str,environment(this_object()) );
  if(!meat){
    write("The zombie does not find that to attack.\n");
    return 1;
  }
  if(!meat->is_npc()){
    write("Your zombie refuses to attack that.\n");
    return 1;
  }
  write("Your zombie slowly moves to attack "+meat->short()+".\n");
  this_object()->attack_object(meat);
  return 1;
}

do_follow(str){
  if(follow){
    notify_fail("Your zombie is already following.\n");
    return 0;
  }
  write("You tell your zombie to follow you.\n");
  write("zombie nods.\n");
  follow = 1;
  return 1;
}

do_stop(str){
  if(!str){
    notify_fail("What would you like your zombie to stop doing?\n");
    return 0;
  }
  switch(str){
    case "attacking":     return stop_attacking();          break;
    case "following":     return stop_following();          break;
    case "autoattacking": return stop_autoattacking();      break;
    default: notify_fail("Your zombie doesn't understand.\n"); return 0;
  }
}

stop_attacking(){
  if(!this_object()->query_attack()){
    notify_fail("Your zombie is not attacking.\n");
    return 0;
  }
  write("You, through your unspooken connection, tell "+cap_name+" to stop attacking.\n");
  write("Your zombie nods.\n");  say(cap_name+" nods.\n");
  write("Your zombie moves out of combat.\n");
  this_object()->stop_fight();
  return 1;
}

stop_following(){
  if(!follow){
    notify_fail("Your zombie is not following.\n");
    return 0;
  }
  write("You, through your unspooken connection, tell "+cap_name+" to stop following.\n");
  write("Your zombie nods.\n");  say(cap_name+" nods.\n");
  write("Your zombie stops following you.\n");
  follow = 0;
  return 1; 
}

stop_autoattacking(){
  if(!autoattack){
    notify_fail("Your zombie is not autoattacking.\n");
    return 0;
  }
  write("You, through your unspooken connection, tell "+cap_name+" to stop autoattacking.\n");
  write("Your zombie nods.\n");  say(cap_name+" nods.\n");
  write("Your zombie stops autoattacking you.\n");
  autoattack = 0;
  return 1;
}

set_master(m){ master = m; }
set_name(n){ name = n; cap_name = capitalize(name)+"'s Zombie"; }
set_level(l){ lev = l; }
set_m_glevel(l){ guildlev = l; }
set_m_level(l){ mlev = l; }

query_master(){ return master; }
query_name(){ return cap_name; }
query_real_name(){ return name; }
qurey_level(){ return lev; }
