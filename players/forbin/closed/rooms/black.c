#include "/players/forbin/define.h"

inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(!present("display")) 
    move_object(clone_object("/players/cosmo/hslist/svds_new.c"), this_object());
  if(arg) return;
  long_desc = 
    BBLK+HIW+"                                          \n"+NORM+  
    BBLK+HIW+"            [ The Black Room ]            \n"+NORM+
    BBLK+HIW+"                                          \n"+NORM;
  set_light(1);
  no_exit_display = 1;
}

short() {
  return HIK+"The Black Room"+NORM;
 }
