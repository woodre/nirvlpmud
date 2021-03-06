/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Caves of the Salamite
//  Function:     NPC
//  Create Date:  2004.06.05
//  Last Edit:    2004.06.100 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/ph/phdefine.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "pHiShMOB"); }

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("");
  set_alt_name("");
  set_alias("");
  set_race("");
  set_gender("");
  set_short("");
  set_long(
    "\n");
  set_level(19);
  set_hp(450);
  set_al(-500);
  set_wc(28);
  set_ac(16);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("\n");
  set_a_chat_chance(20);
    load_a_chat("\n");  
/*
//  SPELL ATTACKS:
//  One :::::::::: 6% chance 15-30 physical damage to random player 
//  One :::::::::: 6% chance 10-25 physical damage to random player 
*/
  add_spell("flick",
    "\tThe $HK$Archangel of Shadows$N$ flicks his whip at you.\n"+
    "\tYou feel a burst of pain as it draws blood!\n",
    "The $HK$Archangel of Shadows$N$ flicks his whip at #CTN#,\n"+ 
    "drawing deep lines of blood!\n",
    6, "15-30", "physical", 6); 
  add_spell("flick",
    "\tThe $HK$Archangel of Shadows$N$ flicks his whip at you.\n"+
    "\tYou feel a burst of pain as it draws blood!\n",
    "The $HK$Archangel of Shadows$N$ flicks his whip at #CTN#,\n"+ 
    "drawing deep lines of blood!\n",
    8, "10-25", "physical", 6);        
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

