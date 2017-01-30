#define ETO environment(this_object())
#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

set_id("hcl");
set_long("hydrochloric acid\n");
set_weight(0);
set_value(0);
/* ld doesn't like callouts in reset in castle preloads -Bp
call_out("Burn_player",15);
*/
}
init() {
  while(remove_call_out("Burn_player") != -1);
  call_out("Burn_player",15);
}

query_auto_load() { return "/players/eurale/Lab/OBJ/acid.c:"; }

Burn_player() {
if(ETO) {
  if(living(ETO)) {
    tell_object(ETO,
      HIR+"Your skin burns like it is on fire..."+NORM+"\n");
    ETO->hit_player(20 + random(19));
    call_out("Burn_player",30);
    return 1; }
  }
}

drop() {
if(environment()->is_dieing()) destruct(this_object());
else return 1; }
get()   { return 0; }
can_put_and_get()  { return 0; }
