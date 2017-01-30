/*
  change your login awakening
*/

#include "/players/eurale/defs.h"

awaken() {
if(!present("efangs",TP)) return 0;

if(TPSP < 10) {
  write("You don't have enough magic left.\n");
  return 1; }

TP->add_spell_point(-10);
if(TP->query_home() != "/players/eurale/VAMPIRES/RMS/vguild_hall.c") {
  call_other(TP,"set_home","/players/eurale/VAMPIRES/RMS/vguild_hall.c");
  TP->save_me();
  write("You will now AWAKEN in the "+HIR+"Guild Hall"+NORM+".\n");
  return 1; }
write("Your login to AWAKEN is the "+BOLD+"Vampire Guild Hall"+NORM+".\n");
return 1; }
