/*CyberNinja Guild weapon- Kusari-gama daemon master*/
 
inherit wepdefs.h

 
offer_kgama(arg) {
  object ob;
  int value;
value = random(20)+40;
   if(arg == "kusari" || arg == "Kusari-Gama" || arg == "kusari-gama") {
    ob = present("kusari",TP);
    say(
TPN+" raises "+GEN+" Kusari-Gama high into the air.\n");
    write(
"You raise your Kusari-Gama high into the air.\n");
    TR(ETP,"A black vortex envelops and consumes the Kusari-Gama.\n");
    write(
"You receive "+value+" coins for your offering.\n");
CO(TP,"add_money",value);
  destruct(ob);
return 1;
  }
}
 
weapon_hit() {
    int W;
W = RAN(80)+ RAN(ARTR*5)/2;
  if(W > 105) {
kgama_aura();
     }
  if(W > 97 && W < 106)  {
kgama_neck_rip();
     }
  if(W > 90 && W < 98)  {
kgama_chop_tangle();
     }
  if(W > 84 && W < 91)  {
gama_chop();
     }
  if(W > 65 && W < 85)  {
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
  if(MEAT->query_hp() < ARTR) {
nin_finish();
     }
  check_extra();
  ninja_damage(MEAT);
   MYWEP->set_totaldam(0);
  if(W > 70 && W < 91)  {
    say(
"Fire burns along the blade of "+TPN+"'s Kusari-Gama.\n");
    write(
"Fire burns along the blade of your Kusari-Gama.\n");
return ARTR/4;
     }
  if(W > 90)  {
    say(
"Black lightning crackles along the chain of "+TPN+"'s Kusari-Gama.\n");
    write(
"Black lightning crackles along the chain of your Kusari-Gama.\n");
return ARTR/3;
     }
       return;
}
 
gama_slice() {
    int X;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You slice "+MEATN+" in the ";
stab2 = NI+TPN+" slice "+MEATN+" in the ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
    MYWEP->mod_totaldam(RAN(ARTR/4)+4);
return 1;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
    MYWEP->mod_totaldam(RAN(ARTR/4)+2);
return 1;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
    MYWEP->mod_totaldam(RAN(ARTR/4)+2);
return 1;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
    MYWEP->mod_totaldam(RAN(ARTR/4)+1);
return 1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
    MYWEP->mod_totaldam(RAN(ARTR/4)+1);
return 1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
    MYWEP->mod_totaldam(RAN(ARTR/4)+1);
return 1;
    }
}
 
kusari_whip() {
    int X;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You whip the chain of your Kusari-Gama into "+MEATN+"'s ";
stab2 = NI+TPN+" whips the chain of "+GEN+" Kusari-Gama into "+MEATN+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
    MYWEP->mod_totaldam(RAN(ARTR/5)+4);
return 1;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
    MYWEP->mod_totaldam(RAN(ARTR/5)+2);
return 1;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
    MYWEP->mod_totaldam(RAN(ARTR/5)+2);
return 1;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
    MYWEP->mod_totaldam(RAN(ARTR/5)+1);
return 1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
    MYWEP->mod_totaldam(RAN(ARTR/5)+1);
return 1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
    MYWEP->mod_totaldam(RAN(ARTR/5)+1);
return 1;
    }
}
 
kusari_tangle() {
   say(
NI+TPN+" twirls the chain of "+GEN+" Kusari-Gama around "+MEATN+"'s legs!\n");
   write(
NI+"You twirl the chain of your Kusari-Gama around "+MEATN+"'s legs!\n");
   TR(ETP,MEATN+" slams into the ground.\n");
    MYWEP->mod_totaldam((ARTR/(RAN(2)+2))+1);
return 1;
}
 
kgama_multi_hit() {
    int rart;
rart = RAN(ARTR/3)+2;
    if(rart > 6) rart = 6;
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
return 1;
}
 
r_attack() {
    int Z;
    string attack;
Z = RAN(12);
  if(Z == 0) attack = kusari_tangle();
  if(Z > 0 && Z < 4) attack = kusari_whip();
  if(Z > 3) attack = gama_slice();
return attack;
}
 
gama_chop() {
   say(
NI+TPN+" elegantly steps inside "+MEATN+"'s guard.\n"+
NI+TPN+" rips "+GEN+" Kusari-Gama blade through "+MEATN+"'s midsection!\n");
   write(
NI+"You elegantly step inside "+MEATN+"'s guard.\n"+
NI+"You rip your Kusari-Gama blade through "+MEATN+"'s midsection!\n");
   TR(ETP,MEATN+" coughs up blood.\n");
    MYWEP->add_totaldam(RAN(ARTR/2)+3);
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
NI+TPN+"'s Kusari-Gama streaks through the air!.\n");
   write(
NI+"You whip your Kusari-Gama blade through the air while holding the chain!\n");
   TR(ETP,NI+"SSSLLLLIIIIICCCCCCEEEEEE!!!\n");
    say(
NI+TPN+"'s Kusari-Gama blade wraps around and through "+MEATN+"'s throat!\n");
   write(
NI+"Your Kusari-Gama blade wraps around and through "+MEATN+"'s throat!\n");
   TR(ETP,NI+"Blood spatters everywhere!\n");
    MYWEP->add_totaldam(RAN(ARTR)+RAN(ARTR/3)+2);
return 1;
}
 
