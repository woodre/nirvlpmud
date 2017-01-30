/*CyberNinja Guild weapon- Kusari-gama daemon master*/
 
#include "color.h"
#include "wepdefs.h"

weapon_hit() {
    int W;
    MYWEP->set_prof(0);
W = RAN(80)+ RAN(ARTR*5)/2;
  if(GOB->query_attack_mode() == 1) W += 20;
  if(GOB->query_attack_mode() == 2) W -= 40;
  if(GOB->query_weapon() != "kusari_gama") W -=40;
  if(W > 105) {
kgama_aura();
     }
  if(W > 65 && W < 106)  {
kgama_multi_hit();
     }
  if(W > 60 && W < 66)  {
kusari_tangle();
     }
  if(W > 50 && W < 61)  {
kusari_whip();
     }
  if(W > 40 && W < 51)  {
gama_slice();
     }
  check_extra();
  ninja_damage(MEAT);
  if(MEAT->query_hp() < ARTR) {
    write("Your "+KG+" hungers for the kill!\n");
    return (ARTR/3)+1; }
  if(W > 80 && W < 91)  {
    say(
RED+"Fire"+OFF+" burns along the blade of "+TPN+"'s "+KG+".\n");
    write(
RED+"Fire"+OFF+" burns along the blade of your "+KG+".\n");
return ARTR/4;
     }
  if(W > 90)  {
    say(
BOLD+"Lightning"+OFF+" crackles along the chain of "+TPN+"'s "+KG+".\n");
    write(
BOLD+"Lightning"+OFF+" crackles along the chain of your "+KG+".\n");
return ARTR/3;
     }
       return;
}
 
gama_slice() {
    int X, num;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You slice "+MEATN+" in the ";
stab2 = NI+TPN+" slice "+MEATN+" in the ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
    num = RAN(ARTR/4)+4;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
    num = RAN(ARTR/4)+2;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
    num = RAN(ARTR/4)+2;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
    num = RAN(ARTR/4)+1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
    num = RAN(ARTR/4)+1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
    num = RAN(ARTR/4)+1;
    }
    MYWEP->mod_prof(num);
  return 1;
}
 
kusari_whip() {
    int X, num;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You whip the chain of your "+KG+" into "+MEATN+"'s ";
stab2 = NI+TPN+" whips the chain of "+GEN+" "+KG+" into "+MEATN+"'s ";
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
 
kusari_tangle() {
   say(
NI+TPN+" twirls the chain of "+GEN+" "+KG+" around "+MEATN+"'s legs!\n");
   write(
NI+"You twirl the chain of your "+KG+" around "+MEATN+"'s legs!\n");
   TR(ETP,MEATN+" slams into the ground.\n");
    MYWEP->mod_prof((ARTR/(RAN(2)+2))+1);
return 1;
}
 
kgama_multi_hit() {
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
  if(Z == 0) attack = kusari_tangle();
  if(Z == 1) attack = kgama_neck_rip();
  if(Z == 2) attack = kgama_chop_tangle();
  if(Z == 3) attack = gama_chop();
  if(Z > 3 && Z < 7) attack = kusari_whip();
  if(Z > 6) attack = gama_slice();
return attack;
}
 
gama_chop() {
   say(
NI+TPN+" elegantly steps inside "+MEATN+"'s guard.\n"+
NI+TPN+" rips "+GEN+" "+KG+" blade through "+MEATN+"'s midsection!\n");
   write(
NI+"You elegantly step inside "+MEATN+"'s guard.\n"+
NI+"You rip your "+KG+" blade through "+MEATN+"'s midsection!\n");
   TR(ETP,MEATN+" coughs up "+RED+"blood"+OFF+".\n");
    MYWEP->mod_prof(RAN(ARTR/2)+3);
   say(
NI+TPN+" sneers and spits on "+MEATN+", then spins away.\n");
   write(
NI+"You sneer and spit on "+MEATN+", then spin away.\n");
return 1;
}
 
kgama_chop_tangle() {
gama_chop();
kusari_tangle();
return 1;
}
 
kgama_neck_rip() {
   say(
NI+TPN+"'s "+KG+" streaks through the air!.\n");
   write(
NI+"You whip your "+KG+" blade through the air while holding the chain!\n");
  TR(ETP,NI+REV_RED+"SSSLLLLIIIIICCCCCCEEEEEE"+OFF+"\n");
    say(
NI+TPN+"'s "+KG+" blade wraps around and through "+MEATN+"'s throat!\n");
   write(
NI+"Your "+KG+" blade wraps around and through "+MEATN+"'s throat!\n");
   TR(ETP,NI+RED+"Blood"+OFF+" spatters everywhere!\n");
    MYWEP->mod_prof(RAN(ARTR)+RAN(ARTR/3)+2);
return 1;
}
 
kgama_aura() {
   say(
NI+"A "+BOLD+BLINK+"VORTEX"+OFF+OFF+" of death energy enshrouds "+TPN+"!\n"+
TPN+" writhes and screams in agony!\n");
   write(
NI+"A "+BOLD+BLINK+"VORTEX"+OFF+OFF+" of death energy enshrouds you!\n"+
"You writh and scream in agony!\n");
   TR(ETP,NI+"The room is drained of all light.\n");
   TR(ETP,
NI+"Rings of crackling "+BOLD+"lightning"+OFF+" surround "+MEATN+"!\n"+
MEATN+" is lifted, screaming, from the ground!\n");
    TR(ETP,
NI+"The "+BOLD+"lightning"+OFF+" releases all of its energy into "+MEATN+"!\n"+
MEATN+" groans pitifully and falls into a smoking heap on the floor.\n");
    TR(ETP,
NI+"Light returns to the room.\n"+
NI+"The "+BOLD+BLINK+"VORTEX"+OFF+OFF+" surrounding "+TPN+" disappears.\n");
    MYWEP->mod_prof((ARTR*2));
return 1;
}
  
check_extra() {
  int bi, bl;
  bi = GOB->query_bion_on();
  if(bi && RAN(45) < GLEV) {
    write(REV_BLUE+"~##~  BIONICS  ~##~"+OFF+"\n");
    MYWEP->mod_prof(RAN(GLEV));
  }
  if(GOB->item_weplink()) MYWEP->mod_prof(GOB->item_weplink());
  return 1;
}
 
ninja_damage(object ob) {
  int MAX, mhp, dmg, amode;
  amode = GOB->query_attack_mode();
  MAX = ARTR + 5;
  if(MAX > 17) MAX = 17;
  mhp = ob->query_hp();
  dmg = MYWEP->query_prof();
  if(amode == 1) { MAX += 5; dmg += 2; }
  if(amode == 2) { MAX -= 5; dmg -= 2; }
  if(dmg > MAX) dmg = MAX;
  if(TP->query_alignment() > 500) dmg = dmg - 2;
  if(GOB->shogun()) dmg = dmg + 2;
  if(dmg >= mhp) dmg = mhp - 2;
  if(dmg < 0) dmg = 0;
  if(find_player("snow")) tell_object(find_player("snow"),
     RED+"..KG BONUS : "+dmg+OFF+"\n");
  MYWEP->set_prof(dmg);
  return 1;
}
