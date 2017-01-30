#include "/players/jareel/ansi.h"
#define CO call_other

inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
  if(arg) return;

  set_name(HIK+"Broam, Great Mithril Hammer"+NORM);
  set_class(20);
  set_weight(2);
  set_value(4000);
  set_type("hammer");
  set_alias("broam");
  set_alt_name("great hammer");
  set_short(HIK+"Broam, Great Mithril Hammer"+NORM);
  set_long(
    "This great hammer is forged with a mystic metal Mithril makeing it light as a\n"+
    "feather. The hammer could crush the hardest of skulls.  There is no natural force\n"+
    "that could break this weapon.\n");

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
        write(HIK+me->query_name()+"'s hammer smashes with brute force crushing its foe.\n"+NORM);
        say(HIK+me->query_name()+"'s hammer smashess with brute force crushing its foe.\n"+NORM);
  return 5;
}}
