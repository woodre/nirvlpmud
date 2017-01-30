/*
  alchemist_poison.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

object who_obj;
int damage_amount;

reset() {
  enable_commands();
  set_heart_beat(1);
}

drop() { return 0; }

start_curse() {
  call_out("effect_1", 9);
}

effect_1(arg) {
  who_obj = environment(this_object());
  damage_amount=5;
  damage_the_target();
  if (living(who_obj))
    call_out("effect_2", 5);
  else
    destruct(this_object());
}

effect_2(arg) {
  who_obj = environment(this_object());
  damage_amount=10;
  damage_the_target();
  if (living(who_obj))
    call_out("effect_3", 10);
  else
    destruct(this_object());
}

effect_3(arg) {
  who_obj = environment(this_object());
  damage_amount=15;
  damage_the_target();
  if (living(who_obj))
    call_out("effect_4", 10);
  else
    destruct(this_object());
}

effect_4(arg) {
  who_obj = environment(this_object());
  damage_amount=5;
  damage_the_target();
  destruct(this_object());
}

damage_the_target() {
  if (who_obj->query_hp() > damage_amount) {
    if (who_obj->query_npc()) {
      who_obj->hit_player(damage_amount);
    }
    else {
      who_obj->add_hit_point(- damage_amount);
      who_obj->add_spell_points(- damage_amount);
    }
  }
  tell_room(environment(who_obj),
      "\n"+
      capitalize(who_obj->query_name())+" staggers for amoment as if "+
      +who_obj->query_pronoun()+" just took some damage!\n"+
      capitalize(who_obj->query_name())+
      " seems to look weaker every second!\n\n"+
      "Did that really happen or was it a dream?\n\n");
}

id(str) { return str=="guild curse" || str=="curse"; }
