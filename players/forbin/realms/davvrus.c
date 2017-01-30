/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Heal shop
//  Function:     NPC to run heal shop 
//  Create Date:  2004.06.06
//  Last Edit:    2004.06.11 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "davvrus_the_monk" || str == "da'vvrus"); }

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Da'vvrus");
  set_alt_name("davvrus");
  set_alias("monk");
  set_race("human");
  set_gender("male");
  set_short("Da'vvrus, Monk of the Order of Gamehenge");
  set_long(
    "  A rather old looking chap stands before you.  Dressed in a thin,\n"+
    "brown cloak, he clasps his hands in front of him as if he is waiting\n"+
    "for something.  The hood of the cloak hangs down his back, with his\n"+
    "flowing, white hair cascading down on top of it.  Bright, green eyes\n"+
    "peer at you with a youthful inquisitiveness that belies his years.\n");
  set_level(20);
  set_hp(900+300);
  set_al(888);
  set_wc(30);
  set_ac(19);
  set_heal(1,1);
  set_dead_ob(this_object());
  set_chat_chance(5);
    load_chat("Da'vvrus asks:  \"Hello there.  How are you?\"\n");
    load_chat("Da'vvrus asks:  \"How are you on such a fine day?\"\n");
    load_chat("Da'vvrus says, \"I know much about the lands of the Wizard Forbin.\"\n");
    load_chat("\"Would you like to purchase some heal items,\" asks Da'vvrus.\n");
    load_chat("\"Would you like to purchase some heal items,\" asks Da'vvrus.\n");
    load_chat("\"My prices are the lowest in the land,\" says Da'vvrus.\n");
    load_chat("\"I also have saddlebags you can purchase.\" says Da'vvrus.\n");    
    load_chat("\"I also have saddlebags you can purchase.\" says Da'vvrus.\n");
    load_chat("\"I also have saddlebags you can purchase.\" says Da'vvrus.\n");
    load_chat("\"The saddlebags I have will hold many, many items.\" says Da'vvrus.\n");        
    load_chat("\"The saddlebags I have will hold many, many items.\" says Da'vvrus.\n");            
    load_chat("\"Saddlebags cost 2000 coins.\" says Da'vvrus.\n");            
    load_chat("Da'vvrus exclaims, \"Forbin's floating crystals have a special purpose!\"\n");
    load_chat("Da'vvrus says, \"Maillot Jaune are a tasty snack, but they are very rich.\"\n");
    load_chat("Da'vvrus says, \"I have some tasty d'Huez leaves that will fill you right up.\"\n");
    load_chat("Da'vvrus says, \"I love the smell of Galibier root.  It is so yummy.\"\n");
    load_chat("Da'vvrus says, \"I could eat Mayias bark all day long.  It's very light, you know.\"\n");
    load_chat("Da'vvrus says, \"Mongie berries will satisfy your hunger.\"\n");                    
    load_chat("Da'vvrus says, \"I've heard that Museeuw will strengthen your spirit.\"\n");    
  set_a_chat_chance(20);
    load_a_chat("Da'vvrus blocks your attack and smacks you in the face...\n");
}

init(){
  ::init();
}

monster_died() {
#ifdef BIGKILLLOG
  mon_log(BIGKILLLOG);
#endif
    return 1;
}

