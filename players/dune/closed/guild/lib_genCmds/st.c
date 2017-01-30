#include "../DEFS.h"

#define STRIKES ({"chop","forearm","finger_jab","side_kick","reverse_kick","backfist","drop_kick","palm_thrust","fierce_punch","head_clap","elbow_jab","knee","roundhouse","thrust_kick","uppercut","lock_and_punch","choke_grab","lock_and_twist","rapid_fist_strike","rapid_kick","lock_and_elbow","lock_and_throw","pressure_point"})

status main(string str) { return 0; }


/* this function should have no return type in its declaration */
static_main(string str)
{
  string side, Name, where, rmess, mymess;
  string gen, att, who, has, tpp;
  object g_ob, targ, ob;
  int dam, rand_dam, maxdam, cost, artlev, ran, yards;
  int xdam, sdmg, randnum, hp;
  int slev, level;

  if (!str)
  {
    write("Usage: st <attack> <who>\n");
    return 1;
  }

  if (!sscanf(str,"%s %s",att,who))
  {
    if (!MEAT)
    {
      write("Usage: st <attack> <who>\n");
      return 1;
    }
    who = MEAT->query_real_name();
    att = str;
  }

  if (TP->query_spell_dam())
  {
    IPTP->add_spellscast();
    write("You are already using a martial arts attack.\n");
    return 1;
  }

  if (str == IPTP->query_prevstrike())
  {
    write("You must vary your martial attacks.\n");
    return 1;
  }

  if (!valid_strike(att, TP->query_level()))
  {
    write("You don't know the "+att+" attack.\n");
    return 1;
  }

  ob = TP;

  targ = present(who,environment(ob));
  if(!targ)
  {
    write("You see no '"+who+"' to strike...\n");
    return 1;
  }

  g_ob = present("implants", ob);
  artlev = g_ob->query_art_level();
  gen = ob->query_possessive();
  Name = targ->query_name();
  yards = (random(7))+10;

  ran = (random(2))+1;
  if (ran == 1) side = "left";
  if (ran == 2) side = "right";

  where = randhit();

  switch(att)
  {
case "chop":
  mymess = "You make a knife-hand and chop "+Name+" "+where+".\n";
  rmess = OPN+" makes a knife-hand and chops "+Name+" "+where+".\n";
  slev = 1;
  level = 5;
  dam = random(10)+3; cost = 8; break;
case "forearm":
  mymess = "You quickly thrust your forearm upwards, snapping "+Name+"'s\n"+
           "head painfully backwards.\n";
  rmess = OPN+" quickly thrusts "+gen+" forearm upwards, snapping "+Name+"'s\n"+
          "head painfully backwards.\n";
  slev = 1;
  level = 5;
  dam = random(10)+3; cost = 8; break;
case "finger_jab":
  mymess = "You fuse your fingers together and thrust them "+where+
        " of "+Name+".\n";
  rmess = OPN+" fuses "+gen+" fingers together and thrusts them "+where+
        " of "+Name+".\n";
  slev = 1;
  level = 5;
  dam = random(10)+3; cost = 8; break;
case "side_kick":
  mymess = "You spin sidewards and kick "+Name+" "+where+".\n";
  rmess = OPN+" spins sidewards and kicks "+Name+" "+where+".\n";
  slev = 2;
  level = 5;
  dam = random(12)+4; cost = 10; break;
case "reverse_kick":
  mymess = "You turn completely around and back-kick "+Name+" "+where+".\n";
  rmess = OPN+" turns completely around and back-kicks "+Name+" "+where+".\n";
  slev = 2;
  level = 5;
  dam = random(12)+4; cost = 10; break;
case "backfist":
  mymess = "You snap your "+side+" wrist and hit "+Name+" "+where+".\n";
  rmess = OPN+" snaps "+gen+" "+side+" wrist and hits "+Name+" "+where+".\n";
  slev = 2;
  level = 5;
  dam = random(12)+4; cost = 10; break;
case "drop_kick":
  mymess = "You acrobatically drop to the ground and kick upwards.\n"+
           "You hit "+Name+" "+where+"!\n";
  rmess = OPN+" acrobatically drops to the ground and kicks upwards.\n"+
      OPN+" hit "+Name+" "+where+"!\n";
  slev = 3;
  level = 5;
  dam = random(16)+4; cost = 12; break;
case "palm_thrust":
  mymess = "You thrust out your "+side+" palm with all your bodily might,\n"+
           "and hit "+Name+" "+where+"!\n";
  rmess = OPN+" thrusts out "+gen+" "+side+" palm with all \n"+
          gen+" bodily might and hits "+Name+" "+where+"!\n";
  slev = 4;
  level = 5;
  dam = random(16)+5; cost = 13; break;
case "fierce_punch":
  mymess = "You punch "+Name+" "+where+" with one hell of a whopper!\n";
  rmess = OPN+" punches "+Name+" "+where+" with one hell of a whopper!\n";
  slev = 5;
  level = 5;
  dam = random(18)+5; cost = 14; break;
case "head_clap":
  mymess = "You smack both your hands over "+Name+"'s ears.\n";
  rmess = OPN+" smacks both "+gen+" hands over "+Name+"'s ears.\n";
  slev = 6;
  level = 10;
  dam = random(18)+6; cost = 15; break;
case "elbow_jab":
  mymess = "You force your "+side+" elbow at "+Name+", "+where+"!\n";
  rmess = OPN+" forces "+gen+" "+side+" elbow at "+Name+", "+where+"!\n";
  slev = 6;
  level = 10;
  dam = random(18)+6; cost = 15; break;
case "knee":
  mymess = "You force your "+side+" knee "+where+" of "+Name+".\n";
  rmess = OPN+" forces "+gen+" "+side+" knee "+where+" of "+Name+".\n";
  slev = 7;
  level = 10;
  dam = random(20)+6; cost = 16; break;
case "roundhouse":
  mymess = "You spin around your "+side+" foot and kick "+Name+" "+
         where+"!\n";
  rmess = OPN+" spins around "+gen+" "+side+" foot and kicks "+Name+" "+
         where+"!\n";
  slev = 7;
  level = 10;
  dam = random(20)+6; cost = 16; break;
case "thrust_kick":
  mymess = "You force all your weight into your kick, and hit\n"+
           Name+" "+where+"!\n";
  rmess = OPN+" forces all "+gen+" weight into "+gen+" kick, and hits\n"+
          Name+" "+where+"!\n";
  slev = 8;
  level = 10;
  dam = random(20)+7; cost = 17; break;
case "uppercut":
  mymess = "You smoothly smack "+Name+" "+where+" with a "+side+
        "uppercut!\n";
  rmess = OPN+" smoothly smacks "+Name+" "+where+" with a "+side+
        "uppercut!\n";
  slev = 9;
  level = 10;
  dam = random(20)+8; cost = 18; break;
case "lock_and_punch":
  mymess = "You grapple "+Name+" and connect a solid punch "+where+"!\n";
  rmess = OPN+" grapples "+Name+" and connects a solid punch "+where+"!\n";
  slev = 10;
  level = 10;
  dam = random(20)+9; cost = 19; break;
case "choke_grab":
  mymess = "You lock "+Name+"'s throat in a vice-like grip!\n";
  rmess = OPN+" grabs "+Name+"'s throat in a vice-like grip!\n";
  slev = 11;
  level = 15;
  dam = random(20)+10; cost = 20; break;
case "lock_and_twist":
  mymess = "You grab "+Name+" "+where+" and twist all the juices out!\n";
  rmess = OPN+" grabs "+Name+" "+where+" and twists all the juices out!\n";
  slev = 12;
  level = 15;
  dam = random(20)+11; cost = 21; break;
case "rapid_fist_strike":
  mymess = "You deliver several rapid fist strikes "+where+" of "+Name+"!!\n";
  rmess = OPN+" delivers several rapid fist strikes "+where+" of "+Name+"!!\n";
  slev = 13;
  level = 15;
  dam = random(20)+12; cost = 22; break;
case "rapid_kick":
  mymess = "You kick "+Name+" a few times, a few more, and a few more!\n"+
           "Whoa, and they all hit "+where+"!\n";
  rmess = OPN+" kicks "+Name+" a few times, a few more, and a few more!\n"+
          "Whoa, and they all hit "+where+"!\n";
  slev = 14;
  level = 15;
  dam = random(20)+13; cost = 23; break;
case "lock_and_elbow":
  mymess = "You cleverly lock "+Name+" and force your elbow "+where+"!\n";
  rmess = OPN+" cleverly locks "+Name+" and forces "+gen+" elbow "+where+"!\n";
  slev = 15;
  level = 15;
  dam = random(20)+14; cost = 24; break;
case "lock_and_throw":
  mymess = "With a quick maneuver, you take hold and toss "+Name+" "+
        yards+" yards!\n";
  rmess = "With a quick maneuver, "+OPN+" takes hold and tosses "+Name+" "+
        yards+" yards!\n";
  slev = 16;
  level = 15;
  dam = random(20)+15; cost = 25; break;
case "pressure_point":
  mymess = "You strike "+Name+" in a VITAL pressure point!\n";
  rmess = OPN+" strikes "+Name+" in a VITAL pressure point!\n";
  slev = 17;
  level = 19;
  dam = random(20)+18; cost = 30; break;
  }

  /* Certain places hurt more than others */
  if(where == "right in the kisser") dam = dam + 3;
  if(where == "in the groin") dam = dam + 2;
  if(where == "in the neck") dam = dam + 1;
  if(where == "in the torso") dam = dam - 1;
  if(where == "in the chest") dam = dam - 2;

  if(artlev < slev)
  {
    write("You must train to use this attack.\n");
    return 1;
  }

  if(TP->query_level() < level)
  {
    write("You must gain player levels to use this attack.\n");
    return 1;
  }

  if(ob->query_ghost())
  {
    write("Your insubstantial body does not allow physical attacks.\n");
    return 1;
  }

  if(targ->query_ghost())
  {
    TE(ob, "Your attack swishes through thin air.\n");
    return 1;
  }

  if(!gotsp(TP, cost)) return 1;

/* added by wocket 11.10.00
    -2 for Renegade
   1/4 for defense mode
    +1 for attack mode
*/
  if(IPTP->query_nohonor()) dam -= 2;
  if(IPTP->query_attack_mode() == 2) { if(dam) dam = dam / 4; }
  if(IPTP->query_attack_mode() == 1) dam += 1;
  if(dam < 0) dam = 0;

  ob->spell_object(targ,str,dam,cost,mymess,
      RED+"--------------------------------"+OFF+"\n",rmess);
  IPTP->set_prevstrike(str);
  return 1;
}


string randhit()
{
  int num;
  num = random(12);
  switch(num)
  {
    case 0..3: return "in the chest";
    case 4..7: return "in the torso";
    case 8..9: return "in the neck";
    case 10:   return "in the groin";
    case 11:   return "right in the kisser";
    default:   return "in the chest";
  }

/* This should not happen */
  return "in the chest";
}


int valid_strike(string str)
{
  if(member_array(str, STRIKES) == -1) return 0;
  else return 1;
}
