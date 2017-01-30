#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("flowing scarf");
   set_alias("scarf");
   set_short(HIR+"A Flowing Scarf"+NORM);
   set_long(
      "This scarf is made from superman's cape. It is bright red and\n\
flows like the wind. This scarf is EMPOWERED!\n");
   set_ac(1);
   set_type("scarf");
   set_weight(1);
   set_value(1000);
}

do_special(owner){
  if(!worn) return;
  if (!owner || !owner->query_attack())
    return; /* 06/25/06 Earwax */
  if(random(20) < 4)
  {
    tell_object(owner,
      "You are lifted off the ground!\n"+  
      "     You feel "+HIW+"E M P O W E R E D"+NORM+"!!!\n");
    tell_room(environment(owner),
      owner->query_name()+" BLASTS "+owner->query_attack()->short()+" with Super Strength!!!\n", ({ owner }));
    owner->add_hit_point(random(5));
    return 1;
  }
  return;
}
