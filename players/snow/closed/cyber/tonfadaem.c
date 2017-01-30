/*CyberNinja Guild weapon- Ton-fa daemon master last updated by Ulath 6-12-97*/
 
#include "/players/llew/closed/ansi.h"
#include "/players/ulath/closed/ninjaweps/wepdefs.h"
 
weapon_hit() {
  int W;
  MYWEP->set_prof(0);
  W = RAN(72)+ RAN(ARTR*5)/2;
  if(GOB->query_attack_mode() == 1) W += 20;
  if(GOB->query_attack_mode() == 2) W -= 40;
if(GOB->query_weapon() != "ton-fa") W -=40;
    if(W > 105) {
      ton_aura();
    }
    if(W > 97 && W < 106)  {
      ton_throat_blow();
    }
    if(W > 90 && W < 98)  {
      ton_back_strike();
    }
    if(W > 80 && W < 91)  {
      ton_head_slap();
    }
    if(W > 65 && W < 81)  {
      ton_multi_hit();
    }
    if(W > 60 && W < 66)  {
      ton_face_smash();
    }
    if(W > 50 && W < 61)  {
      ton_gut_punch();
    }
    if(W > 40 && W < 51)  {
      ton_stab();
    }
  check_extra();
  ninja_damage(MEAT);
  if(MEAT->query_hp() < ARTR) {
    write("Your "+TF+" hungers for the kill!\n");
    return (ARTR/3)+1;
  }
  if(W > 70 && W < 91)  {
    say(
      HIR+"Fire"+NORM+" burns down the length of "+TPN+"'s "+TF+".\n");
    write(
      HIR+"Fire"+NORM+" burns down the length of your "+TF+".\n");
    return ARTR/4;
  }
  if(W > 90)  {
    say(
      BOLD+"Black lightning"+NORM+" crackles down the length of "+TPN+"'s "+TF+".\n");
    write(
      BOLD+"Black lightning"+NORM+" crackles down the length of your "+TF+".\n");
    return ARTR/3;
  }
  return;
}
 
ton_stab() {
  int X, num;
  string crack1,crack2;
  X = RAN(10);
  crack1 = NI+"You crack "+MEATN+" in the ";
  crack2 = NI+TPN+" cracks "+MEATN+" in the ";
  if(X == 0) {
    write(crack1+"head.\n");
    say(crack2+"head.\n");
    num = RAN(ARTR/3)+4;
  }
  if(X == 1) {
    write(crack1+"gut.\n");
    say(crack2+"gut.\n");
    num = RAN(ARTR/3)+2;
  }
  if(X == 2) {
    write(crack1+"chest.\n");
    say(crack2+"chest.\n");
    num = RAN(ARTR/3)+2;
  }
  if(X > 2 && X <5) {
    write(crack1+"shoulder.\n");
    say(crack2+"shoulder.\n");
    num = RAN(ARTR/3)+1;
  }
  if(X > 4 && X < 7) {
    write(crack1+"leg.\n");
    say(crack2+"leg.\n");
    num = RAN(ARTR/3)+1;
  }
  if(X > 6) {
    write(crack1+"arm.\n");
    say(crack2+"arm.\n");
    num = RAN(ARTR/3)+1;
  }
  MYWEP->add_prof(num);
  return 1;
}
 
ton_gut_punch() {
   say(
     NI+TPN+" jabs the butt of "+GEN+" "+TF+" into "+MEATN+"'s midsection.\n");
   write(
     NI+"You jab the butt of your "+TF+" into "+MEATN+"'s midsection.\n");
   TR(ETP,MEATN+" doubles over in pain.\n");
   MYWEP->mod_prof(RAN(ARTR/4)+2);
   return 1;
}
 
ton_face_smash() {
   say(
     NI+TPN+" smashes "+GEN+" "+TF+" into "+MEATN+"'s face!\n");
   write(
     NI+"You smash your "+TF+" into "+MEATN+"'s face!\n");
   TR(ETP,MEATN+" tries to blink back tears.\n");
   MYWEP->mod_prof((ARTR/2)+1);
   return 1;
}
 
ton_multi_hit() {
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
  if(Z == 0) attack = ton_face_smash();
  if(Z > 0 && Z < 4) attack = ton_gut_punch();
  if(Z > 3) attack = ton_stab();
  return attack;
}
 
