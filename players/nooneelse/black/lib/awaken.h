/*
  change your login awakening
*/

#include "defs.h"
#define TP this_player()

awaken() {
if(!present("nooneelse@vampire@fangs",TP)) return 0;
TP->add_spell_point(-10);
if(TP->query_home() == "/room/church.c" ||
   TP->query_home() == "room/church.c" ||
   TP->query_home() == "/room/church" ||
   TP->query_home() == "room/church") {
  call_other(TP,"set_home","/players/eurale/VAMPIRES/RMS/vguild_hall.c");
  TP->save_me();
  write("You will now AWAKEN in the "+HIR+"Guild Hall"+NORM+".\n");
  return 1; }
write("You will now AWAKEN in the "+BOLD+"Church"+NORM+".\n");
call_other(TP,"set_home","/room/church.c");
TP->save_me();
return 1; }
