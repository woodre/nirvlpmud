/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Caves of the Salamite
//  Function:     NPC
//  Create Date:  2004.06.05
//  Last Edit:    2004.09.22 -Forbin
//  Notable Changes:    
//    2004.06.15 -added bunch of debugging/logging stuff to see what
//                  kind of damage this mob does [Forbin]
//    2004.06.23 -capped experience given when greater than 300,000 
//                experience - approved by Verte [Forbin]
//    2004.07.22 -wc/ac/hp bonus calculations fixed, so capped exp isn't
//                really neccessary, but leaving it just in case [Forbin]
//    2004.09.22 -all the spell attack calculations for bonuses were still
//                kinda screwy, so I scrapped the majority, and used the
//                new add_spell capability to do most of the attacks
*/ 

#include "/players/forbin/realms/salam/salamdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

object Crown, Weapon;
int ThrownOut, Bezerk;
int WC_Count, AC_Count;
int Regular_Round, Bezerk_Round;
int Healing_Total;
int FlameTell;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Crown = clone_object(OBJ+"coal_crown.c"); 
  move_object(Crown, this_object());
  command("wear crown", this_object());   
  Weapon = clone_object(OBJ+"neruumsh.c"); 
  move_object(Weapon, this_object());
  command("wield axe", this_object()); 
  set_name("Sebassis");
  set_alt_name("sebassis");
  set_alias("king");
  set_race("salamite");
  set_gender("male");
  set_short(HIR+"Sebassis,"+NORM+RED+" the "+HIR+"Sala"+NORM+RED+"mite"+HIR+" King"+NORM);
  set_long(
    "  This dark red giant dwarfs you.  Black, obsidian armor covers most\n"+
    "of his body; what remains visible is covered in bright red scales.  He\n"+
    "holds a large axe in his left hand and wears a crown of black coal on\n"+ 
    "his head.  A large red triangle, pointing downward, has been painted\n"+
    "onto his armored chest.  It would be very wise to tread lightly in his\n"+
    "glorious presence.\n");
  set_level(25);
  set_hp(1400+random(200));
  set_al(-999);
  set_wc(46);
  set_wc_bonus(41);
  set_ac(22);
  set_heal(2,1);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("Sebassis roars: \"Why do you disturb me?\"\n");
    load_chat("The King glares at you...\n");
    load_chat("Sebassis points at you and says, \"Leave why you still can!\"\n");
    load_chat("Sebassis growls: \"Who let you in here?\"\n");
  set_a_chat_chance(20);
    load_a_chat("Sebassis thunders: \"Where are my guardsmen?\"\n");
    load_a_chat("Sebassis kicks you in the chest.\n");
    load_a_chat("The Salamite King swings hard, knocking you to the ground.\n");  
    load_a_chat("The Salamite King roars loudly.\n");
    load_a_chat("Sebassis draws back Neruumsh, ready to strike.\n");
  ThrownOut = 0;
  Bezerk = 0;
  WC_Count = 0;
  AC_Count = 0;
  Regular_Round = 0;
  Bezerk_Round = 0;
  Healing_Total = 0;
  FlameTell = 0;
/*
//  SPELL ATTACKS:
//  darkmagic ::::: 20% chance 30-70 other|evil damage to random attacking player 
//  lavastrike :::: 16% chance 15-30 other|fire damage to random attacking player 
//  toss :::::::::: 16% chance 15-30 physical damage to random attacking player 
//  fireball :::::: 16% chance 15-30 other|fire damage to random attacking player 
//  inferno :::::::  8% chance 15-30 other|fire damage to all attacking players
*/
  add_spell("darkmagic",
    "\nSebassis waves his hand at you...\n"+
    "     "+HIK+"DaRK mAgICk"+NORM+" channels into you, wracking you with pain...\n\n",
    "Sebassis waves his hand at #CTN#...\n"+
    "     #CTN#'s body is wracked with pain by "+HIK+"dArk MaGicK"+NORM+"...\n",
    20, "30-70", "other|evil", 6); 
  add_spell("lavastrike",
    "\nSebassis points at the lava pit...\n"+
        "     "+HIR+"MOLTEN LAVA"+NORM+" leaps forth and douses you...\n\n",
    "Sebassis points at the lava pit...\n"+
        "     #CTN# is covered with "+HIR+"LAVA"+NORM+" as molten rock leaps forth...\n",
    16, "40-100", "other|fire", 6); 
  add_spell("toss",
    HIW+"Sebassis grabs you by your throat and slams you to the ground!"+NORM+"\n",
    "Sebassis grabs #CTN# by #TP# throat and slams #TO# to the ground!\n",
    16, "50-130", "physical", 6); 
  add_spell("fireball",
    RED+"Sebassis conjures a smoldering ball of fire! He throws it into the\n"+
    "center of the room, where it ignites a firestorm\n"+
    "                  Fire rages all about you...\n",    
    RED+"Sebassis conjures a smoldering ball of fire! He throws it into the\n"+
    "center of the room, where it ignites a firestorm\n"+
    "                  Fire rages all about #CTN#...\n", 
    16, "133-200", "other|fire", 6); 
  add_spell("inferno",
    "    You are engulfed in a torrent of flames...\n",
    "Sebassis raises his hands high into the air...\n",
    8, "180-230", "other|fire", 3, "flame");                  
}

init(){
  ::init();
}

query_salamite_king() { return 1; }

