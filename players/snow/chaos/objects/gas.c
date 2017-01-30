/* Gas object */

#include "/players/snow/chaos/defs.h"

id(str) { return str == "gasobj"; }
long() { write("Gas...\n"); RE; }

reset() {
  call_out("gas_effect",3);
  call_out("gas_swirl",random(30));
}

drop() { RE; }
get() { RE; }

gas_effect() {
  object ob;
  call_out("gas_effect",random(10)+5);
  ob = first_inventory(environment(TO));
  while(ob) {
    ob->add_hit_point(-random(12) - 1);
    if(random(20) < 4) TE(ob,"The gas is slowly killing you!\n");
    ob = next_inventory(ob);
  }
  RE;
}

gas_swirl() {
  TR(ENV(TO),"  The gas swirls slowly about the room...\n");
  call_out("gas_swirl",random(30));
  RE;
}
