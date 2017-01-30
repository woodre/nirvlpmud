/*
A shadow for increasing damage
Used by Skull of Mantuok
*/
#include "defs.h"

object target;

start_shadow(targ) {
  shadow(targ,1);
  target=targ;
  call_out("stop_shadow",60);
}

stop_shadow() {
  shadow(target,0);
  destruct(this_object());
}

short() {
  return target->short()+" ("+HIM+"cursed"+NORM+")";
}

hit_player(x) {
  return target->hit_player(x+random(5));
}

heal_self(x) {
  return target->heal_self(x+random(5));
}

query_cursed() { return 1; }

