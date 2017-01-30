/* Spectral Touch replaces Mi for the Necromancers.
   PK sp drain.
   TotalCost - 19 sp (15 sp plus 2 part Blood)   
*/
#include "../defs.h"

cmd(str) {
string caster_msg,target_msg,room_msg;
int dam,spdam;
object ob, att;
  dam = random(5);
  spdam = random(26);
  ob = GOB;
  if(tp->query_spell_dam()){
    notify_fail(""); 
    return 0;
  }
  if(!GOB->checklev(2,5)) return 1;
  if(!str){
    if(tp->query_attack()) att = tp->query_attack();
    else{
      notify_fail("Who would you like to grasp?\n");
      return 0; 
    } 
  }
  else{
    att = present(str, environment(tp)); 
  }
  if(!att){
    notify_fail("There is no "+str+" here to grasp?\n"); 
    return 0; 
  }
  if(!tp->valid_attack(att)){
    notify_fail("That is not something you can attack.\n");
    return 0;
  }
  if(tp->query_sp() < 15) {
    write("You do not have the spell points available for this spell.\n");
    return 1; }
  if((ob->query_blood()) < 2) {
    write("You do not have the spell components available for the spell.\n");
    return 1; }
  ob->add_blood(-2);
  ob->add_val(1);
  caster_msg = "You mumble some incomprehencible words and pour blood at the\n"+
               "feet of "+att->query_name()+".  A "+RED+"red mist"+OFF+" rises from the ground as etheriel hands\n"+
                RED+"GRASP"+OFF+" "+att->query_name()+", taking part of "+att->query_possessive()+" soul.\n";
  target_msg = tpn+" pours blood upon the ground and a "+RED+"red mist"+OFF+" rises up attempting to\n"+
               "pull you under.  You feel weaker as these etheriel hands "+RED+"RIPS"+OFF+" through you.\n";
  room_msg = tpn+" pours blood upon the ground and a red mist rises up attempting to\n"+
               "pull "+att->query_name()+" under.\n";
   if(BLOODMOON) {
    caster_msg+=ROD+"The Bloodmoon increases the power of your spell.\n";
    dam+= 1; spdam+=3;
  }
  if(GRAVESITE) {
    caster_msg+=ROD+"The Graveyard increases the power of your spell.\n";
    spdam+= 2; 
  }
  if(att->query_sp() < spdam){
    att->add_spell_point(att->query_sp(dam));
    caster_msg += att->query_name()+" looks tired.\n";
  }
  else{
    att->add_spell_point(-spdam);
  }
  tp->spell_object(att,"spectral grasp", dam, 15, caster_msg, target_msg, room_msg);
return 1; }
