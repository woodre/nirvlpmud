/*CyberNinja Guild weapon- Naginata daemon master*/
 
#define TP this_player()
#define TO this_object()
#define ETO ENV(TO)
#define ETP ENV(TP)
#define TPN CAP(TP->query_name())
#define ETON ETO->query_name()
#define GOB present("CyberNinja Implants",TP)
#define GLEV GOB->guild_lev()
#define ARTR GOB->query_art_level()
#define MEAT TP->query_attack()
#define MEATN CAP(MEAT->query_real_name())
#define GEN TP->query_possessive()
#define RAN random
#define PRE present
#define CAP capitalize
#define TR tell_room
#define ENV environment
#define CO call_other
#define NI "*~*"
#define NAG "Naginata"
 
int totaldam;
set_totaldam(td) { totaldam = td; }
query_totaldam() { return totaldam; }
add_totaldam(int num) { totaldam += num; }
 
offer_naginata(arg) {
  object ob;
  int value;
value = random(20)+40;
   if(arg == "naginata" || arg == "Naginata") {
    say(
TPN+" raises "+GEN+" "+NAG+" high into the air.\n");
    write(
"You raise your "+NAG+" high into the air.\n");
    TR(ETP,"A black vortex envelops and consumes the "+NAG+".\n");
    write(
"You receive "+value+" coins for your offering.\n");
CO(TP,"add_money",value);
  destruct(PRE("naginata",TP));
return 1;
  }
}
 
weapon_hit() {
    int W;
W = RAN(70)+ RAN(ARTR*5)/2;
  if(W > 105) {
nag_aura();
     }
  if(W > 97 && W < 106)  {
nag_throat_blow();
     }
  if(W > 90 && W < 98)  {
nag_strike();
     }
  if(W > 80 && W < 91)  {
nag_head_smash();
     }
  if(W > 70 && W < 81)  {
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
if(MEAT->query_hp() < ARTR) {
nag_finish();
     }
  check_extra();
  ninja_damage(MEAT);
  set_totaldam(0);
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
    int X;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You rip-slice into "+MEATN+"'s ";
stab2 = NI+TPN+" rip-slices into "+MEATN+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
    totaldam += RAN(ARTR/3)+4;
return 1;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
    totaldam += RAN(ARTR/3)+2;
return 1;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
    totaldam += RAN(ARTR/3)+2;
return 1;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
    totaldam += RAN(ARTR/3)+1;
return 1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
    totaldam += RAN(ARTR/3)+1;
return 1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
    totaldam += RAN(ARTR/3)+1;
return 1;
    }
}
 
nag_leg_sweep() {
   say(
NI+TPN+" whirls with blinding speed.\n"+
NI+TPN+" sweeps the shaft of "+GEN+" "+NAG+" behind and through "+MEATN+"'s legs!\n");
   write(
NI+"You whirl with blinding speed.\n"+
NI+"You sweep the staff of your "+NAG+" behind and through "+MEATN+"'s legs!\n");
   TR(ETP,MEATN+"'s legs crumple as "+MEATN+" falls.\n");
   say(
NI+TPN+" spits on "+MEATN+"'s pitiful, prone form.\n");
   write(
NI+"You spit on "+MEATN+"'s pitiful, prone form.\n");
   totaldam += RAN(ARTR/3)+3;
return 1;
}
 
nag_bar_bash() {
    int X;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You bash the "+NAG+"'s staff into "+MEATN+"'s ";
stab2 = NI+TPN+" bashes the "+NAG+"'s staff into "+MEATN+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
   totaldam += RAN(ARTR/5)+4;
return 1;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
   totaldam += RAN(ARTR/5)+2;
return 1;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
   totaldam += RAN(ARTR/5)+2;
return 1;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
   totaldam += RAN(ARTR/5)+1;
return 1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
   totaldam += RAN(ARTR/5)+1;
return 1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
   totaldam += RAN(ARTR/5)+1;
return 1;
    }
}
 
nag_multi_hit() {
    int rart;
rart = RAN(ARTR/2)+2;
    if(rart > 8) rart = 8;
  if(rart == 2) {
r_attack(); r_attack(); }
  if(rart == 3) {
r_attack(); r_attack(); r_attack(); }
  if(rart == 4) {
r_attack(); r_attack(); r_attack(); r_attack(); }
  if(rart == 5) {
r_attack(); r_attack(); r_attack(); r_attack(); r_attack(); }
  if(rart == 6) {
r_attack(); r_attack(); r_attack(); r_attack(); r_attack(); r_attack(); }
  if(rart == 7) {
r_attack(); r_attack(); r_attack(); r_attack(); r_attack(); 
r_attack(); r_attack(); }
  if(rart == 8) {
r_attack(); r_attack(); r_attack(); r_attack(); r_attack();
r_attack(); r_attack(); r_attack(); }
return 1;
}
 
