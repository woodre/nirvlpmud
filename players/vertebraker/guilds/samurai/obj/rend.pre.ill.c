#include "../def.h"

int r;

id(str) {
 return str=="rend_object" || str=="poison";
}

load_it(rank){
  r = rank;
  set_heart_beat(1);
  call_out("shake_it_off", rank * 3);
}

drop() { return 1; }

heart_beat()
{
  if(!ENV() || !living(ENV()) ) { remove_call_out("shake_it_off"); return destruct(this_object()); }
  tell_object(ENV(), HIR+"Your wound bleeds profusely!\n"+NORM);
  if(ENV()->query_ghost()) return destruct(this_object());
  tell_room(ENV(ENV()),
    HIR+ENV()->QN+"'s wound pours out blood.\n"+NORM);
/* Added min damage of 1 - illarion 6.17.2010 */
  ENV()->hit_player(1+random(r), "other|blood");
}

shake_it_off()
{
  tell_room(ENV(ENV()),
    ENV()->QN+" seems to have recovered from the rend.\n");
  destruct(this_object());
}
