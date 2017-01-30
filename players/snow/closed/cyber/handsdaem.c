/*CyberNinja Guild weapon- Unarmed combat daemon master*/
 
#include "color.h"
#include "wepdefs.h"

object ob;
string obn, me;

side() {
  if(random(2) == 1) return "left";
  else return "right";
}

weapon_hit() {
    int W;
if(!MEAT) return;
if(!TP) return;
  MYWEP->set_prof(0);
ob = MEAT;
obn = ob->query_name();
me = TPN;
W = RAN(ARTR*5);
if(GOB->query_attack_mode() == 1) W += 10;
if(GOB->query_attack_mode() == 2) W -= 20;
if(GOB->query_weapon() != "unarmed") W -=40;
  if(W > 80) {
hands_aura();
     }
  if(W > 45 && W < 81)  {
hands_multi_hit();
     }
  if(W > 35 && W < 46)  {
hands_leg_sweep();
     }
  if(W > 25 && W < 36)  {
hands_kick();
     }
  if(W > 15 && W < 26)  {
hands_jab();
     }
  check_extra();
  ninja_damage(ob);
  if(ob->query_hp() < ARTR) {
    write("You hunger for the kill!\n");
    return (ARTR/3 + 1); }
  if(W > 60) {
    write(
RED+"Fire of Power"+OFF+" outlines your fists!\n");
    say(
RED+"Fire of Power"+OFF+" outlines "+me+"'s fists!\n");
  return ARTR/4; }
}
 
hands_jab() {
    int X, num;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You jab your "+side()+" hand into "+obn+"'s ";
stab2 = NI+me+" jabs "+GEN+" "+side()+" hand into "+obn+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
    num = RAN(ARTR/4)+2;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
    num = RAN(ARTR/5)+1;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
    num = RAN(ARTR/6)+1;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
    num = RAN(ARTR/6)+1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
    num = RAN(ARTR/6)+1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
    num = RAN(ARTR/6)+1;
    }
  MYWEP->mod_prof(num);
  return 1;
}
 
hands_leg_sweep() {
   say(
NI+me+" whirls with blinding speed.\n"+
NI+me+" sweeps "+GEN+" "+side()+" leg behind and through "+obn+"'s legs!\n");
   write(
NI+"You whirl with blinding speed.\n"+
NI+"You sweep your "+side()+" leg behind and through "+obn+"'s legs!\n");
   TR(ETP,
obn+"'s legs crumple as "+obn+" falls.\n");
   say(
NI+me+" spits on "+obn+"'s pitiful, prone form.\n");
   write(
NI+"You spit on "+obn+"'s pitiful, prone form.\n");
  MYWEP->mod_prof(RAN(ARTR/3)+2);
return 1;
}

hands_slide() {
  write(
NI+"You glide gracefully behind your opponent.\n"+
NI+"You smash your fist into "+obn+"'s kidney.\n");
  say(
NI+me+" glides gracefully behind "+GEN+" opponent.\n"+
NI+me+" smashes "+GEN+" fist into "+obn+"'s kidney.\n");
  TR(ETP,
NI+obn+" doubles over in excruciating pain!\n");
  MYWEP->mod_prof(RAN(ARTR/3)+2);
return 1;
}

hands_throat() {
  write(
NI+BOLD+"Lightning"+OFF+
  " crackles down the length of your forearm.\n"+
NI+"You deliver a punishing strike to "+obn+"'s throat!\n");
  say(
NI+BOLD+"Lightning"+OFF+
  " crackles down the length of "+me+"'s forearm.\n"+
NI+me+" delivers a punishing strike to "+obn+"'s throat!\n");
  TR(ETP,
NI+obn+" screams as "+BOLD+"lightning"+OFF+
  " pours from his mouth, nose, and eyes!\n");
  MYWEP->mod_prof(RAN(ARTR/2)+2);
return 1;
}

hands_ribs() {
  write(
NI+"You snap a powerful kick into "+obn+"'s midsection.\n");
  say(
NI+me+" snaps a powerful kick into "+obn+"'s midsection.\n");
  TR(ETP,
NI+"You hear the sickening "+RED+"crunch"+OFF+
  " of "+obn+"'s ribs breaking!\n");
  MYWEP->mod_prof(RAN(ARTR/3)+3);
return 1;
}

hands_plexus() {
  write(
NI+"You drive your knee into "+obn+"'s solar plexus.\n");
  say(
NI+me+" drives "+GEN+" knee into "+obn+"'s solar plexus.\n");
  TR(ETP,
NI+obn+" doubles over.\n");
  write(
NI+"You smash your elbow into "+obn+"'s face!\n");
  say(
NI+me+" smashes "+GEN+" elbow into "+obn+"'s face!\n");
  TR(ETP,
NI+obn+"'s head "+BOLD+"snaps"+OFF+" back.\n");
  MYWEP->mod_prof(RAN(ARTR/2)+2);
return 1;
}

