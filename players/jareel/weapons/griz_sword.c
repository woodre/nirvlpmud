#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
  if(arg) return;
  ::reset(arg);

set_alt_name("sword");
set_alias("bastard sword");
set_id("bastard sword");
set_name(HIK+"Bastard sword"+NORM);

set_long(
  "This finely crafted bastard sword, forged from the rune metal iron.\n"+
  "Blood runnels run the length of the blade, to drain off the blood of\n"+
  "its victims.  The hilt of the sword has a small inscription.\n");
  
  set_class(18);
  set_type("sword");
  set_weight(2);
  set_value(1500);
  set_read(BOLD+YEL+"Forged at Ye Ole Smithy[TM]\n"+NORM);
  set_hit_func(this_object());
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
write(BOLD+"The bastard sword makes you stronger.\n"+
  "Your bastard sword plunges deep into "+ob->query_name()+"!\n"+NORM);
  say(me->query_name()+"'s bastard sword plunges deep into "+ob->query_name()+"!\n");
  ob->add_spell_point(-random(12)+5);
  me->add_spell_point(random(2)+5);
  return 7;
}
}
