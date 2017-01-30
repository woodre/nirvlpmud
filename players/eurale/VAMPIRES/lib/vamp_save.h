/*
  Vampire save
*/

#include "/players/eurale/defs.h"

vamp_save() {

write(HIR+"Saving Vampire Information...\n"+NORM);
PFANGS->add_BLOODPTS(0);
write("Saving player information...\n");
TP->save_me();
return 1;
}
