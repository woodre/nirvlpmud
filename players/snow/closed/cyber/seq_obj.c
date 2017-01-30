/* CyberNinja sequence functions are found here... */

#include "definitions.h"
#include "color.h"

id(str) { return str == "sequenceobj"; }
get() { return 1; }
drop() { return 1; }

object IP(object ob) {
/* This function is similar to a #define, it just
 * returns the guild object on the player specified.
 */
   object guild_object;
   guild_object = present("implants", ob);
   return guild_object;
}

attack_seq(string str) {
/* main code for altering attack sequences */
  int seq, pos, maxpos;
  string att, tempatt, place, gen, oldname, name;
  if(!str) {
    sequenceError();
    return; }
  gen = TP->query_possessive();
  if(!sscanf(str, "%d %s %d", seq, att, pos)) {
    sequenceError();
    return; }
  if(!validSeq(seq)) {
    write("Invalid attack sequence specified.\n");
    write("You do not have attack sequence number "+seq+".\n");
    return; }
  if(sscanf(str, "%d %s", seq, att)) {
    if(att == "clearall") {
      if(seq > 0 && seq < 4) {
       erase_all_seq(seq);
       write("Attack sequence "+seq+" cleared.\n");
       say(TPN+" rethinks "+gen+" plan of attack.\n");
       IP(TP)->save_me();
       return; }
    else sequenceError();
    return; }
    }
  if(sscanf(str, "%d %s %s", seq, att, name)) {
    if(att == "name") {
       if(!sscanf(str, "%d %s %s", seq, att, name)) {
         sequenceError(); return; }
       oldname = attackName(seq, name, 0);
       write("You give a new name to attack sequence #"+seq+".\n");
       if(oldname) write("It used to be named "+oldname+".\n");
       write("It is now known as "+name+"!\n");
       attackName(seq, name, 1);
       IP(TP)->save_me();
       return; }
    }
  if(sscanf(str, "%d %s %d", seq, att, pos)) {
    tempatt = att;
    if(att != "clear") {
     if(!TOOL->valid_strike(att, TP->query_level()) ) {
      write("You don't know an attack called '"+tempatt+"'.\n");
     return; } }
    if( (seq == 1 && pos > 3) || (seq == 2 && pos > 4) ||
        (seq == 3 && pos > 5) ) {
      write("Attack position out of range.\n");
      return; }
    if(att == "clear") {
      add_seq(seq,pos,"none");
      write("Position "+pos+" in attack sequence "+seq+" cleared.\n");
      say(TPN+" thinks upon a "+gen+" plan of attack.\n");
      IP(TP)->save_me();
      return; }
    add_seq(seq,pos,att);
    write("Position "+pos+" in attack sequence "+seq+
                    " changed to "+att+".\n");
    say(TPN+" alters "+gen+" plan of attack.\n");
    IP(TP)->save_me();
    return; }
  sequenceError();
  return 1;
}
 
add_seq(int seq, int num, string att) {
  if(seq == 1) {
    if(num == 1) IP(TP)->set_seq1_1(att);
    if(num == 2) IP(TP)->set_seq1_2(att);
    if(num == 3) IP(TP)->set_seq1_3(att);
  return 1; }
  if(seq == 2) {
    if(num == 1) IP(TP)->set_seq2_1(att);
    if(num == 2) IP(TP)->set_seq2_2(att);
    if(num == 3) IP(TP)->set_seq2_3(att);
    if(num == 4) IP(TP)->set_seq2_4(att);
  return 1; }
  if(seq == 3) {
    if(num == 1) IP(TP)->set_seq3_1(att);
    if(num == 2) IP(TP)->set_seq3_2(att);
    if(num == 3) IP(TP)->set_seq3_3(att);
    if(num == 4) IP(TP)->set_seq3_4(att);
    if(num == 5) IP(TP)->set_seq3_5(att);
  return 1; }
  sequenceError();
  return 0;
}
 
