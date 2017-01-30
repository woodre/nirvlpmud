#include "../defs.h"
/* sp15 + 3skins(24) = 39sp */
/* changed from 3skins to 2skin 4 blood  10/15/01 */
/* changed back 10/23/01 */
cmd(str){
int cost,dam;
object ob,att;
string caster_msg,target_msg,room_msg;
ob = GOB;
  if(!ob) return;
  if(!GOB->checklev(7,13)) return 1;
  if(tp->query_spell_dam()){ 
    notify_fail("");
    return 0;
  }
  if(!str){
    if(tp->query_attack()) att = tp->query_attack();
    else{
      notify_fail("Who would you like to decay?\n");
      return 0; 
    } 
  }
  else{
    att = present(str, environment(tp)); 
  }
  if(str == "corpse") return corpsedecay();
  if(!att){
    notify_fail("There is no "+str+" here to decay.\n"); 
    return 0; 
  }
  if(!att->is_npc() && !att->is_player()){
    notify_fail("That is not something you can attack.\n");
    return 0;
  }
  cost = 15;  dam = 15+random(48);
  if(tp->query_sp() < cost) {
    write("You do not have the spell points available for this spell.\n");
    return 1; }
  if(ob->query_skin() < 3) {
    write("You do not have the spell components available for the spell.\n");
    return 1; }
  ob->add_val(1);
  ob->add_skin(-3);
  ob->save_me();
  caster_msg = "You wrap your hands in the decaying flesh of others.  Maggots begin to\n"+
               "crawl across your skin as you whisper the word \"decay\".  Your hands glow\n"+
               "as you reach and grab "+att->query_name()+".\n"+
               "Maggots begin to eat away at the flesh as "+att->query_name()+" begins to decay.\n";
  room_msg = tpn+" reaches out and grabs "+att->query_name()+".\n";
  target_msg = "Maggots flood across your body eatting away at your bubbling flesh as\n"+
               tpn+" grabs you.  "+capitalize(tp->query_possessive())+" hands covered in decaying skin.\n";
  if(BLOODMOON) {
    caster_msg+=ROD+"The Bloodmoon increases the power of your spell.\n";
    dam+= 3; 
  }
  if(GRAVESITE) {
    caster_msg+=ROD+"The Graveyard increases the power of your spell.\n";
    dam+= 2; 
  }
/* Again with the 90 percent?? Removed.  - Rumplemintz
  dam *= 90; dam /= 100;
*/
  tp->spell_object(att,"decay", dam, cost, caster_msg, target_msg, room_msg);
  tp->set_spell_dtype("other|evil");
return 1;
}

corpsedecay(){
  write("Not implimented yet.\n");
  return 1;
}  
