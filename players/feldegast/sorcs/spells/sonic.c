
#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "sonic";
  spell_short = "Sonic";
  spell_desc = "A sonic blast\n";
  spcost = 25;
  hpcost = 0;
  coincost = 0;
  type = "sor";
  size = 2;
  time = 1;
}

check_spell(object mage,string str){
  target = previous_object()->get_target(str);
  if(!target){
    tell_object(mage,"There must be a target for this spell.\n");
    return 0;
  }
  if(!previous_object()->target_ok(target)){
    tell_object(mage,"That is not a valid target.\n");
    return 0;
  }
  return 1;
}

cast_spell(object mage){
int damage,dam;
  tell_object(mage,"You cast sonic waves.\n");
  mage->remote_say(mage->query_name()+"casts sonic waves.\n");
  target->attacked_by(mage);
  damage = mage->query_level()+mage->query_extra_level()+random(50);
  if(damage > 50) damage = 50;
  dam = target->hit_player(damage);
  get_emote(mage,target,dam);
  return 1;
}

get_emote(string mage,string target,int dam){
  string roommsg;
  string targetmsg;
  string magemsg;
  if(!target) return; 
    switch(dam){
case 0:      roommsg =  mage->query_name()+" missed "+target->query_name()+" with a sonic blast.\n"; 
             targetmsg = mage->query_name()+" missed you with a sonic blast.\n";
             magemsg = "You missed "+targetmsg+" with a sonic blast.\n";
             break;
case 1..10:  roommsg = mage->query_name()+" knocks "+target->query_name()+" back with a sonic wave.\n";
             targetmsg = mage->query_name()+" knocks you back with a sonic wave.\n";
             magemsg = "You knocks "+target->query_name()+" back with a sonic wave.\n";
case 11..20: roommsg = mage->query_name()+" blasts "+target->query_name()+" with "+HIB+"waves"+OFF+" of "+HIB+"sonic"+OFF+" energy.\n";
             targetmsg = mage->query_name()+" blasts you with "+HIB+"waves"+OFF+" of "+HIB+"sonic"+OFF+" energy.\n"; 
             magemsg = "You blast "+target->query_name()+" with "+HIB+"waves"+OFF+" of "+HIB+"sonic"+OFF+" energy.\n";
             break;
case 21..40: roommsg = mage->query_name()+" sends "+HIB+"SONIC"+HIW+"WAVES"+OFF+" which CRASH into "+target->query_name()+".\n";
             targetmsg = mage->query_name()+" sends "+HIB+"SONIC"+HIW+"WAVES"+OFF+" which CRASH into you.\n";
             magemsg = "You sends "+HIB+"SONIC"+HIW+"WAVES"+OFF+" which CRASH into "+target->query_name()+".\n";
             break;
default:     roommsg = HIB+target->query_name()+" whimpers as "+HIW+"SONIC WAVES"+HIB+" internally crush "+target->query_possessive()+" bones to a dust.\n"+OFF; 
             targetmsg = "You begin whimpers as "+HIW+"SONIC WAVES"+HIB+" internally crush your bones to a dust.\n"+OFF; 
             magemsg = HIB+target->query_name()+" whimpers as "+HIW+"SONIC WAVES"+HIB+" internally crush "+target->query_possessive()+" bones to a dust.\n"+OFF; 
             break;
}
  tell_object(mage,magemsg);
  tell_object(target,targetmsg);
  mage->remote_say(roommsg,target);
  return 1;
}           