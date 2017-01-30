#include <ansi.h>

reset(arg)
{
  if(arg) return;
  return;
}

short() { return; }
long() { return; }
query_value(){ return 0; }
get(){ return 0; }
drop(){ return 1; }

id(str) {
  return str == "no_combat" || str == "no_msg_hit" || str == "no_weapon_attack";
}

do_no_attack_message(ob){ return 1; }

