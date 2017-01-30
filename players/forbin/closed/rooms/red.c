#include "/players/forbin/define.h"

inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(arg) return;
  long_desc = 
    BRED+HIK+"                                          \n"+NORM+  
    BRED+HIK+"             [ The Red Room ]             \n"+NORM+
    BRED+HIK+"                                          \n"+NORM;
  set_light(1);
  no_exit_display = 1;
}

short() {
  return RED+"The Red Room"+NORM;
 }
