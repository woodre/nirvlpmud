#include "/players/jareel/ansi.h"
#define CO call_other

inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
  if(arg) return;

  set_name(BOLD+"Grandor, Great Hammer"+NORM);
  set_class(19);
  set_weight(2);
  set_value(4000);
  set_type("hammer");
  set_alias("grandor");
  set_alt_name("great hammer");
  set_short(BOLD+"Grandor, Great Hammer"+NORM);
  set_long(
    "This great hammer is enchanted with a mystic power to make it light as a feather.\n"+
    "The mystic force seems to have taken away from its combat effectivness, maybe\n"+
    "it has a special use.\n");

/* converted to use params - illarion 6/5/2010
  set_hit_func(this_object());
*/
  set_params("other|fire",0,"fire_hit");
}

query_wear() {
  return 1;
}

weapon_breaks() {
  return 1;
}

fire_hit(ob){
  int pain;
  object me;
  me = wielded_by;
  if(!me) me = environment();
  if(!me) return;
  if(!living(me)) return;
  if(!ob) return;
    pain = random(3);
      if(pain==2){
        write(BOLD+me->query_name()+"'s hammer unleashes a "+GRN+"M Y T H I C"+HIW+" blast of Heat burning its foe.\n"+NORM);
        say(BOLD+me->query_name()+"'s hammer unleashes a "+GRN+"M Y T H I C"+HIW+" blast of Heat burning its foe.\n"+NORM);
  return 6;
}}
