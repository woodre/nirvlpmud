#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("death armor");
     set_ac(4);
     set_value(1200);
     set_weight(3);
     set_type("armor");

     set_short(
       "Iron "+BOLD+BLK+"armor"+NORM+" of death");
     set_long(
       "The armor of death are a dull grey with two\n"+
       "inch protruding spikes from all accross the chest.\n"+
       "The small spikes seem like they would pack quite a\n"+
       "wallup if they were to be hit by someone.\n");
}

/* 11/20/05 Earwax - recoded for functionality and clarity */
do_special(owner) {
  int i;

  i = random(10);
  if (!ATT || i != 1)
    return 0;

  if(ATT->is_npc())
    ATT->heal_self(-(random(3)));
  else
    ATT->hit_player(random(3), "other|evil");

  tell_room(environment(USER),
  CAP(ATT->query_name())+" is pierced by the armors death aura.\n\n"+
  ""+ATT->query_name()+" looks wounded.\n");
  return 0;
}
