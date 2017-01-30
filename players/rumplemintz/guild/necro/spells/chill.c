/* 
Guild Level 1 - basic attack spell
TotalCost -> 12 spell points (10 sp + 1 blood)
*/

#include "../defs.h"


cmd(str) {
int dam;
object ob, att;
string caster_msg,target_msg,room_msg;
  dam = 4 + random(15);
  ob = GOB;
  if(tp->query_spell_dam()){
    notify_fail("");
    return 0;
  }
  if(!str){
    if(tp->query_attack()) att = tp->query_attack();
    else{
      notify_fail("Who would you like to touch?\n");
      return 0; 
    } 
  }
  else{
    att = present(str, environment(tp)); 
  }
  if(!att){
    notify_fail("There is no "+str+" here to touch.\n"); 
    return 0; 
  }
  if(!att->is_npc() && !att->is_player()){
    notify_fail("That is not something you can attack.\n");
    return 0;
  }
  if(tp->query_sp() < 10) {
    write("You do not have the spell points available for this spell.\n");
    return 1; }
  if((ob->query_blood()) < 1) {
    write("You do not have the spell components available for the spell.\n");
    return 1; }
  ob->add_val(1);
  ob->add_blood(-1);
  ob->save_me();
  caster_msg = "You draw power from the Realm of Death with your sacrifice of blood.\n"+
               "You reach out and touch "+att->query_name()+" with chilling hands.\n";
  room_msg = tpn+" reaches out and touches "+att->query_name()+".\n";
  target_msg = tpn+" reaches out and touches you with chilling hands.\n";
  if(BLOODMOON) {
    caster_msg+=ROD+"The Bloodmoon increases the power of your spell.\n";
    dam+= 3; 
  }
  if(GRAVESITE) {
    caster_msg+=ROD+"The Graveyard increases the power of your spell.\n";
    dam+= 2; 
  }
  dam *= 90; dam /= 100;
  tp->spell_object(att,"chill", dam, 10, caster_msg, target_msg, room_msg);
  tp->set_spell_dtype("other|evil");
return 1;
}
