#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";
int branches;
reset(arg){
  ::reset();
  if(arg) return;
  set_name("A Giant Tree");
  set_level(15);
  set_hp(200);
  branches = random(10)+1;
}

init(){
::init();
  if(!random(3) && this_player()->is_player())
    this_object()->attack_object(this_player());
}

heart_beat(){
int i,a;
int tmp;
string msg;
int bonus;
  ::heart_beat();
  if(attacker_ob && environment(attacker_ob) == environment(this_object())){
    a = random(branches);
   say("BRANCHES: "+branches+" A: "+a+"\n"); 
   if(a>5) a = 5;
    for(i=0;i<a;i++){
      tmp = attacker_ob->hit_player(random(30)); 
      switch(tmp){
      case 0: msg = "misses";
        break;
      case 1..5: msg = "thwaps";
        break;
      case 6..10: msg = "hits";
        break;
      case 11..15: msg = "smacks";
        break;
      case 16..20: msg = "clobers";
        break;
      default: msg = "wallops"; bonus = 1;
      }
      tell_object(attacker_ob,"A branch swings out and "+msg+" you.\n");
      if(bonus){
        tell_object(attacker_ob,RED+"\tPain surges through your head.\n"+OFF);
        bonus = 0;
      } 
     say("A branch swings out and "+msg+" "+attacker_ob->query_name()+".\n",attacker_ob);
    }
  }
}

hit_player(i){
     if(i > 25){
        tell_object(previous_object(),BOLD+"You break off a branch\n"+OFF);
        if(this_player())
          this_player()->add_exp(random(2000));
        if(!random(3)) drop_branch();
         branches --;
      }
   if(branches == 0){
     say("The tree fades back into the mist, licking it's wounds.\n");
     destruct(this_object());
   }
return i;
}

attack(){
  if(!attacker_ob)
    return 0;
  if(!call_other(attacker_ob,"query_interactive") && !call_other(attacker_ob,"query_npc"))
    stop_fight();
    return 0;
  if(environment(attacker_ob) != environment(this_object())){
    attacker_ob = 0;
  if(attacker_ob->query_dead())
    attacker_ob = 0;
    return 0;
  }
  return 1;
}

drop_branch(){
object branch;
  branch = clone_object("/obj/treasure.c");
  branch->set_id("branch");
  branch->set_alias("w_branch");
  branch->set_weight(3);
  branch->set_short("A fallen branch");
  branch->set_long("A branch that looks to have broken off of a tree.\n"+
                   "It looks to have come from an evergreen.  Grey consumes\n"+
                   "its bark while a dusty green covers the needles.\n");
  branch->set_value(50);
  branch->set_dest_flag(1);
  move_object(branch,environment(this_object()));
}

query_invis(){ return 100; }
short(){ return;}