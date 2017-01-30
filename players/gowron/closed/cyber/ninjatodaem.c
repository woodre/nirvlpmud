/*CyberNinja Guild weapon- Ninja-To daemon master*/
 
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
 
int totaldam;
set_totaldam(td) { totaldam = td; }
query_totaldam() { return totaldam; }
add_totaldam(int num) { totaldam += num; }
 
 
offer_ninjato(arg) {
  object ob;
  int value;
value = RAN(20)+40;
   if(arg == "ninjato" || arg == "Ninja-To" || arg == "ninja-to") {
    say(
TPN+" raises "+GEN+" Ninja-To high into the air.\n");
    write(
"You raise your Ninja-To high into the air.\n");
    TR(ETP,"A black vortex envelops and consumes the Ninja-To.\n");
/*
    write(
"You receive "+value+" coins for your offering.\n");
CO(TP,"add_money",value);
*/
  destruct(PRE("ninjato",TP));
return 1;
  }
}
 
weapon_hit() {
    int W;
W = RAN(72)+ RAN(ARTR*5)/2;
  if(W > 105) {
nin_aura();
     }
  if(W > 97 && W < 106)  {
nin_throat_blow();
     }
  if(W > 90 && W < 98)  {
nin_back_strike();
     }
  if(W > 80 && W < 91)  {
nin_head_slap();
     }
  if(W > 65 && W < 81)  {
nin_multi_hit();
     }
  if(W > 60 && W < 66)  {
nin_face_smash();
     }
  if(W > 50 && W < 61)  {
nin_gut_punch();
     }
  if(W > 40 && W < 51)  {
nin_stab();
     }
  if(MEAT->query_hp() < ARTR) {
nin_finish();
     }
  check_extra();
  if(random(4) == 0) ninja_damage(MEAT);
  set_totaldam(0);
  if(W > 70 && W < 91)  {
    say(
"Fire burns along the blade of "+TPN+"'s Ninja-To.\n");
    write(
"Fire burns along the blade of your Ninja-To.\n");
return ARTR/4;
     }
  if(W > 90)  {
    say(
"Black lightning crackles along the blade of "+TPN+"'s Ninja-To.\n");
    write(
"Black lightning crackles along the blade of your Ninja-To.\n");
return ARTR/3;
     }
       return;
}
 
