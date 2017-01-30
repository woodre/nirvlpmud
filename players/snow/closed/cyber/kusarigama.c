/*CyberNinja Guild weapon*/
 
#include "color.h"
#include "wepdefs.h"
#define KGAMA "/players/snow/closed/cyber/kgamadaem.c"

inherit "/players/snow/closed/cyber/weapon.c";

object master;
int totaldam;
query_totaldam() { return prof; }
set_totaldam(num) { prof = num; }
mod_totaldam(num) { prof += num; }

 reset(arg) {
  int artwc;
  string ninshort;
    ::reset(arg);
ninshort = "A Kusari-Gama <steel>";
artwc = -10;
if(!ARTR) ninshort = "Kusari-Gama <rubber>";
if(ARTR) artwc = (ARTR/3)+1;
if(TP->query_level() < 20) {if(artwc > 6) artwc = 6;}
if(artwc == 3) ninshort = "Kusari-Gama <titanium>";
if(artwc == 4) ninshort = "Kusari-Gama <adamantium>";
if(artwc > 4) ninshort = "Kusari-Gama <ether-alloy>";
if(artwc > 6) ninshort = "Kusari-Gama <vortex-forged>";
 
master = this_player();
 
    if (arg) return;
    set_name("kusarigama");
    set_alt_name("kusari");
    set_alias("gama");
    set_short(ninshort);
    set_long(
"A short scythe converted to a finely-honed weapon with the addition of\n"+
"a weighted chain make the Kusari-Gama a feared weapon of the CyberNinjas.\n");
    set_class(artwc + 10);
    set_weight(1);
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
 
offer_kgama(arg) {KGAMA->offer_kgama(arg); return 1;}
weapon_hit() {KGAMA->weapon_hit(); return 1;}
gama_slice() {KGAMA->gama_slice(); return 1;}
kusari_tangle() {KGAMA->kusari_tangle(); return 1;}
kusari_whip() {KGAMA->kusari_whip(); return 1;}
kgama_multi_hit() {KGAMA->kgama_multi_hit(); return 1;}
r_attack() {KGAMA->r_attack(); return 1;}
gama_chop() {KGAMA->gama_chop(); return 1;}
kgama_tangle_chop() {KGAMA->kgama_tangle_chop(); return 1;}
kgama_neck_rip() {KGAMA->kgama_neck_rip(); return 1;}
kgama_aura() {KGAMA->kgama_aura(); return 1;}
kgama_finish() {KGAMA->kgama_finish(); return 1;}

