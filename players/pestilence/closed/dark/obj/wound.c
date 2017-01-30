/* borrowed from the great Eurale */
#include "/players/pestilence/ansi.h"
#include "/players/pestilence/define.h"
#define ETO environment(this_object())
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("do_infection");
    set_weight(0);
    set_value(0);
call_out("poison_player",15);
}


poison_player() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
tell_room(environment(environment(this_object())), ""+YEL+"Puss"+NORM+" flows from "+USER->query_name()+"'s "+HBYEL+"INFECTION"+NORM+".\n");
    if(ETO->is_npc() || interactive(ETO))  
    ETO->do_damage(({10 + random(10)}), ({"other|poison"}));
    call_out("poison_again2",10);
    return 1; }
  }
}

poison_again2() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
tell_room(environment(environment(this_object())), ""+YEL+"Puss"+NORM+" flows from "+USER->query_name()+"'s "+HBYEL+"INFECTION"+NORM+".\n");
    if(ETO->is_npc() || interactive(ETO)) 
    ETO->do_damage(({10 + random(10)}), ({"other|poison"}));
    call_out("poison_again3",10);
    return 1; }
  }
}

poison_again3() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
tell_room(environment(environment(this_object())), ""+YEL+"Puss"+NORM+" flows from "+USER->query_name()+"'s "+HBYEL+"INFECTION"+NORM+".\n");
    if(ETO->is_npc() || interactive(ETO)) 
    ETO->do_damage(({10 + random(10)}), ({"other|poison"}));
    call_out("poison_again",20);
    return 1; }
  }
}
poison_again() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
tell_room(environment(environment(this_object())), ""+YEL+"Puss"+NORM+" flows from "+USER->query_name()+"'s "+HBYEL+"INFECTION"+NORM+".\n");
    if(ETO->is_npc() || interactive(ETO)) 
    ETO->do_damage(({10 + random(10)}), ({"other|poison"}));
    call_out("poison_leave",60);
    return 1; }
  }
}

poison_leave() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
tell_room(environment(environment(this_object())),""+USER->query_name()+"'s infection scabs over.\n");
    if(ETO->is_npc() || interactive(ETO)) 
    ETO->do_damage(({10 + random(10)}), ({"other|poison"}));
    destruct(this_object());
    return 1; }
  }
}

drop() { return 1; }
extra_look() {
write(environment()->query_name()+" has a "+YEL+"puss "+NORM+"filled Infection.\n");
}


long() {
  write("A "+YEL+"puss "+NORM+"filled Infection.\n");
}
