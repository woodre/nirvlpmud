/*CyberNinja Guild weapon- Naginata daemon master*/
 
#include "color.h"
#include "wepdefs.h"
 
weapon_hit() {
    int W;
    MYWEP->set_prof(0);
W = RAN(70)+ RAN(ARTR*5)/2;
  if(GOB->query_attack_mode() == 1) W += 20;
  if(GOB->query_attack_mode() == 2) W -= 40;
  if(GOB->query_weapon() != "naginata") W -=40;
  if(W > 105) {
nag_aura();
     }
  if(W > 70 && W < 106)  {
nag_multi_hit();
     }
  if(W > 60 && W < 71)  {
nag_leg_sweep();
     }
  if(W > 50 && W < 61)  {
nag_bar_bash();
     }
  if(W > 40 && W < 51)  {
nag_slice();
     }
  check_extra();
  ninja_damage(MEAT);
  if(MEAT->query_hp() < ARTR) {
    write("Your "+NAG+" hungers for the kill!\n");
    return (ARTR/3)+1; }
  if(W > 70 && W < 91)  {
    say(
"Fire burns along the blade of "+TPN+"'s "+NAG+".\n");
    write(
"Fire burns along the blade of your "+NAG+".\n");
return ARTR/4;
     }
  if(W > 90)  {
    say(
"Black lightning crackles along the blade of "+TPN+"'s "+NAG+".\n");
    write(
"Black lightning crackles along the blade of your "+NAG+".\n");
return ARTR/3;
     }
       return;
}
 
nag_slice() {
    int X, num;
  num = RAN(ARTR/3) + 1;
  MYWEP->mod_prof(num);
  return 1;
}
 
nag_leg_sweep() {
   MYWEP->mod_prof(RAN(ARTR/3)+3);
return 1;
}
 
nag_bar_bash() {
    int X, num;
  num = RAN(ARTR/2) + 2;
  MYWEP->mod_prof(num);
  return 1;
}
 
nag_multi_hit() {
    int rart, go;
rart = RAN(ARTR/2)+2;
    if(rart > 5) rart = 5;
  for(go=0; go < rart; go++) {
  r_attack(); }
return 1;
}
 
r_attack() {
    int Z;
    string attack;
Z = RAN(12);
  if(Z == 0) attack = nag_head_smash();
  if(Z == 1) attack = nag_leg_sweep();
  if(Z == 2) attack = nag_throat_blow();
  if(Z == 3) attack = nag_strike();
  if(Z == 4) attack = nag_head_smash();
  if(Z > 3 && Z < 8) attack = nag_bar_bash();
  if(Z > 7) attack = nag_slice();
return attack;
}
 
nag_head_smash() {
   MYWEP->mod_prof(RAN(ARTR)+1);
return 1;
}
 
nag_strike() {
nag_head_smash();
   MYWEP->mod_prof((ARTR/(RAN(2)+1))+3);
return 1;
}
 
nag_throat_blow() {
nag_leg_sweep();
   MYWEP->mod_prof(RAN(ARTR)+RAN(ARTR/2));
return 1;
}
 
nag_aura() {
   MYWEP->mod_prof(ARTR*2);
return 1;
}
 
check_extra() {
  int bi, bl;
  bi = GOB->query_bion_on();
  if(bi && RAN(45) < GLEV) {
    write(OH+" Bionics power your attack "+OH+"\n");
    MYWEP->mod_prof(RAN(ARTR));
  }
  if(GOB->item_weplink()) MYWEP->mod_prof(GOB->item_weplink());
  return 1;
}
 
ninja_damage(object ob) {
  int MAX, dmg, amode;
  amode = GOB->query_attack_mode();
  MAX = ARTR + 5;
  if(MAX > 17) MAX = 17;
  dmg = MYWEP->query_prof();
  if(amode == 1) { MAX += 5; dmg += 2; }
  if(amode == 2) { MAX -= 5; dmg -= 2; }
  if(dmg > MAX) dmg = MAX;
    if(TP->query_alignment() > 500) dmg = dmg - 2;
  if(GOB->shogun()) dmg = dmg + 2;
  if(dmg < 0) dmg = 0;
  if(find_player("snow")) TE(find_player("snow"),
    RED+" NAG BON : "+dmg+OFF+"\n");
  MYWEP->set_prof(dmg);
  return 1;
}
