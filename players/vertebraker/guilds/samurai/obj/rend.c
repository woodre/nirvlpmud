#include "../def.h"

int r;
int beats;

id(str) {
 return str=="rend_object" || str=="poison";
}

load_it(rank){
  r = rank;
  beats = rank;
  set_heart_beat(1);
}

drop() { return 1; }

heart_beat()
{
  if(!ENV() || !living(ENV()) || ENV()->query_ghost() || beats <=0 ) 
    return destruct(this_object());
  tell_object(ENV(), HIR+"Your wound bleeds profusely!\n"+NORM);
  tell_room(ENV(ENV()),
    HIR+ENV()->QN+"'s wound pours out blood.\n"+NORM);
/* This spell was ineffcient at low levels, and illegal at high levels:
  30 sp for approx 90 random pts of damage at glev 10.  new cost will 
  be glev*glev/2 for roughly glev*glev/2 pts of random direct damage.
   - ill 6.17.2010
   */
  ENV()->hit_player(1+random(r/2), "other|blood");
  beats--;
}
