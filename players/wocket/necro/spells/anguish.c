#include "../defs.h"

cmd(str){
int cost,dam;
object ob, att;
string caster_msg,target_msg,room_msg;
dam = random(40)+5;
ob = GOB;
  if(!ob) return 0;
  if(!GOB->checklev(4,10)) return 1;
  if(tp->query_spell_dam()){ 
    notify_fail("");
    return 0;
  }
  if(!str){
    if(tp->query_attack()){
      att = tp->query_attack(); 
    }
    else { 
      notify_fail("Who would you like to suffer the pains of anguish?\n"); 
      return 0;
    }
  }
  else{ 
    att = present(str, environment(tp));
  }
  cost = 15;
  if(tp->query_sp() < cost) { 
    notify_fail("You do not have the spell points available for this spell.\n");
    return 0;
  }
  if((ob->query_blood()) < 1) {
    write("You do not have the spell components available for the spell.\n");
  return 0;
  }
  if(!att){
    notify_fail("There is no "+str+" here to suffer anguish.\n"); 
    return 0;
  }
  if(!att->is_npc() && !att->is_player()){
    notify_fail("That is not something you can attack.\n");
    return 0;
  }
  ob->add_val(1);
  ob->add_blood(-1);
  ob->save_me();
  caster_msg="You take a vial of blood and crush in in your hand as you stare\n"+
        "at "+att->query_name()+" intently.  "+capitalize(att->query_pronoun())+" crumples in anguish.\n";
  target_msg=tp->query_name()+" stares at you.  You crumple in anguish.\n";
  room_msg=tp->query_name()+" crushes a vial of blood in "+tp->query_possessive()+" hand.\n"+
           att->query_name()+" crumples in anguish.\n";
  say(tp->query_name() +" throws a glowing sphere at "+att->query_name()+".\n");
  if(BLOODMOON) {
    caster_msg+=ROD+"The Bloodmoon increases the power of your spell.\n";
    dam+= 3; 
  }
  if(GRAVESITE) {
    caster_msg+=ROD+"The Graveyard increases the power of your spell.\n";
    dam+= 2; 
  }
  tp->add_hit_point(-10);
  tp->spell_object(att,"anguish", dam, cost, caster_msg, target_msg, room_msg);
  tp->set_spell_dtype("other|evil");
return 1;
}

