#include "../../defs.h"
int corpses;

id(str) { return str == "necro_corpse_check"; }

long() {
write("How are you looking at this?  Contact Wocket imediately!\n");
}

reset(arg) { 
  corpses = random(4);
  if(arg) return;
}

get(){ return 1; }

query_weight(){ return 400; }

query_corpses(){ return corpses; }

add_corpses(i) {
  corpses = corpses+i;
  return 1;
}