r_attack() {
    int Z;
    string attack;
Z = RAN(12);
  if(Z == 0) attack = nag_head_smash();
  if(Z == 1) attack = nag_leg_sweep();
  if(Z > 1 && Z < 8) attack = nag_bar_bash();
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
TR(ETP,NI+"TTTTHHHHHHHUUUUUUCCCCCCCCKKKKKKKKK!!!!!!!!!!\n"+
MEATN+" stumbles backward in a daze.\n");
   totaldam += RAN(ARTR)+1;
return 1;
}
 
nag_strike() {
nag_head_smash();
   say(
NI+TPN+"'s "+NAG+" blade burns with a molten fury!\n"+
NI+TPN+" charges toward "+GEN+" reeling foe!\n"+
NI+TPN+" plunges "+GEN+" white-hot "+NAG+" into "+MEATN+".\n");
   write(
NI+"Your "+NAG+" blade burns with a molten fury!\n"+
NI+"You charge toward your reeling foe!\n"+
NI+"You plunge your white-hot "+NAG+" into "+MEATN+".\n");
   TR(ETP,MEATN+" screams in burned agony!\n");
   totaldam += (ARTR/(RAN(2)+1))+3;
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
NI+"TTTTHHHHHHUUUUUUUUCCCCCCCCKKKKKKKKKK!!!!!!!!!\n");
    say(
NI+TPN+" impales "+MEATN+" through the throat!\n");
   write(
NI+"You impale "+MEATN+" through the throat!\n");
   TR(ETP,NI+"Blood spatters everywhere!\n"+
MEATN+" gurgles in helpless pain.\n");
   totaldam += RAN(ARTR)+RAN(ARTR/2);
return 1;
}
 
nag_aura() {
   say(
NI+"A black vortex of death energy enshrouds "+TPN+"!\n"+
TPN+" writhes and screams in agony!\n");
   write(
NI+"A black vortex of death energy enshrouds you!\n"+
"You writh and scream in agony!\n");
   TR(ETP,NI+"The room is drained of all light.\n");
   TR(ETP,
NI+"Rings of crackling black lightning surround "+MEATN+"!\n"+
MEATN+" is lifted, screaming, from the ground!\n"+
NI+"The lightning releases all of its energy into "+MEATN+"!\n"+
MEATN+" groans pitifully and falls into a smoking heap on the floor.\n");
    TR(ETP,
NI+"Light returns to the room.\n"+
NI+"The vortex surrounding "+TPN+" disappears.\n");
   totaldam += ARTR*2;
   CO(TP,"hit_player",RAN(ARTR));
return 1;
}
 
