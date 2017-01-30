/*CyberNinja Guild weapon*/
 
#include "color.h"
#include "wepdefs.h"
#define NAGIN "/players/snow/closed/cyber/nagidaem.c"

inherit "/players/snow/closed/cyber/weapon.c";

object master;

 reset(arg) {
  int artwc;
  string ninshort;
    ::reset(arg);
ninshort = "A Naginata <steel>";
artwc = -10;
if(this_player())
if(GOB) {
if(!ARTR) ninshort = "Naginata <rubber>";
if(ARTR) artwc = (ARTR/3)+1;
if(TP->query_level() < 20) {if(artwc > 5) artwc = 5;}
if(artwc == 3) ninshort = "Naginata <titanium>";
if(artwc == 4) ninshort = "Naginata <adamantium>";
if(artwc == 5) ninshort = "Naginata <ether-alloy>";
if(artwc > 5) ninshort = "Naginata<vortex-forged>";
}
 
master = this_player();
 
    if (arg) return;
    set_name("naginata");
    set_alias("nagi");
    set_short(ninshort);
    set_long(
"A deadly CyberNinja Guild weapon, the Naginata is a polearm about\n"+
"5 1/2 feet long with a razor-edged blade and a stout black staff. When\n"+
"wielded by an expert of the art of Ninjitsu, the Naginata becomes a\n"+
"whirling instrument of destruction.\n");
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
 
offer_naginata(arg) {NAGIN->offer_naginata(arg); return 1;}
weapon_hit() {
NAGIN->weapon_hit(); return 1;
  }
nag_slice() {NAGIN->nag_slice(); return 1;}
nag_leg_sweep() {NAGIN->nag_leg_sweep(); return 1;}
nag_bar_bash() {NAGIN->nag_bar_bash(); return 1;}
nag_multi_hit() {NAGIN->nag_multi_hit(); return 1;}
r_attack() {NAGIN->r_attack(); return 1;}
nag_bar_smash() {NAGIN->nag_bar_smash(); return 1;}
nag_strike() {NAGIN->nag_strike(); return 1;}
nag_throat_blow() {NAGIN->nag_throat_blow(); return 1;}
nag_aura() {NAGIN->nag_aura(); return 1;}
nag_finish() {NAGIN->nag_finish(); return 1;}
 
