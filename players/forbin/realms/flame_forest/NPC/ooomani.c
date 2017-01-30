/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest Addition
//  Function:     NPC
//  Create Date:  2005.07.27
//  Last Edit:    2005.07.27 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/flame_forest/ffdefine.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

id(str) 
{ 
  return (::id(str) || str == "ooomani" || str == "rutuu"  
                    || str == "ooomani rutuu"
                    || str == "scout"  
                    || str == "burning arrow"
                    || str == "ooomani_rutuu"); 
}

reset(arg) 
{
  ::reset(arg);
  if(arg) return;
  
  move_object(clone_object(OBJ+"gmoloch.c"), this_object()); 
  command("wear glove", this_object());   
  
  set_name("Ooomani");
  set_race("human");
  set_gender("male");
  set_short(CYN+"Ooomani Rutuu"+NORM+" (Burning Arrow) "+CYN+"["+NORM+"scout"+CYN+"]"+NORM+" (neutral)");
  set_long(
    "Ooomani Rutuu, or Burning Arrow, is a strong man that looks\n"+
    "both wise and young of years.  He stands in a small clearing,\n"+ 
    "slowing rubbing his chin - clearly deep in thought.  He wears\n"+
    "nothing except for a loincloth of cloth and red scales and a\n"+
    "metal glove on his left hand.\n");  
  set_level(21);
  set_hp(1500);
  set_al(0);
  set_wc(25);
  set_ac(55);
  add_money(2000+random(3000));
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("Ooomani says: \"Once I find the Salamites, I'll destroy them.\"\n");
    load_chat("Ooomani picks up a handful of dirt and sniffs it.\n");
    load_chat("Carefully eyeing the ground, Ooomani seems to be tracking something.\n");
    load_chat("Ooomani demands: \"Leave me be!  I've work to do.\"\n");
  set_a_chat_chance(20);
    load_a_chat("Ooomani smashes you in the face with his gloved hand.\n");
    load_a_chat("Ooomani is surrounded by a healing aura.\n");
    load_a_chat("Deftly avoding your attack, Ooomani strikes you in the side.\n");
    load_a_chat("Ooomani leaps back, avoiding your clumsy attack.\n");
/* 
////////////////////////////////////////////////////////////////////////////
// Trine 
//   10% chance of 10-30 other|mental damage to main attacker
////////////////////////////////////////////////////////////////////////////
*/   
  add_spell("Trine",
    "Ooomani outstretches #MP# palm towards you and intones...\n"+
    "$C$            ^         ^         ^         ^\n"+"      "+
    "$HW$[$C$T$HW$]$C$ / + \\ "+
    "$HW$[$C$R$HW$]$C$ / + \\ "+
    "$HW$[$C$I$HW$]$C$ / + \\ "+
    "$HW$[$C$N$HW$]$C$ / + \\ "+
    "$HW$[$C$E$HW$]$C$\n"+
    "          -----     -----     -----     -----\n$N$"+
    "You are encased in a pyramidal prison of sonic fury...\n"+
    "You are $HR$DESTROYED$N$ by Ooomani's $C$Trine$N$ spell.\n",
    "Ooomani outstretches #MP# palm towards #CTN# and intones...\n"+
    "#CTN# is $HR$DESTROYED$N$ by Ooomani's $C$Trine$N$ spell.\n",
    10, "10-30", "other|mental");     
}