#include "/players/forbin/define.h"

#define RCD "/players/forbin/closed/rooms/cycle.c"

inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(arg) return;
  long_desc = 
    HBWHT+HIK+"                                          \n"+NORM+  
    HBWHT+HIK+"            [ The White Room ]            \n"+NORM+
    HBWHT+HIK+"                                          \n"+NORM;
  set_light(1);
  no_exit_display = 1;
  add_exit("/room/void.c","out");
}

short() {
  return HIW+"The White Room"+NORM;
 }

query_dont_clean_obs_here() { return 1; }
