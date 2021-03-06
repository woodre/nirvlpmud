#define ETO environment(this_object())
#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

set_id("scorptox");
set_long("scorpion poison\n");
set_weight(0);
set_value(0);
/* ld doesn't like callouts in reset in castle preloads -Bp
call_out("Hurt_player",15);
*/
}

init() {
  while(remove_call_out("Hurt_player") != -1);
  call_out("Hurt_player",15);
}
query_auto_load() { return "/players/eurale/Lab/OBJ/scorptox.c:"; }

Hurt_player() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(ETO,
      HIG+"You convulse violently....\n"+NORM);
    if(interactive(ETO))
    ETO->hit_player(20 + random(19), "other|poison");
    call_out("Hurt_player",20 + random(20));
    return 1; }
  }
}

drop() {
if(environment()->is_dieing()) destruct(this_object());
else return 1; }
get()   { return 0; }
can_put_and_get()  { return 0; }