nin_stab() {
    int X;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You stab "+MEATN+" in the ";
stab2 = NI+TPN+" stabs "+MEATN+" in the ";
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
 
nin_gut_punch() {
   say(
NI+TPN+" jabs the butt of "+GEN+" Ninja-To into "+MEATN+"'s midsection.\n");
   write(
NI+"You jab the butt of your Ninja-To into "+MEATN+"'s midsection.\n");
   TR(ETP,MEATN+" doubles over in pain.\n");
    totaldam += RAN(ARTR/4)+2;
return 1;
}
 
nin_face_smash() {
   say(
NI+TPN+" smashes the guard of "+GEN+" Ninja_To into "+MEATN+"'s face!\n");
   write(
NI+"You smash the guard of your Ninja-To into "+MEATN+"'s face!\n");
   TR(ETP,MEATN+" tries to blink back tears.\n");
    totaldam += (ARTR/2)+1;
return 1;
}
 
nin_multi_hit() {
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
  if(Z == 0) attack = nin_face_smash();
  if(Z > 0 && Z < 4) attack = nin_gut_punch();
  if(Z > 3) attack = nin_stab();
return attack;
}
 
nin_head_slap() {
   say(
NI+TPN+" elegantly steps inside "+MEATN+"'s guard.\n"+
NI+TPN+" slaps "+MEATN+"'s head with the flat of "+GEN+" Ninja-To's blade.\n");
   write(
NI+"You elegantly step inside "+MEATN+"'s guard.\n"+
NI+"You slap "+MEATN+"'s head with the flat of your Ninja-To's blade.\n");
   TR(ETP,MEATN+" looks dazed.\n");
    totaldam += RAN(4)+2;
nin_face_smash();
   say(
NI+TPN+" sneers and spits on "+MEATN+", then spins away.\n");
   write(
NI+"You sneer and spit on "+MEATN+", then spin away.\n");
return 1;
}
 
nin_back_strike() {
nin_gut_punch();
   say(
NI+TPN+" spins elegantly around "+GEN+" gasping foe.\n"+
NI+TPN+" plunges "+GEN+" Ninja-To into "+MEATN+"'s exposed back.\n");
   write(
NI+"You spin elegantly around your gasping foe.\n"+
NI+"You plunge your Ninja-To into "+MEATN+"'s exposed back.\n");
   TR(ETP,MEATN+" screams in pain.\n");
    totaldam += (ARTR/(RAN(3)+1))+RAN(6);
return 1;
}
 
nin_throat_blow() {
   say(
NI+TPN+"'s Ninja-To blurs into a black streak across your vision.\n");
   TR(ETP,NI+"SSSLLLLIIIIICCCCCCEEEEEE!!!\n"+
NI+TPN+" rips "+GEN+" Ninja-To deep into "+MEATN+"'s throat!\n");
   write(
NI+"You rip your Ninja-To deep into "+MEATN+"'s throat!\n");
   TR(ETP,NI+"Blood spatters everywhere!\n");
    totaldam += RAN(ARTR)+RAN(ARTR/3)+5;
return 1;
}
 
nin_aura() {
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
    totaldam += (ARTR*2);
CO(TP,"hit_player",RAN(ARTR));
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
NI+TPN+" raises "+GEN+" Ninja-To above "+GEN+" head...\n");
    write(
NI+"You raise your Ninja-To above your head...\n");
    TR(ETP,
MEATN+" screams pitifully for mercy!\n");
    say(
NI+TPN+" brings "+GEN+" Ninja-To down upon "+MEATN+" with relish!\n");
    write(
NI+"You bring your Ninjo-To down upon "+MEATN+" with relish for the kill!\n");
    TR(ETP,
NI+"THWACK!\n"+
MEATN+"'s head rolls on the bloody floor.\n");
  totaldam += MEAT->query_hp();
    say(
NI+TPN+" raises "+GEN+" Ninja-To in victory!\n");
    write(
NI+"You raise your Ninja-To in victory!\n");
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
NI+"You bring your Ninja-To up to touch the tender hollow below\n"+
NI+MEATN+"'s chin...\n"+
NI+"You shove the Ninja-To into "+MEATN+"'s brain!\n");
    say(
NI+TPN+" caresses "+MEATN+"'s face... almost tenderly...\n"+
NI+TPN+" brings "+GEN+" Ninja-To up to touch the tender hollow below\n"+
NI+MEATN+"'s chin...\n"+
NI+TPN+" shoves "+GEN+" Ninja-To into "+MEATN+"'s brain!\n");
    TR(ETP,
MEATN+" squirms around on the end of the blade then slides to the floor.\n");
  totaldam += MEAT->query_hp();
    write(
NI+"You raise your Ninja-To in victory!\n");
    say(
NI+TPN+" raises "+GEN+" Ninja-To in victory!\n");
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
NI+"You raise your Ninja-To in victory!\n");
    say(
NI+TPN+" raises "+GEN+" Ninja-To in victory!\n");
return 1;
   }
 
  if(F == 3) {
    write(
NI+"You rip your Ninja-To through "+MEATN+"'s stomach!\n");
    say(
NI+TPN+" rips "+GEN+" Ninja-To through "+MEATN+"'s stomach!\n");
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
NI+"You raise your Ninja-To in victory!\n");
    say(
NI+TPN+" raises "+GEN+" Ninja-To in victory!\n");
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
NI+"You raise your Ninja-To in victory!\n");
    say(
NI+TPN+" raises "+GEN+" Ninja-To in victory!\n");
return 1;
   }
}
 
check_extra() {
  int bi, bl;
  bi = GOB->query_bion_on();
  bl = GOB->query_blad_on();
  if(bi && RAN(45) < GLEV) {
    write("~##~ Bionics power your attack ~##~\n");
    totaldam += RAN(GLEV);
  }
  if(bl && RAN(35) < GLEV) {
    write("~##~ Blades merge with your attack ~##~\n");
    totaldam += RAN(GLEV/2);
  }
  if(GOB->item_weplink()) {
    totaldam += GOB->item_weplink();
  }
  return 1;
}

ninja_damage(object ob) {
  int MAX, mhp, dmg;
  /*
  MAX = 20;
  */
  MAX = TP->query_wc();
  if(MAX > 17) MAX = 17;
  mhp = ob->query_hp();
  dmg = totaldam;
  if(dmg > MAX) dmg = MAX;
  /*
  if(TP->query_alignment() < -200) dmg = dmg + 1;
  if(TP->query_alignment() > 200) dmg = dmg - 2;
  */
  if(dmg >= mhp) dmg = mhp - 1;
  /*
  if(ob->is_player()) {
    ob->add_hit_point(-dmg);
    return 1;
  }
  */
  ob->hit_player(dmg);
  return 1;
}
