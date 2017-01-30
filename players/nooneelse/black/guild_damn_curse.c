/*
 guild_curse.c
*/

object who_obj;
int damage_amount;


drop() { return 0; }

start_curse() {
  call_out("effect_1", 9);
}

effect_1(arg) {
  if(!environment() || !living(environment()) ) return;
  if(environment()->query_ghost()) return;
  who_obj = environment(this_object());
  if(!who_obj) 
  {
    destruct(this_object());
return 1; }
  damage_amount=5;
  damage_the_target();
  if (living(who_obj))
    call_out("effect_2", 5);
  else
  {
    destruct(this_object());
  return 1; }
}

effect_2(arg) {
  if(!environment() || !living(environment()) ) return;
  if(environment()->query_ghost()) return;
  who_obj = environment(this_object());
  if(!who_obj) 
    destruct(this_object());
  damage_amount=5;
  damage_the_target();
  if (living(who_obj))
    call_out("effect_3", 10);
  else
    destruct(this_object());
}

effect_3(arg) {
  if(!environment() || !living(environment()) ) return;
  if(environment()->query_ghost()) return;
  who_obj = environment(this_object());
  if(!who_obj) 
    destruct(this_object());
  damage_amount=5;
  damage_the_target();
  if (living(who_obj))
    call_out("effect_4", 10);
  else
    destruct(this_object());
}

effect_4(arg) {
  if(!environment() || !living(environment()) ) return;
  if(environment()->query_ghost()) return;
  who_obj = environment(this_object());
  if(!who_obj) 
  destruct(this_object());
  damage_amount=5;
  damage_the_target();
  destruct(this_object());
}

damage_the_target() {
  if(!who_obj) 
  {
  destruct(this_object());
  return 1;}
  if(!who_obj->query_attack()) { destruct(this_object()); return 1; }
  if (who_obj->query_hp() > damage_amount) {
    if (who_obj->query_npc()) {
   if(who_obj)
      who_obj->heal_self(-damage_amount);
    }
    else {
  /*
      who_obj->add_hit_point(- damage_amount);
      who_obj->add_spell_points(- damage_amount);
   took out cause this is pk oriented
  mythos <3-4-1999>
*/
    }
  }
  if(!who_obj) destruct(this_object());
  if(!environment(who_obj)) return 1;
  tell_room(environment(who_obj),
      "\nA small bat flys in and attaches itself to "+
      capitalize(who_obj->query_name())+" neck!\n"+
      capitalize(who_obj->query_name())+
      " looks weaker every second!  The bat flys away.\n\n"+
      "Did that really happen or was it a dream?\n\n");
}

id(str) { return str=="vamp curse" || str=="curse"; }

init() {
  if(this_player()) if(environment())
   if(this_player() != environment(this_object())) destruct(this_object());
}
