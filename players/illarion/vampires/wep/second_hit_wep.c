#include "../def.h"
object usr;
object gob;

drop() { return 1; }
get() { return 1; }

id(str) { return str=="vamp_second_hit"; }

setup(u, g)
{
  usr = u;
  gob = g;
}

init() {
  if(!usr || !gob || ETO != usr)
    destruct(TO);
}

vamp_extra_hit(att) {
  return COMDAEM->extra_attack_bonus(usr, TO, att);
}

query_message_hit(dam) {
  return COMDAEM->extra_attack_message_hit(dam, usr, gob);
}
