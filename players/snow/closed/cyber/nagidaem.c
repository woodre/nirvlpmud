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
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You rip-slice into "+MEATN+"'s ";
stab2 = NI+TPN+" rip-slices into "+MEATN+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
    num = RAN(ARTR/3)+4;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
    num = RAN(ARTR/3)+2;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
    num = RAN(ARTR/3)+2;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
    num = RAN(ARTR/3)+1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
    num = RAN(ARTR/3)+1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
    num = RAN(ARTR/3)+1;
    }
  MYWEP->mod_prof(num);
  return 1;
}
 
nag_leg_sweep() {
   say(
NI+TPN+" whirls with blinding speed.\n"+
NI+TPN+" sweeps the shaft of "+GEN+" "+NAG+
       " behind and through "+MEATN+"'s legs!\n");
   write(
NI+"You whirl with blinding speed.\n"+
NI+"You sweep the staff of your "+NAG+" behind and through "+MEATN+"'s legs!\n");
   TR(ETP,MEATN+"'s legs crumple as "+MEATN+" falls.\n");
   say(
NI+TPN+" spits on "+MEATN+"'s pitiful, prone form.\n");
   write(
NI+"You spit on "+MEATN+"'s pitiful, prone form.\n");
   MYWEP->mod_prof(RAN(ARTR/3)+3);
return 1;
}
 
nag_bar_bash() {
    int X, num;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You bash the "+NAG+"'s staff into "+MEATN+"'s ";
stab2 = NI+TPN+" bashes the "+NAG+"'s staff into "+MEATN+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
    num = RAN(ARTR/5)+4;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
    num = RAN(ARTR/5)+2;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
    num = RAN(ARTR/5)+2;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
    num = RAN(ARTR/5)+1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
    num = RAN(ARTR/5)+1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
    num = RAN(ARTR/5)+1;
    }
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
   say(
NI+TPN+" gracefully whirls in close to "+MEATN+".\n"+
NI+TPN+" lifts "+GEN+" "+NAG+" staff blurring toward "+MEATN+"'s face!\n");
   write(
NI+"You gracefully whirl in close to "+MEATN+".\n"+
NI+"You lift your "+NAG+" staff blurring toward "+MEATN+"'s face!\n");
TR(ETP,NI+REV_BROWN+"TTTTHHHHHHHUUUUUUCCCCCCCCKKKKKKKKK"+OFF+"\n"+
MEATN+" stumbles backward in a daze.\n");
   MYWEP->mod_prof(RAN(ARTR)+1);
return 1;
}
 
nag_strike() {
nag_head_smash();
   say(
NI+TPN+"'s "+NAG+" blade burns with a "+REV_RED+"molten"+OFF+" fury!\n"+
NI+TPN+" charges toward "+GEN+" reeling foe!\n"+
NI+TPN+" plunges "+GEN+" "+BOLD+"white-hot"+OFF+" "+NAG+" into "+MEATN+".\n");
   write(
NI+"Your "+NAG+" blade burns with a "+REV_RED+"molten"+OFF+" fury!\n"+
NI+"You charge toward your reeling foe!\n"+
NI+"You plunge your "+BOLD+"white-hot"+OFF+" "+NAG+" into "+MEATN+".\n");
   TR(ETP,MEATN+" screams in burned agony!\n");
   MYWEP->mod_prof((ARTR/(RAN(2)+1))+3);
return 1;
}
 
nag_throat_blow() {
nag_leg_sweep();
   say(
NI+TPN+" jumps high into the air!\n"+
NI+TPN+" holds "+GEN+" "+NAG+" poised above "+GEN+" head.\n"+
NI+TPN+" descends upon "+MEATN+" like an Angel of Death!\n");
   write(
NI+"You jump high in the air!\n"+
NI+"You hold your "+NAG+" poised above your head.\n"+
NI+"You descend upon "+MEATN+" like an Angel of DEATH!\n");
   TR(ETP,MEATN+" quivers in fear and horror.\n"+
NI+REV_BROWN+"TTTTHHHHHHUUUUUUUUCCCCCCCCKKKKKKKKKK"+OFF+"\n");
    say(
NI+TPN+" impales "+MEATN+" through the throat!\n");
   write(
NI+"You impale "+MEATN+" through the throat!\n");
   TR(ETP,NI+"Blood spatters everywhere!\n"+
MEATN+" gurgles in helpless pain.\n");
   MYWEP->mod_prof(RAN(ARTR)+RAN(ARTR/2));
return 1;
}
 
nag_aura() {
   say(
NI+"A "+BOLD+"black vortex"+OFF+" of "+BOLD+"death energy"+OFF+
   " enshrouds "+TPN+"!\n"+
TPN+" writhes and screams in ecstacy!\n");
   write(
NI+"A "+BOLD+"black vortex"+OFF+" of "+BOLD+"death energy"+OFF+
   " enshrouds you!\n"+
"You writh and scream in ecstacy!\n");
   TR(ETP,NI+"The room is drained of all light.\n");
   TR(ETP,
NI+"Rings of "+BLINK+BOLD+"crackling black lightning"+OFF+OFF+
   " surround "+MEATN+"!\n"+
MEATN+" is lifted, screaming, from the ground!\n");
    TR(ETP,
NI+"The lightning releases all of its energy into "+MEATN+"!\n"+
MEATN+" groans pitifully and falls into a "+BROWN+"smoking"+OFF+
      " heap on the floor.\n");
    TR(ETP,
NI+"Light returns to the room.\n"+
NI+"The "+BOLD+"vortex"+OFF+" surrounding "+TPN+" disappears.\n");
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
