#include "../defs.h"
#define SPCOST 5

inherit "/obj/monster.c";
object mas;

string master;
string name;
int lev;
int guildlev;
int mlev;
int follow;
int autoattack;
int time;

id(str){ return str == "skeleton" || str == "dead" || str == "undead" || str == "necro_skeleton"; } 
 

short(){ return "The skeletal remains of "+BOLD+capitalize(name)+OFF+" (undead)"; }
long(){  
  write("The undead skeleton of "+capitalize(name)+".\n"+
        "It stands erect, held together only by the magical power of "+capitalize(master)+".  If a\n"+
        "skull could have different looks this one would be as blank as an unused\n"+
        "canvas.  It is here only to do its masters bidding.\n");
  if(this_player()->query_real_name() == master){
  write(HIR+"You may tell your 'skeleton' to: attack, follow, autoassist, collapse, or stop.\n"+OFF);
  }
  return 1;
}

reset(arg){
  ::reset();
  if(arg) return; 
    set_name("nobody");
    set_master("wocket");
    follow = 1;
    set_dead_ob(this_object());
}

setup(){
  set_hp(130);
  set_wc(16);
  set_ac(1);
  time = 100;
}

heart_beat(){
::heart_beat();
  if(!mas){ do_whither(); return 1;}
  if(environment(mas) != environment(this_object()) && follow){
    tell_room(environment(this_object()),cap_name+" leaves following "+capitalize(master)+".\n");
    move_object(this_object(),environment(mas));
    tell_room(environment(this_object()),cap_name+" arrives following "+capitalize(master)+".\n");
  }
  if(autoattack && mas->query_attack() && !this_object()->query_attack() && !mas->query_attack()->is_player() ){
    tell_room(environment(this_object()),cap_name+" moves to assist "+capitalize(master)+"'s battle.\n");
    this_object()->attack_object(mas->query_attack());
  } 
  if(this_object()->query_attack()){
    if(this_object()->query_attack()->query_attack() != this_object()){
        secondhitme();
    }
  }
  if(!random(20)){
    tell_object(mas,BOLD+"A white mist of your energy floods into your skeleton.\n"+OFF);
     mas->add_spell_point(-SPCOST);
  }
  time--;
  if(time == 10 || (time < 10 && !random(3)) ){
    say(BOLD+"The skeleton begins to waiver.\n"+OFF);
  }
  if(time < 0){
    say(BOLD+"The skeleton falls into a pile of bones.\n"+OFF);
    if(environment()) /* added by verte, not sure how this happens. 6-6-01 */
    move_object(clone_object(OBJ+"/bodyparts/bones.c"),environment(this_object()));
    destruct(this_object());
    return 1;
  }    
}

secondhitme(){
int dam;
string verb;
  if(random(100) < 20){
   dam = random(20);
  switch(dam){
    case 0:  verb = " misses "; break;
    case 1..3:  verb = " grazes "; break;
    case 4..9:  verb = " hits "; break;
    case 10..15: verb = " smashes "; break;
    case 16..20: verb = " crushes "; break;
  }
  tell_room(environment(this_object()),this_object()->query_attack()->query_name()+verb+cap_name+" with a side attack.\n");
  hit_player(dam);
  }
}

init(){
::init();
  add_action("youtalkntome","skeleton");
  
}


youtalkntome(str){
string arg;
object pres;
int which;
  if(tprn != master){
    notify_fail("The skeleton ignores you.\n");
    return 0;
  }
  if(!str){
    notify_fail("What would you like your skeleton to do?\n");
    return 0; 
  }
  sscanf(str,"%d %s",which,arg);
  if(!arg){
    if(!which){ which = 1; arg = str; }
  }
  pres = present("necro_skeleton "+which,environment(this_object())); 
  if(!pres){
    notify_fail("You do not have that many skeletons.\n");
    return 0;
  }
  if(!arg){
    notify_fail("What would you like your number "+which+" skeleton to do?\n");
    return 0;
  }
 if(!pres){
    notify_fail("You do not have that many skeletons.\n");
    return 0;
  }
 return ohhcommandme(arg);
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
    case "autoassist":  return do_autoattack(str);              break;
    case "collapse":     return do_whither(str);                 break;
    default:  notify_fail("Your skeleton looks confused.\n");  return 0;
  }
  return 1;
}

