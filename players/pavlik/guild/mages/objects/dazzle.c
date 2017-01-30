#include <ansi.h>

reset(arg) {
 if(arg) return;
  return;
}

short() { return "Dazzle!\n"; }
long() { write("Dazzle!\n"); return; }
query_value(){ return 0; }
get(){ return 0; }
drop(){ return 1; }

id(str) {
  return str == "no_msg_hit" || str == "no_weapon_attack" || str == "dazzle";
}


