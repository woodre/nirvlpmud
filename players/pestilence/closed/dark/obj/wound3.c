/* borrowed from the great Eurale */
#include "/players/pestilence/ansi.h"
#define ETO environment(this_object())
int ac_times;
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("wound");
    set_weight(0);
    set_value(0);
call_out("poison_player",15);
}

long() {
write("A large "+HIR+"bloody"+NORM+" wound.\n");
  }
wounded(){ return 1; }
poison_player() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      ""+HIR+"Blood poors from your open wound"+NORM+".\n");
    if(interactive(ETO))  
    ETO->hit_player(10 + random(10), "other|poison");
    call_out("poison_again2",random(40));
    return 1; }
  }
}

poison_again2() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      ""+HIR+"Blood poors from your open wound"+NORM+".\n");
    if(interactive(ETO)) 
    ETO->hit_player(10 + random(10), "other|poison");
    call_out("poison_again3",random(40));
    return 1; }
  }
}

poison_again3() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      ""+HIR+"Blood poors from your open wound"+NORM+".\n");
    if(interactive(ETO)) 
    ETO->hit_player(10 + random(10), "other|poison");
    call_out("poison_again",random(40));
    return 1; }
  }
}
poison_again() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      ""+HIR+"Blood poors from your open wound"+NORM+".\n");
    if(interactive(ETO)) 
    ETO->hit_player(10 + random(10), "other|poison");
    call_out("poison_leave",60);
    return 1; }
  }
}

poison_leave() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      "Your wound dries up, and heals.\n");
    if(interactive(ETO)) 
    ETO->hit_player(10 + random(10), "other|poison");
    destruct(this_object());
    return 1; }
  }
}

drop() { return 1; }
extra_look() {
write(environment()->query_name()+" has a "+HIR+"bloody"+NORM+" wound.\n");
}

add_ac_times(arg) { ac_times = ac_times + arg; }
query_ac_times() { return ac_times; }
