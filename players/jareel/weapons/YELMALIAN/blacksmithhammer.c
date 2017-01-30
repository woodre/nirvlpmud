#include "/players/jareel/ansi.h"
#define CO call_other

inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
  if(arg) return;

  set_name(HIY+"Sunspot, "+NORM+"A "+HIY+"Yelm"+NORM+" Sunfire Hammer"+NORM);
  set_class(19);
  set_weight(2);
  set_value(4000);
  set_type("hammer");
  set_alias("sunspot");
  set_alt_name("sunfire hammer");
  set_name(HIY+"Sunspot, "+NORM+"A "+HIY+"Yelm"+NORM+" Sunfire Hammer"+NORM);
  set_long(
    "This great hammer is enchanted with a mystic power to make it light as a feather.\n"+
    "The mystic force seems to have taken away from its combat effectivness, maybe\n"+
    "it has a special use.\n");

  set_hit_func(this_object());
}

query_wear() {
  return 1;
}

weapon_breaks() {
  return 1;
}

weapon_hit(ob){
  int pain;
  object me;
  me = wielded_by;
  if(!me) me = environment();
  if(!me) return;
  if(!living(me)) return;
  if(!ob) return;
    pain = random(3);
      if(pain==2){
        write(BOLD+me->query_name()+"'s hammer unleashes "+HIY+"S U N F I R E"+HIW+" blast of Heat burning its foe.\n"+NORM);
        say(BOLD+me->query_name()+"'s hammer unleashes "+GRN+"S U N F I R E"+HIW+" blast of Heat burning its foe.\n"+NORM);
  return 6;
}}
