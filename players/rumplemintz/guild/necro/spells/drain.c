/* 
Guild Level 3 - Neg heal attack spell plus slight healing.
   healing effect symulates necro taking lifeforce as thier own.
   TotalCost - 40 sp (20 sp, 1 Eye)
*/
#include "../defs.h"
int heal;

cmd(str) {
int dam;
string caster_msg,room_msg,target_msg;
object ob, att;

  dam = 5+random(27);
  heal = dam;
  ob = GOB;
  if(tp->query_spell_dam()){
    notify_fail("");
    return 0;
  }
  if(!GOB->checklev(3,7)) return 1;
  if(!str) {
    if(tp->query_attack()){
      att = tp->query_attack(); 
    }
    else{ 
      notify_fail("Who would you like to drain?\n"); 
      return 0; 
    }
  }
  else{
    att = present(str, environment(this_player()));
  }
  if(!att){
    notify_fail("There is no "+str+" here to drain.\n"); 
    return 0;
  }
  if(!att->is_npc() && !att->is_player()){
    notify_fail("That is not something you can attack.\n");
    return 0;
  }
  if(tp->query_sp() < 20) {
    notify_fail("You do not have the spell points available for this spell.\n");
    return 0; 
  }
  if(ob->query_eye() < 1){
    notify_fail("You do not have the spell components available for the spell.\n");
    return 0;
  }

  ob->add_val(1);
  ob->add_eye(-1);
  caster_msg = "You pull out an eye from your pouch.  As you squeeze it "+att->query_name()+" falls\n"+
               "to the ground in pain.\n";
  room_msg = tpn+" squezes an eye from "+tpp+" pouch.\n"+att->query_name()+" buckles over in pain.\n";
  target_msg = "As "+tpn+" squeeze an eye from "+tpp+" pouch your stomach squeezes and you\nfeel the life drain out of you.\n";
  if(BLOODMOON){
    dam += 1;
    heal += 1;
  caster_msg+=ROD+"Your spell grows stronger by the presence of the BloodMoon\n";
  }
  if(GRAVESITE) {
    caster_msg+=ROD+"The Graveyard increases the power of your spell.\n";
    dam += 2; 
    heal += 1;
  }
  call_out("get_life",1,({tp, att}));
  dam *= 90; dam /= 100;
  tp->spell_object(att,"drain", dam, 20, caster_msg, target_msg, room_msg);
  tp->set_spell_dtype("other|evil");
return 1; }


get_life(arg){
  tell_room(environment(arg[0]),HIM+"A purple mist rises and "+arg[0]->query_name()+" seems to become stronger.\n"+OFF);
  if(arg[1]->is_player() && present(arg[1], environment(arg[0])))
  {
    arg[0]->add_hit_point((heal / (1+random(4))));
  }
  else
  {
    arg[0]->add_hit_point(heal);
  }
  return 1;
}
