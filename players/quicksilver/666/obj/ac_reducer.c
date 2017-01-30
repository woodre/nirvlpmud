#include "/players/quicksilver/666/include/std.h"

int original_ac;

reset(arg) {
     if(!arg) return;
     remove_call_out("query_combat");
     query_combat();
}

get() { return; }

drop() { return; }
   
long() { return; }

short() { return; }

id(str) { return str=="quicksilver_ac_reducer"; }

query_combat() {
     if(!ENVTO->query_attack()) {
          restore_ac();
          destruct(TO);
          return;          
     }
     call_out("query_combat",5);
     return 1;
}

reduce_ac() {
     int ac;
     
     if(!ENVTO || !ENVTO->query_npc()) {
          destruct(TO);
          return;
     }
     original_ac = ac = ENVTO->query_ac();
     if((ac * 2/3) > (ac - 4)) ac = ac * 2/3;
     else ac = ac - 4;
     ENVTO->set_ac(ac);
     query_combat();
     return 1;
}

restore_ac() {
     ENVTO->set_ac(original_ac);
     return 1;
}