erase_all_seq(int seq) {
  if(seq == 1) {
    IP(TP)->set_seq1_1("none");
    IP(TP)->set_seq1_2("none");
    IP(TP)->set_seq1_3("none");
  return 1; }
  if(seq == 2) {
    IP(TP)->set_seq2_1("none");
    IP(TP)->set_seq2_2("none");
    IP(TP)->set_seq2_3("none");
    IP(TP)->set_seq2_4("none");
  return 1; }
  if(seq == 3) {
    IP(TP)->set_seq3_1("none");
    IP(TP)->set_seq3_2("none");
    IP(TP)->set_seq3_3("none");
    IP(TP)->set_seq3_4("none");
    IP(TP)->set_seq3_5("none");
  return 1; }
  sequenceError();
  return 0;
}
 
attackName(int seq, string new, int flag) {
/* flag = 0 is just query */
/* flag = 1 is set */
string name;
switch(seq) {
  case 1: if(flag == 0) {
            name = IP(TP)->query_seq1name();
            return name; }
          IP(TP)->set_seq1name(new);
          break;
  case 2: if(flag == 0) {
            name = IP(TP)->query_seq2name();
            return name; }
          IP(TP)->set_seq2name(new);
          break;
  case 3: if(flag == 0) {
            name = IP(TP)->query_seq3name();
            return name; }
          IP(TP)->set_seq3name(new);
          break;
  }
return name;
}
 
int validSeq(int seq) {
  int artlev, allowedSeqs;
  if(seq <= 0) return 0;
  artlev = ((int)IP(TP)->query_art_level());
  if( (artlev >= 1) && (artlev <= 3) ) allowedSeqs = 1;
  if( (artlev >= 4) && (artlev <= 6) ) allowedSeqs = 2;
  if(artlev >= 7) allowedSeqs = 3;
  if(seq > allowedSeqs) return 0;
  else return 1;
}
 
executeSequence(string str) {
 object sob;
 string who, name, gen, jumble;
 int seq, i, rnd, counter;
 if(!str) {
   write("Usage: att [#sequence]\n");
   write("You must specify which attack sequence to execute.\n");
   write("You must be already in combat.\n");
   return 1; }
 gen = TP->query_possessive();
 if(!sscanf(str, "%d", seq)) {
   write("Usage: att [#sequence]\n");
   write("You must specify which attack sequence to execute.\n");
   write("You must be already in combat.\n");
   return 1; }
 if(!TP->query_attack() ||
    ENV(TP->query_attack()) != ENV(TP)) {
   write("You must be in combat to use attack sequences.\n");
   return 1; 
 if(!validSeq(seq)) {
   write("Invalid attack sequence specified.\n");
   write("You do not have attack sequence number "+seq+".\n");
   return 1; }
 if(IP(TP)->query_sequence_check()) {
   write("You are too tired to initiate another attack maneuver.\n");
   return 1; }
   }
 IP(TP)->set_sequence_check(1);
 write("Sequence "+seq+" initiated.\n");
 name = attackName(seq, name, 0);
 write("You perform your "+name+" maneuver!\n\n");
 say(TPN+" unleashes "+gen+" "+name+" maneuver!\n\n");
 IP(TP)->seq_beat(seq);
 return 1;
}
 
