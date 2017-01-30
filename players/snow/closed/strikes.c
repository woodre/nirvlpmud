strike(string str) {
  string side, name, Name, where, rmess, mymess;
  string gen, att, who, has, tpp;
  object g_ob, targ, ob;
  int dam, rand_dam, maxdam, cost, artlev, ran, yards;
  int xdam, sdmg, randnum, percent, fail, hp;
  int slev;
  if(!str) { write("Usage: st <attack> <who>\n"); return 1; }
  if(!sscanf(str,"%s %s",att,who)) {
    if(!MEAT) { write("Usage: st <attack> <who>\n"); return 1; }
    who = MEAT->query_real_name();
    att = str;
  }
  if(!valid_strike(att, TP->query_level()) ) {
    write("You don't know the "+att+" attack.\n"); return 1; }
  ob = TP;
  targ = present(who,environment(ob));
  if(!targ) {
    write("You see no '"+who+"' to strike...\n");
  return 1; }
  if(!valid_attack(targ, ob)) {
    if(check_location(ob, targ)) { }
    else {
      TE(ob,"You cannot attack "+WHO+".\n");
      return; }
    }
    if(targ->is_player() && !check_location(ob, targ)) {
      TE(ob,"You cannot attack "+WHO+".\n");
      return; }
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
  if(ob->query_ghost()) {
    write("Your insubstantial body does not allow physical attacks.\n");
    return 1;
  }
  if(targ->query_ghost()) {
    TE(ob, "Your attack swishes through thin air.\n");
    return 1; }

  randnum = random(100) + 1;
  fail = 100 - ((4 + artlev) * 4);
  if(randnum <= fail) {
    if(random(3) == 1) {
      /* total of 5% to 20% of failure */
      TE(ob, "()You fumble your attack()\n");
      return 1; }
    }

  rand_dam = dam + (artlev * 2);
  maxdam = rand_dam + dam;
  dam += random(rand_dam);
  cost += random(rand_dam);
  if(dam > 40) {
    cost = cost - (dam - 40)/5;  dam = 40; }
  if(maxdam > 50) maxdam = 50;

  if(dam > S10DAM_CAP) dam = S10DAM_CAP;

  ob->spell_object(targ,str,dam,cost,mymess,
      RED+"--------------------------------"+OFF+"\n",rmess);
if(dam < maxdam / 4) write(Name+" lets out a soft whimper.\n");
if(dam>maxdam/4 && dam<maxdam*3/4) write(Name+" screams in pain!\n");
if(dam >= maxdam *3/4) write(Name+" is DEVASTED by your attack!\n");

  if(targ) {
    if(!ob->query_attack()) ob->attack_object(targ);
    if(!targ->query_attack()) targ->attack_object(ob);
    }
  return 1;
}
