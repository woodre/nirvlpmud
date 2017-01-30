/*CyberNinja Guild weapon*/
 
#include "color.h"
#include "wepdefs.h"
#define HANDS "/players/snow/closed/cyber/handsdaem.c"

inherit "/players/snow/closed/cyber/weapon.c";

object master;

 reset(arg) {
  int artwc;
    ::reset(arg);
  if(!this_player()) return;
artwc = -10;
if(ARTR) artwc = ARTR/2 + 6;
 
master = this_player();
 
    if (arg) return;
    set_name("CyberNinjaHands");
    set_class(artwc);
    set_weight(0);
    set_hit_func(this_object());
  call_out("wep_beat",5);
}
 
wep_beat() {
  object myenv;
  myenv = environment(TO);
  if(!myenv) return 1;
  if(!master) { destruct(TO); return 1; }
  if(myenv != master && myenv->is_player() && TO->wielded()) {
    myenv->stop_wielding(); destruct(TO); return 1; }
  if(!myenv->is_player()) destruct(TO);
  call_out("wep_beat",25);
  return 1;
}
 
side() {HANDS->side(); return 1;}
offer_hands() {HANDS->offer_hands(); return 1;}
weapon_hit() {HANDS->weapon_hit(); return 1;}
hands_jab() {HANDS->hands_jab(); return 1;}
hands_leg_sweep() {HANDS->hands_leg_sweep(); return 1;}
hands_kick() {HANDS->hands_kick(); return 1;}
hands_multi_hit() {HANDS->hands_multi_hit(); return 1;}
r_attack() {HANDS->r_attack(); return 1;}
hands_head_smash() {HANDS->hands_head_smash(); return 1;}
hands_strike() {HANDS->hands_strike(); return 1;}
hands_throat_blow() {HANDS->hands_throat_blow(); return 1;}
hands_aura() {HANDS->hands_aura(); return 1;}
hands_finish() {HANDS->hands_finish(); return 1;}