show_sequence(string str) {
  string name;
  int seq, i, num;
  if(!str) {
    write("Which sequence do you want displayed.\n");
    return; }
  if(!sscanf(str, "%d", seq)) {
    write("Usage: sequence [#sequence]\n");
    return; }
  if(!validSeq(seq)) {
    write("Invalid attack sequence specified.\n");
    write("You do not have attack sequence number "+seq+".\n");
    return; }
  name = attackName(seq, name, 0);
  write(TPN+"'s attack sequence # "+seq+".\n");
  if(name) write("The "+BOLD+name+OFF+" maneuver.\n");
  write("______________________________________________\n");
  write("POSITION\tATTACK\n");
  if(seq == 1) {
    if(IP(TP)->query_seq1_1())
      write("[1]  "+IP(TP)->query_seq1_1()+"\n");
    if(IP(TP)->query_seq1_2())
      write("[2]  "+IP(TP)->query_seq1_2()+"\n");
    if(IP(TP)->query_seq1_3())
      write("[3]  "+IP(TP)->query_seq1_3()+"\n");
  }
  if(seq == 2) {
    if(IP(TP)->query_seq2_1())
      write("[1]  "+IP(TP)->query_seq2_1()+"\n");
    if(IP(TP)->query_seq2_2())
      write("[2]  "+IP(TP)->query_seq2_2()+"\n");
    if(IP(TP)->query_seq2_3())
      write("[3]  "+IP(TP)->query_seq2_3()+"\n");
    if(IP(TP)->query_seq2_4())
      write("[4]  "+IP(TP)->query_seq2_4()+"\n");
  }
  if(seq == 3) {
    if(IP(TP)->query_seq3_1())
      write("[1]  "+IP(TP)->query_seq3_1()+"\n");
    if(IP(TP)->query_seq3_2())
      write("[2]  "+IP(TP)->query_seq3_2()+"\n");
    if(IP(TP)->query_seq3_3())
      write("[3]  "+IP(TP)->query_seq3_3()+"\n");
    if(IP(TP)->query_seq3_4())
      write("[4]  "+IP(TP)->query_seq3_4()+"\n");
    if(IP(TP)->query_seq3_5())
      write("[5]  "+IP(TP)->query_seq3_5()+"\n");
  }
  write("______________________________________________\n");
}
 
sequenceError() {
  write("You have performed an invalid operation. Check the\n"+
        "Cyber files on sequences.\n");
  return 1;
}