ton_head_slap() {
   say(
     NI+TPN+" rolls underneath "+MEATN+"'s pathetic attack.\n"+
     NI+TPN+" SMACKS! "+MEATN+"'s head "+GEN+" "+TF+".\n");
   write(
     NI+"You roll underneath "+MEATN+"'s pathetic attack.\n"+
     NI+"You SMACK! "+MEATN+"'s head with your "+TF+".\n");
   TR(ETP,MEATN+" looks dazed.\n");
   MYWEP->mod_prof(RAN(4)+2);
   ton_face_smash();
   say(
     NI+TPN+" sneers and spits on "+MEATN+", then spins away.\n");
   write(
     NI+"You sneer and spit on "+MEATN+", then spin away.\n");
   return 1;
}
 
ton_back_strike() {
  ton_gut_punch();
  say(
    NI+TPN+" spins elegantly around "+GEN+" gasping foe.\n"+
    NI+TPN+" cracks "+GEN+" "+TF+" over "+MEATN+"'s back.\n");
  write(
    NI+"You spin elegantly around your gasping foe.\n"+
    NI+"You crack your "+TF+" over "+MEATN+"'s back.\n");
  TR(ETP,"You hear "+MEATN+"'s spine crack.\n");
  MYWEP->mod_prof((ARTR/(RAN(3)+1))+RAN(6));
  return 1;
}
 
ton_throat_blow() {
   say(
     NI+TPN+"'s "+TF+" blurs into a black streak across your vision.\n");
   TR(ETP,HIR+"SSSCCCCHHHHHWWWWWWAAAAAACCCCCKKKK!!!"+NORM+"\n");
   say(NI+TPN+" slams "+GEN+" "+TF+" into "+MEATN+"'s throat!\n");
   write(
     NI+"You slam your "+TF+" into "+MEATN+"'s throat!\n");
   TR(ETP,HIR+MEATN+"'s windpipe collapses!\n"+
      MEATN+" gasps for air!"+NORM+"\n");
   MYWEP->mod_prof(RAN(ARTR)+RAN(ARTR/3)+5);
   return 1;
}
 
ton_aura() {
  say(
    NI+"A black "+BOLD+"VORTEX"+NORM+" of death energy enshrouds "+TPN+"!\n"+
    TPN+" writhes and screams in ecstacy!\n");
  write(
    NI+"A black "+BOLD+"VORTEX"+NORM+" of death energy enshrouds you!\n"+
    "You writh and scream in ecstacy!\n");
  TR(ETP,NI+"The room is drained of all light.\n");
  TR(ETP,
    NI+"Rings of crackling "+BOLD+"black lightning"+NORM+" surround "+MEATN+"!\n"+
    MEATN+" is lifted, screaming, from the ground!\n"+
    NI+"The "+BOLD+"lightning"+NORM+" releases all of its energy into "+MEATN+"!\n"+
    MEATN+" groans pitifully and falls into a smoking heap on the floor.\n");
  TR(ETP,
    NI+"Light returns to the room.\n"+
    NI+"The vortex surrounding "+TPN+" disappears.\n");
  MYWEP->mod_prof((ARTR*2));
  return 1;
}

check_extra() {
  int bi, bl;
  bi = GOB->query_bion_on();
  if(bi && RAN(45) < GLEV) {
    write("~##~ Bionics power your attack ~##~\n");
    MYWEP->mod_prof(RAN(GLEV));
  }
  if(GOB->item_weplink()) {
    MYWEP->mod_prof(GOB->item_weplink());
  }
  return 1;
}
 
ninja_damage(object ob) {
  int MAX, dmg, amode;
  amode = GOB->query_attack_mode();
  MAX = TP->query_wc();
  if(MAX > 17) MAX = 17;
  dmg = MYWEP->query_prof();
  if(amode == 1) { MAX += 5; dmg += 2; }
  if(amode == 2) { MAX -= 5; dmg -= 2; }
  if(dmg > MAX) dmg = MAX; 
  if(TP->query_alignment() > 500) dmg = dmg - 2;
  if(dmg < 0) dmg = 0;
  MYWEP->set_prof(dmg);
  return 1;
}
