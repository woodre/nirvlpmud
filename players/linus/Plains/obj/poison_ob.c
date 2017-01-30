#include "/players/linus/def.h"
inherit "/obj/treasure.c";
reset(arg) {
 if(arg) return;
 set_id("poison");
 set_weight(0);
 set_alias("poison");
 set_value(0);
 call_out("you_gonna_die",10);
}
you_gonna_die() {
 if(ENV(TO)) {
  if(living(ENV(TO))) {
 tell_object(ENV(TO), "Your skin starts oozing a smelly "+GRN+"puss"+NORM+"\n");
 if(interactive(ENV(TO)));
 ENV(TO)->hit_player(10+random(30));
 call_out("you_gonna_die",20);
 return 1;
  }
 }
}
drop() {
 if(ENV()->is_dieing()) destruct(TO);
 else return 1; 
}
get() { return 0; }
can_put_and_get() { return 0; }
