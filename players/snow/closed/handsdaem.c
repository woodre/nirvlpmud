/*CyberNinja Guild weapon- Unarmed combat daemon master*/
 
#define TP this_player()
#define TO this_object()
#define ETO ENV(TO)
#define ETP ENV(TP)
#define TPN CAP(TP->query_name())
#define ETON ETO->query_name()
#define GOB present("CyberNinja Implants",TP)
#define GLEV GOB->query_guild_lev()
#define ARTR GOB->query_art_level()
#define MEAT TP->query_attack()
#define MEATN CAP(MEAT->query_real_name())
#define GEN TP->query_possessive()
#define RAN random
#define CAP capitalize
#define TR tell_room
#define ENV environment
#define CO call_other
#define NI "*~*"
 
side() {
  int Z;
Z = random(2);
  if(Z == 1) return "left";
  if(Z == 0) return "right";
}
 
offer_hands() {
    write(
"You meditate and lose the power of the Emperors.\n");
destruct(present("Hands",TP));
return 1;
}
 
weapon_hit() {
    int W;
W = RAN(70)+ RAN(ARTR*2);
  if(W > 105) {
hands_aura();
     }
  if(W > 97 && W < 106)  {
hands_throat_blow();
     }
  if(W > 90 && W < 98)  {
hands_strike();
     }
  if(W > 80 && W < 91)  {
hands_head_smash();
     }
  if(W > 70 && W < 81)  {
hands_multi_hit();
     }
  if(W > 60 && W < 71)  {
hands_leg_sweep();
     }
  if(W > 50 && W < 61)  {
hands_kick();
     }
  if(W > 40 && W < 51)  {
hands_jab();
     }
  if(MEAT->query_hp() < ARTR) {
hands_finish();
     }
       return;
}
 
hands_jab() {
    int X;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You jab your "+side()+" hand into "+MEATN+"'s ";
stab2 = NI+TPN+" jabs "+GEN+" "+side()+" hand into "+MEATN+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/5)+2));
return 1;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/5)+1));
return 1;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/5)+1));
return 1;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
    say(stab2+"shoulder.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/5)));
return 1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/5)));
return 1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/5)));
return 1;
    }
}
 
hands_leg_sweep() {
   say(
NI+TPN+" whirls with blinding speed.\n"+
NI+TPN+" sweeps "+GEN+" "+side()+" leg behind and through "+MEATN+"'s legs!\n");
   write(
NI+"You whirl with blinding speed.\n"+
NI+"You sweep your "+side()+" leg behind and through "+MEATN+"'s legs!\n");
   TR(ETP,MEATN+"'s legs crumple as "+MEATN+" falls.\n");
   say(
NI+TPN+" spits on "+MEATN+"'s pitiful, prone form.\n");
   write(
NI+"You spit on "+MEATN+"'s pitiful, prone form.\n");
call_other(MEAT,"heal_self",-(RAN(ARTR/4)));
return 1;
}
 