nag_finish() {
    int F;
F = RAN(6);
  if(F == 0) {
    say(
NI+TPN+" hacks off "+MEATN+"'s legs!\n");
    write(
NI+"You hack off "+MEATN+"'s legs!\n");
    TR(ETP,
MEATN+" flops to the floor.\n");
    say(
NI+TPN+" mercilessly hacks off "+MEATN+"'s arms!\n");
    write(
NI+"You mercilessly hack off "+MEATN+"'s arms!\n");
    TR(ETP,
MEATN+" bleeds helplessly on the ground.\n");
    say(
NI+TPN+" raises "+GEN+" "+NAG+" above "+GEN+" head...\n");
    write(
NI+"You raise your "+NAG+" above your head...\n");
    TR(ETP,
MEATN+" screams pitifully for mercy!\n");
    say(
NI+TPN+" brings "+GEN+" "+NAG+" down upon "+MEATN+" with relish!\n");
    write(
NI+"You bring your "+NAG+" down upon "+MEATN+" with relish for the kill!\n");
    TR(ETP,
NI+"THWACK!\n"+
MEATN+"'s head rolls on the bloody floor.\n");
  totaldam += MEAT->query_hp();
    say(
NI+TPN+" raises "+GEN+" "+NAG+" in victory!\n");
    write(
NI+"You raise your "+NAG+" in victory!\n");
return 1;
   }
 
  if(F == 1) {
    write(
NI+"You whirl inside "+MEATN+"'s defenses!\n"+
NI+"You stare into "+MEATN+"'s eyes...\n");
    say(
NI+TPN+" whirls inside "+MEATN+"'s defenses!\n"+
NI+TPN+" stares mercilessly into "+MEATN+"'s eyes...\n");
    TR(ETP,
MEATN+" quivers in helpless panic.\n");
    write(
NI+"You caress "+MEATN+"'s face... almost tenderly...\n"+
NI+"You bring your "+NAG+" up to touch the tender hollow below\n"+
NI+MEATN+"'s chin...\n"+
NI+"You shove the "+NAG+" into "+MEATN+"'s brain!\n");
    say(
NI+TPN+" caresses "+MEATN+"'s face... almost tenderly...\n"+
NI+TPN+" brings "+GEN+" "+NAG+" up to touch the tender hollow below\n"+
NI+MEATN+"'s chin...\n"+
NI+TPN+" shoves "+GEN+" "+NAG+" into "+MEATN+"'s brain!\n");
    TR(ETP,
MEATN+" squirms around on the "+NAG+" blade, then slides to the floor.\n");
  totaldam += MEAT->query_hp();
    write(
NI+"You raise your "+NAG+" in victory!\n");
    say(
NI+TPN+" raises "+GEN+" "+NAG+" in victory!\n");
return 1;
   }
 
  if(F == 2) {
    write(
NI+"You roll under "+MEATN+"'s pitifully weak defenses!\n"+
NI+"You come up behind "+MEATN+".\n");
    say(
NI+TPN+" rolls under "+MEATN+"'s pitifully weak defenses!\n"+
NI+TPN+" comes up behind "+MEATN+".\n");
   TR(ETP,
MEATN+" starts to turn around... too slowly...\n");
   write(
NI+"You remove "+MEATN+"'s head with one quick, expert stroke!\n");
   say(
NI+TPN+" removes "+MEATN+"'s head with one quick, expert stroke!\n");
   TR(ETP,
MEATN+"'s headless body slumps to the ground.\n");
  totaldam += MEAT->query_hp();
    write(
NI+"You raise your "+NAG+" in victory!\n");
    say(
NI+TPN+" raises "+GEN+" "+NAG+" in victory!\n");
return 1;
   }
 
  if(F == 3) {
    write(
NI+"You rip your "+NAG+" blade through "+MEATN+"'s stomach!\n");
    say(
NI+TPN+" rips "+GEN+" "+NAG+" blade through "+MEATN+"'s stomach!\n");
    TR(ETP,
MEATN+" looks down and tries to catch the intestines as they cascade out...\n");
    write(
NI+"You end "+MEATN+"'s suffering with a decapitating slice!\n");
    say(
NI+TPN+" ends "+MEATN+"'s suffering with a decapitating slice!\n");
    TR(ETP,
MEATN+"'s headless, disemboweled body falls to the ground.\n");
  totaldam += MEAT->query_hp();
    write(
NI+"You raise your "+NAG+" in victory!\n");
    say(
NI+TPN+" raises "+GEN+" "+NAG+" in victory!\n");
return 1;
   }
 
  if(F == 4) {
    TR(ETP,
MEATN+" bows to "+TPN+" in defeat...\n"+
MEATN+" kneels on the ground...\n");
    write(
NI+"You step forward and decapitate "+MEATN+".\n"+
NI+"You salute the fountain of blood that was... "+MEATN+".\n");
    say(
NI+TPN+" steps forward and decapitates "+MEATN+".\n"+
NI+TPN+" salutes the ountain of blood that was... "+MEATN+".\n");
    TR(ETP,
NI+MEATN+"'s body flops to the floor, still gushing blood.\n");
  totaldam += MEAT->query_hp();
      write(
NI+"You raise your "+NAG+" in victory!\n");
    say(
NI+TPN+" raises "+GEN+" "+NAG+" in victory!\n");
return 1;
   }
  if(F == 5) {
    TR(ETP,
MEATN+" staggers from pain and exhaustion....\n");
nag_multi_hit();
nag_multi_hit();
nag_multi_hit();
    TR(ETP,
MEATN+"'s battered body falls to the ground and twitches a little,\n"+
      " then is still.\n");
  totaldam += MEAT->query_hp();
    write(
NI+"You raise your "+NAG+" in victory!\n");
    say(
NI+TPN+" raises "+GEN+" "+NAG+" in victory!\n");
return 1;
   }
}
 
check_extra() {
  int bi, bl;
  bi = GOB->query_bion_on();
  bl = GOB->query_blad_on();
  if(bi && RAN(45) < GLEV) {
    write("~##~ Bionics power your attack ~##~\n");
    totaldam += RAN(ARTR);
  }
  if(bl && RAN(30) < GLEV) {
    write("~##~ Blades merge into your attack ~##~\n");
    totaldam += RAN(ARTR/2);
  }
  if(GOB->item_weplink()) totaldam += GOB->item_weplink();
  return 1;
}

ninja_damage(object ob) {
  int MAX, mhp, dmg;
  MAX = 50;
  mhp = ob->query_hp();
  dmg = totaldam;
  if(dmg > 50) dmg = 50;
  if(dmg >= mhp) dmg = mhp - 1;
  if(ob->is_player()) {
    ob->add_hit_point(-dmg);
    return 1;
  }
  ob->hit_player(dmg);
  return 1;
}
