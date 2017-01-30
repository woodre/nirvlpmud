/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Phish area
//  Function:     NPC
//  Create Date:  2004.08.27
//  Last Edit:    2004.09.03 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/ph/phdefine.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

#define NM HIW+"Millie Grace"+NORM

id(str) { return (::id(str) || str == "pHiShMOB"); }

reset(arg)  {
  int x, y;
  object sheet, coins;

  ::reset(arg);
  if(arg) return;

  sheet = clone_object(OBJ+"sheetmusic.c");
  y = 1 + random(3);
  for(x = 0; x < y; x++) move_object(sheet, this_object());
  
  coins = clone_object("obj/money");
  coins->set_money(4400 + random(1200));
  move_object(coins, this_object());

  set_name("Millie Grace");
  set_alt_name("millie");
  set_alias("grace");
  set_race("human");
  set_gender("female");
  set_short(NM);
  set_long(
    "\n");
  set_level(20);
  set_hp(525);
  set_heal(2,2);
  set_al(900);
  set_wc(30); 
  set_ac(15);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat(NM+" begins to sing Amazing Grace.\n"); 
    load_chat("A lovely voice carries through the air.\n");
    load_chat(NM+" stops singing and looks at you.\n");
    load_chat("With her eyes closed, "+NM+" starts an unfamiliar tune.\n");
    load_chat("Clearing her throat, "+NM+" says, \"This tune is called 'Wading in the Velvet Sea'.\"\n");
  set_a_chat_chance(20);
    load_a_chat("Your ears almost burst as "+NM+" hits a high note.\n");
    load_a_chat(NM+" ducks her attacker's strike.\n");
    load_a_chat("Quicker than you can say holy Icculus, "+NM+" puts her attacker in a headlock.\n");
    load_a_chat(NM+" lifts her attacker high above the ground and slams them to the floor.\n");
    load_a_chat("Swinging hard, "+NM+" barely misses hitting you in the jaw.\n");
/*
//  SPELL ATTACKS:
//  slice :::::::::: 10% chance 15-25 physical damage to random player 
*/
  add_spell("slice",
    "\t"+NM+" swings a piece of sheet music at you.  You yelp in\n"+
    "\tpain as it slices you on the nipple, drawing blood!\n",
    ""+NM+" slices #CTN# on one of #TP# nipples.  #CTN# yelps in pain!\n",
    10, "15-25", "physical", 6); 
}

monster_died() {  
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
  tell_room(environment(this_object()),
    "\n\n"+NM+" tries to hit one last high note, but collapses dead instead.");
    return 1;
}