hands_kick() {
    int X;
    string stab1,stab2;
X = RAN(10);
stab1 = NI+"You smash your "+side()+" foot into "+MEATN+"'s ";
stab2 = NI+TPN+" smashes "+GEN+" "+side()+" foot into "+MEATN+"'s ";
  if(X == 0) {
    write(stab1+"head.\n");
    say(stab2+"head.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/7)+2));
return 1;
    }
  if(X == 1) {
    write(stab1+"gut.\n");
    say(stab2+"gut.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/7)+1));
return 1;
    }
  if(X == 2) {
    write(stab1+"chest.\n");
    say(stab2+"chest.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/7)+1));
return 1;
    }
  if(X > 2 && X <5) {
    write(stab1+"shoulder.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/7)));
return 1;
    }
  if(X > 4 && X < 7) {
    write(stab1+"leg.\n");
    say(stab2+"leg.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/7)));
return 1;
    }
  if(X > 6) {
    write(stab1+"arm.\n");
    say(stab2+"arm.\n");
CO(MEAT,"heal_self",-(RAN(ARTR/7)));
return 1;
    }
}
 
hands_multi_hit() {
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
  if(Z == 0) attack = hands_head_smash();
  if(Z == 1) attack = hands_leg_sweep();
  if(Z > 1 && Z < 8) attack = hands_kick();
  if(Z > 7) attack = hands_jab();
return attack;
}
 
hands_head_smash() {
   say(
NI+TPN+" gracefully whirls in close to "+MEATN+".\n"+
NI+TPN+" lifts "+GEN+" "+side()+" elbow smashing into "+MEATN+"'s face!\n");
   write(
NI+"You gracefully whirl in close to "+MEATN+".\n"+
NI+"You lift your "+side()+" elbow smashing into "+MEATN+"'s face!\n");
TR(ETP,NI+"TTTTHHHHHHHUUUUUUCCCCCCCCKKKKKKKKK!!!!!!!!!!\n"+
MEATN+" stumbles backward in a daze.\n");
CO(MEAT,"heal_self",-(RAN(ARTR)));
return 1;
}
 
hands_strike() {
   say(
NI+TPN+" raises "+GEN+" hands to the heavens.\n"+
NI+TPN+"'s hands are wreathed with glowing energy!\n"+
NI+TPN+" plunges "+GEN+" hands into "+MEATN+".\n");
   write(
NI+"You raise your hands to the heavens.\n"+
NI+"Your hands are wreathed in black energy!\n"+
NI+"You plunge your hands into "+MEATN+".\n");
   TR(ETP,MEATN+"'s body writhes in arcs of electricity!\n");
call_other(MEAT,"heal_self",-((ARTR/(RAN(3)+1))+RAN(3)));
return 1;
}
 
hands_throat_blow() {
   say(
NI+TPN+" flips high into the air!\n"+
NI+TPN+" blurs as "+GEN+" descends.\n"+
NI+TPN+"'s hands and feet flash out!\n");
   write(
NI+"You flip high into the air!\n"+
NI+"You blur as you descend.\n"+
NI+"Your hands and feet flash out!\n");
   TR(ETP,MEATN+"'s eyes widen in fear and horror.\n"+
NI+"TTTTHHHHHHUUUUUUUUCCCCCCCCKKKKKKKKKK!!!!!!!!!\n");
   TR(ETP,MEATN+"'s throat appears to be crushed!\n"+
MEATN+" gurgles in helpless pain.\n");
call_other(MEAT,"heal_self",-(RAN(ARTR)+RAN(ARTR/3)));
return 1;
}
 
hands_aura() {
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
CO(MEAT,"heal_self",-((ARTR*2)/(RAN(2)+1)));
CO(TP,"hit_player",RAN(ARTR*2));
return 1;
}
 
hands_finish() {
    int F;
F = RAN(6);
  if(F == 0) {
    say(
NI+TPN+" grabs the battered head of "+MEATN+" and slams it into the ground!\n");
    write(
NI+"You grab "+MEATN+"'s battered head and slam it into the ground!\n");
    TR(ETP,MEATN+"'s head cracks open and grey matter spills forth.\n");
CO(MEAT,"heal_self",-(ARTR+1));
    say(
NI+TPN+" kneels in prayer for "+GEN+" victory.\n");
    write(
NI+"You kneel in prayer for your victory.\n");
return 1;
  }
  if(F == 1) {
    TR(ETP,MEATN+" stumbles in a daze.\n");
    say(
NI+TPN+" jumps at "+MEATN+"'s head!\n");
    write(
NI+"You jump at "+MEATN+"'s head!\n");
    TR(ETP,"CRACK!\n"+
MEATN+"'s broken head lolls at an unnatural angle.\n"+
MEATN+" thuds to the ground!\n");
CO(MEAT,"heal_self",-(ARTR+1));
    say(
NI+TPN+" kneels in prayer for "+GEN+" victory.\n");
    write(
NI+"You kneel in prayer for your victory.\n");
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
NI+"You break "+MEATN+"'s neck with one quick, expert twist!\n");
   say(
NI+TPN+" breaks "+MEATN+"'s neck with one quick, expert twist!\n");
   TR(ETP,
MEATN+"'s lifeless body slumps to the ground.\n");
CO(MEAT,"heal_self",-(ARTR+1));
    say(
NI+TPN+" kneels in prayer for "+GEN+" victory.\n");
    write(
NI+"You kneel in prayer for your victory.\n");
return 1;
   }
 
  if(F == 3) {
    write(
NI+"You thrust your "+side()+" hand into "+MEATN+"'s chest!\n");
    say(
NI+TPN+" thrusts "+GEN+" "+side()+" hand into "+MEATN+"'s chest!\n");
    TR(ETP,
MEATN+" looks down in numb disbelief...\n");
    write(
NI+"You rip out "+MEATN+"'s heart and hold it in the air!\n");
    say(
NI+TPN+" rips out "+MEATN+"'s heart and holds it in the air!\n");
    TR(ETP,
MEATN+"'s heartless body falls to the ground.\n");
    say(
NI+TPN+" offers the heart to "+GEN+" Emperors.\n");
    write(
NI+"You offer the heart to your Emperors.\n");
    TR(ETP,"The heart bursts into flame and disappears.\n");
CO(MEAT,"heal_self",-(ARTR+1));
    say(
NI+TPN+" kneels in prayer for "+GEN+" victory.\n");
    write(
NI+"You kneel in prayer for your victory.\n");
return 1;
  }
  if(F == 4) {
    say(
NI+MEATN+" bows to "+TPN+" in defeat...\n"+
MEATN+" kneels on the ground...\n");
    write(
NI+"You step forward and smash "+MEATN+"'s head between your hands.\n"+
NI+"You salute the body of your honorable foe.\n");
    say(
NI+TPN+" steps forward and smashes "+MEATN+"'s head between "+GEN+" hands.\n"+
NI+TPN+" salutes the body of "+GEN+" honorable foe.\n");
    TR(ETP,
NI+MEATN+"'s body flops to the floor.\n");
CO(MEAT,"heal_self",-(ARTR+1));
    say(
NI+TPN+" kneels in prayer for "+GEN+" victory.\n");
    write(
NI+"You kneel in prayer for your victory.\n");
return 1;
   }
  if(F == 5) {
    TR(ETP,
MEATN+" staggers from pain and exhaustion....\n");
hands_multi_hit();
hands_multi_hit();
hands_multi_hit();
    TR(ETP,
MEATN+"'s battered body falls to the ground, twitches a bit, then is still.\n");
CO(MEAT,"heal_self",-(ARTR+1));
    say(
NI+TPN+" kneels in prayer for "+GEN+" victory.\n");
    write(
NI+"You kneel in prayer for your victory.\n");
return 1;
   }
}
