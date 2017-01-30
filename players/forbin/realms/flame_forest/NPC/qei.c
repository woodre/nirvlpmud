/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest Addition
//  Function:     NPC
//  Create Date:  2005.07.27
//  Last Edit:    2005.07.28 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/flame_forest/ffdefine.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

id(str) 
{ 
  return (::id(str) || str == "qei" || str == "natas'h"
  	                || str == "qei t-uu natas'h"  
  	                || str == "doctor" || str == "witch"  
                    || str == "witch doctor"
                    || str == "blessed by he" 
                    || str == "qei_t-uu_natas'h"); 
}

reset(arg) 
{
  ::reset(arg);
  if(arg) return;
  
  move_object(clone_object(OBJ+"juju.c"), this_object()); 
  
  set_name("Qei");
  set_race("human");
  set_gender("female");
  set_short(CYN+"Qei T-uu Natas'h"+NORM+" (Blessed By He) "+CYN+"["+NORM+"witch-doctor"+CYN+"]"+NORM+" (black-knight)");
  set_long(
    "Qei T-uu Natas'h, or Blessed By He, stands in the middle of\n"+
    "a smoldering fire.  Her eyes are slick with madness and she\n"+
    "chants loudly, rhythmically dancing atop the smoking embers.\n"+
    "Long, black hair hangs to her waist, and lines of white mud\n"+
    "streak her dark face and forehead.  She is naked except for\n"+ 
    "a short skirt of cloth and red scales, and a small trinket of\n"+
    "some sort worn around her neck.\n");  
  set_level(20);
  set_hp(2000);
  set_al(-666);
  set_wc(30);
  set_ac(35);
  set_heal(2,10);
  add_money(2500+random(2000));
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("Qei chants: \"Uk taka gnu mamba!\"\n");
    load_chat("Qei looks up at the sky and yells: \"Uuba Tuuba!\"\n");
    load_chat("Qei tosses bones onto the ground and attempts to read them.\n");
    load_chat("Qei puffs smoke into the air.\n");
  set_a_chat_chance(20);
    load_a_chat("Qei jabs you with a sharpened bone.\n");
    load_a_chat("Qei chants: \"Bunga Bonga Banga!\"\n");
    load_a_chat("Qei tosses bone dust into your face.\n");
/* 
////////////////////////////////////////////////////////////////////////////
// NumNum 
//   15% chance of 10-30 magical damage to main attacker
////////////////////////////////////////////////////////////////////////////
*/   
  add_spell("NumNum",
    "Qei raises her sharpened bone high into the air and chants...\n"+
    " Numnum...\n"+
    "             Numnum...\n"+
    "                          Numnum...\n"+
    "You feel pain shoot throughout your body!\n",
    "Qei raises her sharpened bone high into the air and chants...\n"+
    " Numnum...\n"+
    "             Numnum...\n"+
    "                          Numnum...\n"+
    "#CTN# yells out as pain shoots throughout his body.\n",
    15, "10-30", "magical");     
}