do_whither(){
  write("You tell your skeleton to collapse.\n");
  say(cap_name+" falls to the ground, forming a pile of bones.\n");
   if(environment()) /* added by verte 6.6.01 */
  move_object(clone_object(OBJ+"/bodyparts/bones.c"),environment(this_object()));
  destruct(this_object());
  return 1;
}

do_autoattack(str){
  if(autoattack){
    notify_fail("Your skeleton is already autoassist.\n");
    return 0;
  }
  write("With your unspoken connection you tell your skeleton to autoassist.\n");
  write("Your skeleton nods.\n");
  say(cap_name+" nods.\n",this_player());
  autoattack = 1;
  return 1;
}

do_attack(str){
object meat;
  if(!str){
    notify_fail("Who do you want your skeleton to attack?\n");
    return 0;
  }
  meat = present(str,environment(this_object()) );
  if(!meat){
    write("The skeleton does not find that to attack.\n");
    return 1;
  }
  if(meat->is_player()){
    write("Your skeleton refuses to attack that.\n");
    return 1;
  }
  write("Your skeleton slowly moves to attack "+meat->short()+".\n");
  this_object()->attack_object(meat);
  return 1;
}

do_follow(str){
  if(follow){
    notify_fail("Your skeleton is already following.\n");
    return 0;
  }
  write("You tell your skeleton, through your unspoken connection, to follow you.\n");
  say(cap_name+" nods.\n");
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
    case "autoassisting": return stop_autoattacking();      break;
    default: notify_fail("Your skeleton doesn't understand.\n"); return 0;
  }
}

stop_attacking(){
  if(!this_object()->query_attack()){
    notify_fail("Your skeleton is not attacking.\n");
    return 0;
  }
  write("You, through your unspoken connection, tell "+cap_name+" to stop attacking.\n");
  write("Your skeleton nods.\n");  say(cap_name+" nods.\n",this_player());
  write("Your skeleton moves out of combat.\n");
  this_object()->stop_fight();
  return 1;
}

stop_following(){
  if(!follow){
    notify_fail("Your skeleton is not following.\n");
    return 0;
  }
  write("You, through your unspoken connection, tell "+cap_name+" to stop following.\n");
  write("Your skeleton nods.\n");  say(cap_name+" nods.\n",this_player());
  write("Your skeleton stops following you.\n");
  follow = 0;
  return 1; 
}

stop_autoattacking(){
  if(!autoattack){
    notify_fail("Your skeleton is not autoassisting.\n");
    return 0;
  }
  write("You, through your unspoken connection, tell "+cap_name+" to stop autoassistinging.\n");
  write("Your skeleton nods.\n");  say(cap_name+" nods.\n",this_player());
  write("Your skeleton stops autoassisting you.\n");
  autoattack = 0;
  return 1;
}

monster_died(){
    if(present("corpse",environment(this_object()))){
      say(BOLD+"The skeleton falls into a pile of bones.\n"+OFF);
      destruct(present("corpse",environment(this_object())));
      move_object(clone_object(OBJ+"/bodyparts/bones.c"),environment(this_object()));
    }
return 1;
}


set_master(m){ master = m; mas = find_player(master);}
set_name(n){ name = n; cap_name = BOLD+capitalize(name)+"'s "+OFF+"undead skeleton"+OFF; }
set_level(l){ lev = l; }
set_m_glevel(l){ guildlev = l; }
set_m_level(l){ mlev = l; }

query_master(){ return master; }
query_mas(){ return mas; }
query_name(){ return cap_name; }
query_real_name(){ return name; }
qurey_level(){ return lev; }
