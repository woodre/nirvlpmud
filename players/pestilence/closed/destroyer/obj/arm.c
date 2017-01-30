#include "/players/pestilence/ansi.h"
#include "/players/pestilence/define.h"
#define ETO environment(this_object())
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("arm_ob");
    set_weight(0);
    set_value(0);
call_out("poison_player",2);
}


poison_player() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
tell_room(environment(environment(this_object())), ""+USER->query_name()+" has been armed.\n");
    if(interactive(ETO))
    command("wield",ETO);
    command("wield");
    ETO->hit_player(10 + random(10), "other|poison");
    call_out("poison_leave",10);
    return 1; }
  }
}



poison_leave() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
/*
tell_room(environment(environment(this_object())),""+USER->query_name()+"'s wound dries up and goes away.\n");
*/
    if(interactive(ETO)) 
    ETO->hit_player(10 + random(10), "other|poison");
    destruct(this_object());
    return 1; }
  } 
}

drop() { return 1; }
