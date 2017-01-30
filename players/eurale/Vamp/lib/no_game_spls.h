/*
  change your login awakening
*/

#include "/players/eurale/defs.h"

no_game_spls() {
if(!present("vampire fangs",TP)) return 0;
write(HIR+
  "As a Vampire, you cannot use that ability.\n"+NORM);
TP->save_me();
return 1; }
