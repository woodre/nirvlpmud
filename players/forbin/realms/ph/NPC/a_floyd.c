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

#define NM NORM+YEL+"Floyd"+NORM

id(str) { return (::id(str) || str == "pHiShMOB"); }

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("floyd");
  set_alt_name("chimpanzee");
  set_alias("chimp");
  set_race("animal");
  set_gender("male");
  set_short("A chimpanzee named "+NM+" (evil)");
  set_long(
    "\n");
  set_level(20);
  set_hp(475);
  set_al(-777);
  set_wc(30); 
  set_ac(18);
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

