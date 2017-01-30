
#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
inherit "/players/vertebraker/closed/std/room";
reset(arg) {
   if(arg) return;
   short_desc=(RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint ");
   set_light(0);
   set_chance(100);
   add_msg("The waves crash against the rocks...");
   add_msg("The sound of the sea drowns out all other noise ...");
   add_msg("The mist encloses you, clinging to your flesh....");
   add_msg("The jagged rocks rise up before you....");
   add_listen("main","You hear the sound of the sea crashing on the rocks.");

}


