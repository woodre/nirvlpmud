#include "/players/feldegast/defines.h"

inherit "/obj/monster";

object victim;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tangle vine");
  set_alt_name("vine");
  set_short(HIG+"Tangle Vine"+NORM);
  set_long(
"This is a thick, green tangle of vines, sprouting up out of the\n\
ground with its lithe green tendrils.\n"
  );
  set_race("plant");
  set_level(5);
  set_wc(1);
  set_ac(5);
  set_hp(250); /* High hp for low wc and limited duration */
  set_al(0);  
  set_a_chat_chance(5);
  load_a_chat(HIG+"The tangle vine GROWS.\n"+NORM);
  load_a_chat("The tangle vine wraps around its target.\n");
  set_dead_ob(this_object());
  call_out("die",8);
}
die() {
  if(!attacker_ob && victim && present(victim,environment(this_object())) ) {
    victim->attacked_by(this_object());
    this_object()->attacked_by(victim);
  }
  if(!attacker_ob) {
    tell_room(environment(this_object()),"The tangle vine withers and dies.\n");
    destruct(this_object());
  }
  else {
    tell_object(attacker_ob,HIG+"The tangle vine holds you in its grip!\n"+NORM);
    call_out("die",8);
  }
}
monster_died(ob) {
  tell_room(environment(this_object()),
GRN+"The tangle vine retreats back into the ground.\n"+NORM);
}
heartbeat() {
  ::heartbeat();
  if(attacker_ob) victim=attacker_ob;
}
