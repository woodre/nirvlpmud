/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     NPC
 *  Create Date:  2004.06.05
 *  Last Edit:    2004.06.100 -Forbin
 *  Notable Changes:            
 */ 

#include "/players/forbin/realms/salam/salamdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("shardak");
  set_alt_name("shard");
  set_gender("male");
  set_short(RED+"Shardak"+NORM);
  set_long("");
  set_level(19);
  set_hp(450);
  set_al(-500);
  set_wc(28);
  set_ac(16);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("The Salamite keeps a close watch...\n");
    load_chat("The Salamite hisses at you...\n");
  set_a_chat_chance(20);
    load_a_chat("The Salamite tosses you to the ground...\n");
    load_a_chat("With lightning reflexes, the Salamite punches you in the face....\n");
    load_a_chat("The Salamite swings hard...barely missing you...\n");  
}

is_player() { return 1;}
query_npc() { return 0;}
query_interactive() { return 1;}