kgama_aura() {
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
    MYWEP->add_totaldam(ARTR*2);
    TP->hit_player(RAN(ARTR));
return 1;
}
 
nin_finish() {
    int F;
F = RAN(5);
  if(F == 0) {
    say(
NI+TPN+" slices off "+MEATN+"'s legs!\n");
    write(
NI+"You chop off "+MEATN+"'s legs!\n");
    TR(ETP,
MEATN+" flops to the floor.\n");
    say(
NI+TPN+" mercilessly hacks off "+MEATN+"'s arms!\n");
    write(
NI+"You mercilessly hack off "+MEATN+"'s arms!\n");
    TR(ETP,
MEATN+" bleeds helplessly on the ground.\n");
    say(
NI+TPN+" raises "+GEN+" Kusari-Gama above "+GEN+" head...\n");
    write(
NI+"You raise your Kusari-Gama above your head...\n");
    TR(ETP,
MEATN+" screams pitifully for mercy!\n");
    say(
NI+TPN+" wraps "+GEN+" Kusari-Gama chain around "+MEATN+"'s neck!\n");
    write(
NI+"You wrap your Kusari-Gama chain around "+MEATN+"'s neck!\n");
    TR(ETP,
MEATN+"'s eyes start to swell and blacken.\n"+
MEATN+"'s dismembered, strangled corpse falls to the floor.\n");
    MYWEP->mod_totaldam(MEAT->query_hp());
    say(
NI+TPN+" raises "+GEN+" Kusari-Gama in victory!\n");
    write(
NI+"You raise your Kusari-Gama in victory!\n");
return 1;
   }
 
  if(F == 1) {
kusari_tangle();
    say(
NI+TPN+" leaps high into the air!\n"+
NI+TPN+" brings "+GEN+" Kusari-Gama ripping down through "+MEATN+"'s chest!\n");
    write(
NI+"You leap high into the air!\n"+
NI+"You bring your Kusari-Gama ripping down through "+MEATN+"'s chest!\n");
    TR(ETP,
MEATN+"'s blood flies everywhere!\n");
    MYWEP->mod_totaldam(MEAT->query_hp());
    write(
NI+"You raise your Kusari-Gama in victory!\n");
    say(
NI+TPN+" raises "+GEN+" Kusari-Gama in victory!\n");
return 1;
   }
 
  if(F == 2) {
    say(
NI+TPN+" sneers in contempt for "+GEN+" pitiful opponent.\n"+
NI+TPN+" tosses "+GEN+" Kusari-Gama spinning high into the air!\n");
    write(
NI+"You sneer in contempt for your pitiful opponent.\n"+
NI+"You toss your Kusari-Gama spinning high into the air!\n");
   TR(ETP,
TPN+"'s Kusari-Gama begins to exude a hideous greenish glow...\n"+
TPN+"'s Kusari-Gama strikes down toward "+MEATN+"!\n");
   TR(ETP,
MEATN+" screams in absolute terror!\n"+
NI+"The glowing Kusari-Gama wraps up around "+MEATN+"'s body!\n");
   TR(ETP,
MEATN+"'s eyes grow wide as the Kusari-Gama blade spins up...\n"+
"SHLIIIIIIPPPPPPPP!!!!!!\n");
   TR(ETP,
MEATN+"'s headless body slumps to the ground.\n");
    MYWEP->mod_totaldam(MEAT->query_hp());
    write(
NI+"You raise your Kusari-Gama in victory!\n");
    say(
NI+TPN+" raises "+GEN+" Kusari-Gama in victory!\n");
return 1;
   }
 
  if(F == 3) {
gama_chop();
    TR(ETP,
MEATN+" looks down and tries to catch the intestines as they cascade out...\n");
    write(
NI+"You end "+MEATN+"'s suffering with a decapitating chop!\n");
    say(
NI+TPN+" ends "+MEATN+"'s suffering with a decapitating chop!\n");
    TR(ETP,
MEATN+"'s headless, disemboweled body falls to the ground.\n");
    MYWEP->mod_totaldam(MEAT->query_hp());
    write(
NI+"You raise your Kusari-Gama in victory!\n");
    say(
NI+TPN+" raises "+GEN+" Kusari-Gama in victory!\n");
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
    MYWEP->mod_totaldam(MEAT->query_hp());
    write(
NI+"You raise your Kusari-Gama in victory!\n");
    say(
NI+TPN+" raises "+GEN+" Kusari-Gama in victory!\n");
return 1;
   }
}
 
check_extra() {
  int bi, bl;
  bi = GOB->query_bion_on();
  bl = GOB->query_blad_on();
  if(bi && RAN(45) < GLEV) {
    write("~##~ Bionics power your attack ~##~\n");
    MYWEP->mod_totaldam(RAN(GLEV));
  }
  if(bl && RAN(30) < GLEV) {
    write("~##~ Blades merge into your attack ~##~\n");
    MYWEP->mod_totaldam(RAN(ARTR/2));
  }
  if(GOB->item_weplink())  MYWEP->mod_totaldam(GOB->item_weplink());
  return 1;
}

ninja_damage(object ob) {
  int MAX, mhp, dmg;
  MAX = 50;
  mhp = ob->query_hp();
  dmg = TOT;
  if(dmg > 50) dmg = 50;
  if(dmg >= mhp) dmg = mhp - 1;
  if(ob->is_player()) {
    ob->add_hit_point(-dmg);
    return 1;
  }
  ob->hit_player(dmg);
  return 1;
}
