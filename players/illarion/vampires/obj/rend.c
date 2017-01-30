#include "../def.h"
/* TODO - vary damage based on vampire, vary message based on damage */

int r, beats;

id(str) {
  return str=="vampire_rend" || str=="poison";
}

add_duration(rank){
  if(rank > r)
    r = rank;
  if(rank > beats)
    beats = rank;
  set_heart_beat(1);
}

drop() { return 1; }

heart_beat()
{
  if(beats <= 0 || !ETO || !living(ETO) || ETO->query_ghost()) 
    return stop_bleeding();
  tell_object(ETO, HIR+"You are bleeding!\n"+NORM);
  tell_room(ENV(ETO),DAEM->emote("$HR$#MN# bleeds from #MP# wounds.\n$N$", ETO), ({ENV(ETO)}));
  ETO->do_damage(({1+random(r/4)}), ({"other|blood"}));
  beats--;
}

stop_bleeding() {
  if(ETO && living(ETO))
  {
    tell_object(ETO, "You stop bleeding.\n");
    tell_room(ENV(ETO),DAEM->emote("$HW$#MN# stops bleeding.\n$N$", ETO), ({ENV(ETO)}));
  }
  destruct(TO);
}