hands_kick() {
    int X, num;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You smash your "+side()+" foot into "+obn+"'s ";
stab2 = NI+me+" smashes "+GEN+" "+side()+" foot into "+obn+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
    num = RAN(ARTR/4)+4;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
    num = RAN(ARTR/4)+3;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
    num = RAN(ARTR/4)+2;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
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
 
hands_multi_hit() {
    int rart, go;
rart = RAN(ARTR/2)+2;
    if(rart > 8) rart = 8;
  for(go=0; go < rart; go++) {
  r_attack(); }
return 1;
}
 
r_attack() {
    int Z;
    string attack;
Z = RAN(20);
  if(Z == 0) attack = hands_head_smash();
  if(Z == 1) attack = hands_slide();
  if(Z == 2) attack = hands_plexus();
  if(Z == 3) attack = hands_leg_sweep();
  if(Z == 4) attack = hands_strike();
  if(Z == 4) attack = hands_throat_blow();
  if(Z == 4) attack = hands_throat();
  if(Z == 4) attack = hands_throat();
  if(Z > 4 && Z < 10) attack = hands_kick();
  if(Z > 9) attack = hands_jab();
return attack;
}
 
hands_head_smash() {
   say(
NI+me+" gracefully whirls in close to "+obn+".\n"+
NI+me+" lifts "+GEN+" "+side()+" elbow smashing into "+obn+"'s face!\n");
   write(
NI+"You gracefully whirl in close to "+obn+".\n"+
NI+"You lift your "+side()+" elbow smashing into "+obn+"'s face!\n");
TR(ETP,
  NI+BOLD+"CCRRRRRAAAAACCCCCCCCKKKKKKKKK!!!!!!!!!!"+OFF+"\n"+
obn+" stumbles backward in a daze.\n");
  MYWEP->mod_prof(RAN(ARTR)+1);
return 1;
}
 
hands_strike() {
   say(
NI+me+" raises "+GEN+" hands to the heavens.\n"+
NI+me+"'s hands are wreathed with black "+
  BOLD+"energy"+OFF+"!\n"+
NI+me+" plunges "+GEN+" hands into "+obn+".\n");
   write(
NI+"You raise your hands to the heavens.\n"+
NI+"Your hands are wreathed in black "+
  BOLD+"energy"+OFF+"!\n"+
NI+"You plunge your hands into "+obn+".\n");
   TR(ETP,obn+"'s body writhes in arcs of "+
  YELLOW+"electricity"+OFF+"!\n");
  MYWEP->mod_prof((ARTR/(RAN(3)+1))+3);
return 1;
}
 
hands_throat_blow() {
   say(
NI+me+" flips high into the air!\n"+
NI+me+" blurs as "+GEN+" descends.\n"+
NI+me+"'s hands and feet "+BOLD+"flash"+OFF+" out!\n");
   write(
NI+"You flip high into the air!\n"+
NI+"You blur as you descend.\n"+
NI+"Your hands and feet "+BOLD+"flash"+OFF+" out!\n");
   TR(ETP,obn+"'s eyes widen in fear and horror.\n"+
NI+REV_RED+"TTTHHHHHAAAAAACCCCCCCCCCKKKKK!!!!!!!!!"+OFF+"\n");
   TR(ETP,obn+"'s throat appears to be crushed!\n"+
obn+" gurgles in helpless pain.\n");
  MYWEP->mod_prof(RAN(ARTR)+RAN(ARTR/3)+2);
return 1;
}
 
hands_aura() {
   say(
NI+"A black "+BLINK+BOLD+"vortex"+OFF+OFF+
  " of death energy enshrouds "+me+"!\n");
   write(
NI+"A black "+BLINK+BOLD+"vortex"+OFF+OFF+
  " of death energy enshrouds you!\n");
   TR(ETP,NI+"The room is drained of all light.\n");
   TR(ETP,
NI+"Rings of crackling black lightning surround "+obn+"!\n"+
obn+" is lifted, screaming, from the ground!\n");
   TR(ETP,
NI+"The lightning releases all of its energy into "+obn+"!\n"+
obn+" groans pitifully and falls into a "+
  BROWN+"smoking"+OFF+" heap on the floor.\n");
    TR(ETP,
NI+"Light returns to the room.\n"+
NI+"The vortex surrounding "+me+" disappears.\n");
  MYWEP->mod_prof((ARTR*2)/(RAN(2)+1)+1);
return 1;
}

check_extra() {
  int bi, bl;
  bi = GOB->query_bion_on();
  if(bi && RAN(45) < GLEV) {
    write(REV_BLUE+"~##~  BIONICS  ~##~"+OFF+"\n");
    MYWEP->mod_prof(RAN(GLEV));
  }
  if(GOB->item_weplink())
    MYWEP->mod_prof(GOB->item_weplink()/2);
  return 1;
}
 
ninja_damage(object ob) {
  int MAX, dmg, amode;
  amode = GOB->query_attack_mode();
  MAX = ARTR + 5;
  if(MAX > 15) MAX = 15;
  dmg = MYWEP->query_prof();
  if(amode == 1) { MAX += 5; dmg += 2; }
  if(amode == 2) { MAX -= 5; dmg -= 2; }
  if(dmg > MAX) dmg = MAX;
  if(TP->query_alignment() > 500) dmg = dmg - 2;
  if(GOB->shogun()) dmg = dmg + 2;
  if(dmg < 0) dmg = 0;
  if(find_player("snow")) TE(find_player("snow"),
    RED+" HANDS BON : "+dmg+OFF+"\n");
  MYWEP->set_prof(dmg);
  return 1;
}
