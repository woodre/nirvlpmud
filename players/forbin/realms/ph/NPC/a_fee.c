/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Phish area
//  Function:     NPC
//  Create Date:  2004.08.27
//  Last Edit:    2004.08.27 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/ph/phdefine.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

#define NM NORM+HIK+"F"+HIW+"e"+HIK+"e"+NORM

id(str) { return (::id(str) || str == "pHiShMOB"); }

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("fee");
  set_alt_name("weasel");
  set_alias("buddist");
  set_race("weasel");
  set_gender("male");
  set_short("A buddist weasel named "+NM);
  set_long(
    "\n");
  set_level(20);
  set_hp(525);
  set_al(500);
  set_wc(15); /* low wc cause spells are cast each round */
  set_ac(15);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("\n");
  set_a_chat_chance(20);
    load_a_chat("\n");  
/*
//  SPELL ATTACKS:
//  Oak, Southern Yellow Pine, Birch, Ash, Sycamore, Maple
//  One :::::::::: 6% chance 15-35 physical damage to random player 
//  One :::::::::: 6% chance 10-25 physical damage to random player 
*/
  add_spell("ToweringOakAcornAttack",
    ""+NM+" assumes the $Y$Towering Oak$N$ stance before launching\n"+
    "into you with a series of $HW$Acorn Attacks$N$.\n",
    ""+NM+" assumes the $Y$Towering Oak$N$ stance before launching\n"+
    "into #CTN# with a series of $HW$Acorn Attacks$N$.\n",
    6, "15-35", "physical", 6); 
  add_spell("ToweringOakFallenLeaves",
    "Standing quickly into the $Y$Towering Oak$N$ posture, "+NM+" yells\n"+
    "and attacks you with the $HG$Strike of the Fallen Leaves$N$.\n",
    "Standing quickly into the $Y$Towering Oak$N$ posture, "+NM+" yells\n"+
    "and attacks #CTN# with the $HG$Strike of the Fallen Leaves$N$.\n",
    6, "15-30", "physical", 6);
  add_spell("SouthernYellowPineLimbDrop",
    "With a startling quick move, "+NM+" suprises you with a devastating\n"+
    "$HY$Limb Drop Chop$N$ out of the $HY$Southern Yellow Pine$N$ pose.\n",
    "With a startling quick move, "+NM+" suprises #CTN# with a devastating\n"+
    "$HY$Limb Drop Chop$N$ out of the $HY$Southern Yellow Pine$N$ pose.\n",
    6, "5-20", "physical", 6);
  add_spell("SouthernYellowPineRoughBark",
    "Quickly bounding out of the $HY$Southern Yellow Pine$N$ stance, "+NM+"\n"+
    "bloodies your nose with a $HK$Rough Bark Bash$N$ elbow to the face.\n",
    "Quickly bounding out of the $HY$Southern Yellow Pine$N$ stance, "+NM+"\n"+
    "bloodies #CTN#'s nose with a $HK$Rough Bark Bash$N$ elbow to #TP# face.\n",
    6, "20-25", "physical", 6);
  add_spell("FullOfNutsHickoryDoubleFeldTrunkCrunch",
    "With arms waving wildly through the air, "+NM+" assumes the $HW$Full\n"+
    "of Nuts Hickory$N$ posture.  Raring back, he punches you smack, dab\n"+
    "in the center of your stomach with a $R$Double Feld Trunk Crutch$N$.\n",
    "With arms waving wildly through the air, "+NM+" assumes the $H$Full\n"+
    "of Nuts Hickory$N$ posture.  Raring back, he punches #CTN# smack, dab\n"+
    "in the center of #TP# stomach with a $R$Double Feld Trunk Crutch$N$.\n",
    4, "40-55", "physical", 6);      
  add_spell("FullOfNutsHickoryShadySapplingKicks",
    ""+NM+" launches himself out of the $HW$Full of Nuts Hickory$N$ stance.\n"+
    "You scream as "+NM+" riddles you with several $G$Shady Sappling Kicks$N$.\n"+
    ""+NM+" kicks you hard.\n"+
    ""+NM+" kicks you with devastating force.\n"+
    ""+NM+" kicks you hard.\n"+    
    ""+NM+" kicks you hard.\n"+    
    ""+NM+" kicks you with a loud CRUNCH.\n",    
    ""+NM+" launches himself out of the $HW$Full of Nuts Hickory$N$ stance.\n"+
    "#CTN# screams as "+NM+" riddles #TO# with several $G$Shady Sappling Kicks$N$.\n",
    6, "5-40", "physical", 6);                 
}

monster_died() {  
  object treasure;  
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
  tell_room(environment(this_object()),
    "\n\nWith the killing blow, a chunk of scales is knocked from the Salamite.\n\n");
  treasure = clone_object(OBJ+"salamite_scales.c");
  move_object(treasure,environment(this_object()));
    return 1;
}

