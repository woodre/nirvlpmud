/*
  cancel_summons.h
*/

#include "/players/eurale/defs.h"

/* -------- Cancel a summons  ---------- */
cancel_summons(str) {
  object obj;
  if (!str) return 0;
  obj = find_player(str);

if(!obj) {
  write("I can't find "+capitalize(str)+".\n");
  return 1; }

obj = present("vampire summons", obj);
if(!obj) {
  write(capitalize(str)+" doesn't have a summons.\n");
  return 1; }

destruct(obj);
write(HIR+"Summons to "+capitalize(str)+" canceled.\n"+NORM);
return 1;
}
