/*
  emit_mist.h
*/

#include "/players/eurale/defs.h"

/* -------- Emit a mist that makes it dark ---------- */
dispell_vampmist(str) {
if(!str || str != "mist") return 0;

if(EFANGS->query_vampire_mist() == 0) {
  write("No vampire mist surrounds you.\n");
  return 1; }

EFANGS->set_vampire_mist(0);
TP->set_ac(TPAC - 1);
TP->set_wc(TPWC - 1);
EFANGS->tell_my_room(HIR+
  "The red mist clears revealing "+capitalize(TPRN)+"."+NORM+"\n");
write(HIR+"You dissipate your vampire mist."+NORM+"\n");
return 1;
}
