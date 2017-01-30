/*CyberNinja Guild weapon*/
 
#include "/players/llew/closed/ansi.h"
#include "/players/ulath/closed/ninjaweps/wepdefs.h"
#define NINJATO "/players/ulath/closed/ninjaweps/ninjatodaem.c"

object master;
 
inherit "/players/snow/closed/cyber/weapon.c";

reset(arg) {
  int artwc;
  string ninshort;
    ::reset(arg);
  ninshort = "Ninja-To <steel>";
  artwc = -10;
if(!GOB || !ARTR) ninshort = "Ninja-To <rubber>";
if(GOB) { if(ARTR) artwc = (ARTR/3)+1; }
  if(TP->query_level() < 20) {if(artwc > 5) artwc = 5;}
  if(artwc == 3) ninshort = "Ninja-To <titanium>";
  if(artwc == 4) ninshort = "Ninja-To <adamantium>";
  if(artwc == 5) ninshort = "Ninja-To <ether-alloy>";   
  if(artwc > 5) ninshort = "Ninja-To <vortex-forged>";
 
  master = this_player();
 
  if (arg) return;
  set_name("ninja-to");
  set_alt_name("ninjato");
  set_alias("to");
  set_short(ninshort);
  set_long(
     "A deadly CyberNinja Guild weapon, the Ninja-to is a dead-black blade about\n"+
     "3 1/2 feet long with an incredibly keen edge that longs for blood. When\n"+
     "wielded by an expert of the art of Ninjitsu, the Ninja-to becomes less like\n"+
     "a material object, more like death extending from the arm of its wielder.\n");
  set_class(artwc + 12);
  set_weight(2);
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
 
offer_ninjato(arg) {NINJATO->offer_ninjato(arg); return 1;}
weapon_hit() {NINJATO->weapon_hit(); return 1;}
nin_stab() {NINJATO->nin_stab(); return 1;}
nin_gut_punch() {NINJATO->nin_gut_punch(); return 1;}
nin_face_smash() {NINJATO->nin_face_smash(); return 1;}
nin_multi_hit() {NINJATO->nin_multi_hit(); return 1;}
r_attack() {NINJATO->r_attack(); return 1;}
nin_head_slap() {NINJATO->nin_head_slap(); return 1;}
nin_back_strike() {NINJATO->nin_back_strike(); return 1;}
nin_throat_blow() {NINJATO->nin_throat_blow(); return 1;}
nin_aura() {NINJATO->nin_aura(); return 1;}
nin_finish() {NINJATO->nin_finish(); return 1;}