strike(string me, string str) {
  string side, name, Name, where, rmess, mymess;
  string gen, att, who, has, tpp;
  object g_ob, targ, ob;
  int dam, rand_dam, maxdam, cost, artlev, ran, yards;
  int xdam, sdmg, randnum, percent, fail, hp;
  int slev;
  if(!me || !str) return 1;
  ob = find_player(me);
  targ = ob->query_attack();
  if(!targ || ENV(targ) != ENV(ob) ) return 1;
  if(!TOOL->valid_attack(targ, ob)) {
    if(TOOL->check_location(ob, targ)) { }
      return; }
  if(targ->is_player() &&
   !TOOL->check_location(ob, targ)) return;
  if(ob->query_ghost()) {
    TE(ob,"Your insubstantial body does not allow physical attacks.\n");
    return 1;
  }
  if(targ->query_ghost()) {
    TE(ob, "Your attack swishes through thin air.\n");
    return 1; }
 
  g_ob = present("implants", ob);
  artlev = g_ob->query_art_level();
  if (ob->query_spell_point() < 1) {
    TE(ob,"You are low on power.\n");
    return;}
  gen = ob->query_possessive();
  name = targ->query_name();
  Name = CAP(name);
  yards = (random(7))+10;
  ran = (random(2))+1;
  if(ran == 1) side = "left";
  if(ran == 2) side = "right";
  where = randhit();
  switch(att) {
case "chop":
  mymess = "You make a knife-hand and chop "+Name+" "+where+".\n";
  rmess = OPN+" makes a knife-hand and chops "+Name+" "+where+".\n";
  slev = 1;
  dam = 3; cost = 3; break;
case "forearm":
  mymess = "You quickly thrust your forearm upwards, snapping "+Name+"'s\n"+
           "head painfully backwards.\n";
  rmess = OPN+" quickly thrusts "+gen+" forearm upwards, snapping "+Name+"'s\n"+
          "head painfully backwards.\n";
  slev = 1;
  dam = 2; cost = 2; break;
case "finger_jab":
  mymess = "You fuse your fingers together and thrust them "+where+
        " of "+Name+".\n";
  rmess = OPN+" fuses "+gen+" fingers together and thrusts them "+where+
        " of "+Name+".\n";
  slev = 1;
  dam = 3; cost = 3; break;
case "side_kick":
  mymess = "You spin sidewards and kick "+Name+" "+where+".\n";
  rmess = OPN+" spins sidewards and kicks "+Name+" "+where+".\n";
  slev = 1;
  dam = 3; cost = 3; break;
case "reverse_kick":
  mymess = "You turn completely around and back-kick "+Name+" "+where+".\n";
  rmess = OPN+" turns completely around and back-kicks "+Name+" "+where+".\n";
  slev = 2;
  dam = 7; cost = 7; break;
case "backfist":
  mymess = "You snap your "+side+" wrist and hit "+Name+" "+where+".\n";
  rmess = OPN+" snaps "+gen+" "+side+" wrist and hits "+Name+" "+where+".\n";
  slev = 2;
  dam = 6; cost = 6; break;
case "drop_kick":
  mymess = "You acrobatically drop to the ground and kick upwards.\n"+
           "You hit "+Name+" "+where+"!\n";
  rmess = OPN+" acrobatically drops to the ground and kicks upwards.\n"+
      OPN+" hit "+Name+" "+where+"!\n";
  slev = 2;
  dam = 7; cost = 7; break;
case "palm_thrust":
  mymess = "You thrust out your "+side+" palm with all your bodily might,\n"+
           "and hit "+Name+" "+where+"!\n";
  rmess = OPN+" thrusts out "+gen+" "+side+" palm with all \n"+
          gen+" bodily might and hits "+Name+" "+where+"!\n";
  slev = 2;
  dam = 6; cost = 6; break;
case "fierce_punch":
  mymess = "You punch "+Name+" "+where+" with one hell of a whopper!\n";
  rmess = OPN+" punches "+Name+" "+where+" with one hell of a whopper!\n";
  slev = 3;
  dam = 10; cost = 10; break;
case "head_clap":
  mymess = "You smack both your hands right between "+Name+"'s head.\n";
  rmess = OPN+" smacks both "+gen+" hands right between "+Name+"'s head.\n";
  slev = 3;
  dam = 11; cost = 11; break;
case "elbow_jab":
  mymess = "You force your "+side+" elbow at "+Name+", "+where+"!\n";
  rmess = OPN+" forces "+gen+" "+side+" elbow at "+Name+", "+where+"!\n";
  slev = 3;
  dam = 10; cost = 10; break;
case "knee":
  mymess = "You force your "+side+" knee "+where+" of "+Name+".\n";
  rmess = OPN+" forces "+gen+" "+side+" knee "+where+" of "+Name+".\n";
  slev = 3;
  dam = 11; cost = 11; break;
case "roundhouse":
  mymess = "You spin around your "+side+" foot and kick "+Name+" "+
         where+"!\n";
  rmess = OPN+" spins around "+gen+" "+side+" foot and kicks "+Name+" "+
         where+"!\n";
  slev = 4;
  dam = 13; cost = 13; break;
case "thrust_kick":
  mymess = "You force all your weight into your kick, and hit\n"+
           Name+" "+where+"!\n";
  rmess = OPN+" forces all "+gen+" weight into "+gen+" kick, and hits\n"+
          Name+" "+where+"!\n";
  slev = 4;
  dam = 12; cost = 12; break;
case "uppercut":
  mymess = "You smoothly smack "+Name+" "+where+" with a "+side+
        "uppercut!\n";
  rmess = OPN+" smoothly smacks "+Name+" "+where+" with a "+side+
        "uppercut!\n";
  slev = 4;
  dam = 12; cost = 12; break;
case "lock_and_punch":
  mymess = "You grapple "+Name+" and connect a solid punch "+where+"!\n";
  rmess = OPN+" grapples "+Name+" and connects a solid punch "+where+"!\n";
  slev = 5;
  dam = 15; cost = 15; break;
case "choke_grab":
  mymess = "You grab "+Name+"'s throat and choke like there's no tomorrow!\n";
  rmess = OPN+" grabs "+Name+"'s throat and chokes like there's no tomorrow!\n";
  slev = 5;
  dam = 15; cost = 15; break;
case "lock_and_twist":
  mymess = "You grab "+Name+" "+where+" and twist all the juices out!\n";
  rmess = OPN+" grabs "+Name+" "+where+" and twists all the jout!\n";
  slev = 5;
  dam = 13; cost = 13; break;
case "rapid_fist_strike":
  mymess = "You deliver a few thousand fist strikes "+where+" of "+Name+"!!\n";
  rmess = OPN+" delivers a few thousand fist strikes "+where+" of "+Name+"!!\n";
  slev = 6;
  dam = 16; cost = 16; break;
case "rapid_kick":
  mymess = "You kick "+Name+" a few times, a few more, and a few more!\n"+
           "Whoa, and they all hit "+where+"!\n";
  rmess = OPN+" kicks "+Name+" a few times, a few more, and a few more!\n"+
          "Whoa, and they all hit "+where+"!\n";
  slev = 6;
  dam = 18; cost = 18; break;
case "lock_and_elbow":
  mymess = "You cleverly lock "+Name+" and force your elbow "+where+"!\n";
  rmess = OPN+" cleverly locks "+Name+" and forces "+gen+" elbow "+where+"!\n";
  slev = 6;
  dam = 16; cost = 16; break;
case "lock_and_throw":
  mymess = "With a quick maneuver, you take hold and toss "+Name+" "+
        yards+" yards!\n";
  rmess = "With a quick maneuver, "+OPN+" takes hold and tosses "+Name+" "+
        yards+" yards!\n";
  slev = 7;
  dam = 24; cost = 24; break;
case "pressure_point":
  mymess = "You strike "+Name+" in a VITAL pressure point!\n";
  rmess = OPN+" strikes "+Name+" in a VITAL pressure point!\n";
  slev = 7;
  dam = 24; cost = 24; break;
    }
 
  /* Certain places hurt more than others */
  if(where == "right in the kisser") dam = dam + 3;
  if(where == "in the groin") dam = dam + 2;
if(where == "in the neck") dam = dam + 1;
  if(where == "in the torso") dam = dam - 1;
  if(where == "in the chest") dam = dam - 2;
 
  if(artlev < slev) { write("You must train to use this attack.\n");
    return 1; }
  if(artlev > 16) artlev = 16;
  hp = targ->query_hp();
  if(ob->query_sp() < (4 * cost / 3)) {
        TE(ob, "you become weak and fall flat on your face!\n");
        return 1; }
  if(dam >= hp) {
    TE(ob, "^You pull your blow^\n");
    /* Attacks can never kill a foe */
    return 1; }
  randnum = random(100) + 1;
  fail = 100 - ((4 + artlev) * 5);
  if(randnum <= fail && random(3) == 1) {
/* total of 3% to 25% of failure */   
    TE(ob, "()You fumble your attack()\n");
    return 1; }
 
  rand_dam = dam + (artlev * 2);
  maxdam = 45; /* MAXIMUM DAMAGE OF SPELL_OBJECT 45 */
  dam += random(rand_dam);
  cost += random(rand_dam);
  if(dam > maxdam) {
/* Max of 9 cost reduction -> 5% chance at max art level */
  cost = cost - (dam - 45)/4;  dam = maxdam; }
 
  ob->spell_object(targ,str,dam,cost,mymess,
      RED+"--------------------------------"+OFF+"\n",rmess);
  if(dam < maxdam / 4)
    TE(ob, Name+" lets out a soft whimper.\n");
  if(dam>maxdam/4 && dam<maxdam*3/4)
    TE(ob, Name+" screams in pain!\n");
  if(dam >= maxdam *3/4)
    TE(ob, Name+" is DEVASTED by your attack!\n");
  if(targ) {
    if(!targ->query_attack()) targ->attack_object(ob); }
 return 1;
}
 
string randhit() {
  int a;
  string msg;
  a = random(11) + 1;
  switch(a) {
    case 1:   msg = "right in the kisser"; break;
    case 2:   msg = "in the neck"; break;
    case 3:   msg = "in the groin"; break;
    case 4:   msg = "in the right shoulder"; break;
    case 5:   msg = "in the left shoulder"; break;
    case 6:   msg = "in the chest"; break;
    case 7:   msg = "in the chest"; break;
    case 8:   msg = "in the left leg"; break;
    case 9:   msg = "in the right leg"; break;
    case 10:  msg = "in the torso"; break;
    case 11:  msg = "right in the behind"; break;
    }
  return msg;
}
 