heart_beat() {
  ::heart_beat();
  if(!environment())  return ;
  if(!attacker_ob) return ;
  FlameTell = 0;
  if(!Bezerk) Regular_Round ++;
  else Bezerk_Round ++;
  if(weapon_class < 46) weapon_class = 46;
  if(armor_class < 22 && !Bezerk) armor_class = 22;
  WC_Count += weapon_class; /* used to calc average wc for calculate_worth() */
  AC_Count += armor_class;  /* used to calc average ac for calculate_worth() */
  if(hit_point < 800 && !ThrownOut) throw_out();
  if(hit_point < 600 && !Bezerk) bezerk();
  if(hit_point < 100) { hit_point += 10; Healing_Total += 10; }
  ::heart_beat();  
  if(attacker_ob == this_object()) {
    stop_fight();
    stop_fight();
  }
}

/* 
//  ***********************************************************************
//  Function:    stop_fight 
//  Description: players cannot stop the fight
//  Arguments:   none
//  ***********************************************************************
*/

stop_fight() {
  if(this_player()->query_level() > 20 || this_player() == this_object()) {
    ::stop_fight();
    return 1;
  }
  return;
}

/* 
//  ***********************************************************************
//  Function:    throw_out 
//  Description: called when hit_point < 800 (only called once), throws all
//                 attacking players from room and summons a mob to attack
//  Arguments:   none
//  ***********************************************************************
*/

throw_out() {
  object ob, target, mob;
  string where;
  if(!environment(this_object()) || !((object)this_object()->query_attack()))
    return;
  mob = clone_object(NPC+"brute.c");
  move_object(mob, RMS+"cots07.c");
  ob = first_inventory(environment(this_object()));
  while(ob) {
    if (ob->query_attack() == this_object()) {
      target = ob;
      ob = next_inventory(ob);
      switch(random(4)) {
        case 0: where = "throat"; break;
        case 1: where = "head"; break;
        case 2: where = "arm"; break;
        case 3: where = "leg"; break;
      }
      tell_object(target, 
        HIW+"\n\nSebassis grabs you by your "+where+" and launches you out of the room!"+NORM+"\n\n\n");
      tell_room(environment(),
        "Sebassis grabs "+target->query_name()+" by "+this_player()->query_possessive()+" "+where+" and launches "+this_player()->query_objective()+" out of the room!\n", ({target}));
      target->move_player("flying through the air#"+RMS+"cots07.c");
      tell_object(target,
        HIW+"A salamite brute rushes into the room to protect the king.\n"+NORM);
      target->attacked_by(mob);
    }
    else
      ob = next_inventory(ob);
  }
  ThrownOut = 1;
  return;  
}

/* 
//  ***********************************************************************
//  Function:    bezerk
//  Description: called when hit_point < 600 (only called once), 
//                 weapon_class doubles, armor_class halves, heals
//                 100+random(200) hps heal_rate and heal_intv set to 0
//  Arguments:   none
//  WC_Bonus:    - handled in calculate_worth()
//  ***********************************************************************
*/

bezerk() {
  if(!environment(this_object()) || !((object)this_object()->query_attack()))
    return;
  tell_room(environment(),
    HIB+"\n\t\t   Feeling the battle has turned,\n"+
    "\t\tSebassis flies into a BeZErK rAgE!"+NORM+"\n\n");
  weapon_class *= 2;
  armor_class /= 2;
  hit_point += 100 + random(200);
  Healing_Total += 200; /* average healing total */
  heal_rate = 0;
  heal_intv = 0;
  Bezerk = 1;
}

/* 
///////////////////////////////////////////////////////////////////////////
//  Function:    calculate_worth 
//  Description: used to adjust for bezerk() and healing changes
//  Arguments:   none
//  Notes:       bezerk:  because bezerk() modifies heal_rate and heal_intv
//                          I use the ratio of rounds with set_heal(2,1) to
//                          rounds with set_heal(0,0) to get a ac_bonus
//                        bezerk() also modifies wc and ac, so they are
//                        averaged by total rounds and used to reset wc/ac
//               healing: special cases of healing are handled with a total
//                          count of healing and set accordingly (healing
//                          when hit_point < 100 in heart_beat() and 
//                          healing during bezerk())
///////////////////////////////////////////////////////////////////////////
*/

flame(object target,object room,int damage) {
  if(!FlameTell) {
    tell_room(environment(),
      HIR+"\n               (  .      )\n"+
      "           )           (              )\n"+
      "                 .  '   .   '  .  '  .\n");
    tell_room(environment(),
      HIR+"        (    , )       (.   )  (   ',    )\n"+
      "         .' ) ( . )    ,  ( ,     )   ( .\n"+
      "      ). , ( .   (  ) ( , ')  .' (  ,    )\n");
    tell_room(environment(),
      HIR+"     (_,) . ), ) _) _,')  (, ) '. )  ,. (' )\n"+
      "    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n"+NORM);  
      FlameTell = 1;
  }
}

calculate_worth(){
  int healing_mod;

  if((Regular_Round + Bezerk_Round) > 0) {
    healing_mod = (((2 * Regular_Round) * 3) / (Regular_Round + Bezerk_Round));
    ac_bonus += healing_mod;

  /* following two lines average the wc & ac for more accurate account of wc & ac */
  weapon_class = (WC_Count / (Regular_Round + Bezerk_Round));
  armor_class = (AC_Count / (Regular_Round + Bezerk_Round));
  } 

  hp_bonus += Healing_Total;

  return (::calculate_worth());
}

monster_died() {
  object treasure;
  tell_room(environment(this_object()),
    "\n\nWith the killing blow, a chunk of scales is knocked from Sebassis.\n\n");
  treasure = clone_object(OBJ+"salamite_scales.c");
  move_object(treasure,environment(this_object()));
    return 1;
}
