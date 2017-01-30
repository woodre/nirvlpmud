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

#define NM "Mr. Palmer"

id(str) { return (::id(str) || str == "pHiShMOB"); }

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Mr Palmer");
  set_alt_name("palmer");
  set_alias("mr palmer");
  set_race("human");
  set_gender("male");
  set_short(NM);
  set_long(
    "\n");
  set_level(19);
  set_hp(475);
  set_al(900);
  set_wc(28); 
  set_ac(15);
  set_dead_ob(this_object());  
  set_chat_chance(5);
  load_chats(({ 
    NM+" begins to sing Amazing Grace.\n", 
    "A lovely voice carries through the air.\n",
    NM+" stops singing and looks at you.\n",
    "With her eyes closed, "+NM+" starts an unfamiliar tune.\n", }));
  set_a_chat_chance(20);
  load_a_chats(({ 
    NM+" tosses a ream of paper at you.\n",
    NM+" screams, \"Don't you know how hard accounting is?\".\n",
    "Quicker than you can say holy Icculus, "+NM+" puts her attacker in a headlock.\n",
    NM+" lifts her attacker high above the ground and slams them to the floor.\n", }));
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

catch_tell(string str) {
  string t1, t2, t3;
  object me;
  if(sscanf(str, "%sbows%syou.", t1, t2) == 2) {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("salute_wink", 1, me);
  }
  else if(sscanf(str, "%s arrives.%s\n", t1, t2) == 2) {
    if(!random(2))
      call_out("greeting", 2, find_player(lower_case(t1)));
  }
}

greeting(object you) {
  int z;
  if(you && present(you, environment())) {
    z = random(8);
    switch(z) {    
      if(you()->query_alignment() > 0) {
        case 0..4:
          tell_object(you, 
            NM+" glances up from his work at you.\n");
          tell_room(environment(), 
            NM+" glances up from his work at "+you->query_name()+".\n", ({ you }));
          break;
        case 5:
          tell_room(environment(), 
            NM+" looks around before asking, \"How is the resistance going, "+you->query_name()+"?\"\n");
          break;
        case 6:
          tell_room(environment(),
            NM+" says, \"I should have more money for the resistance shortly, "+you->query_name()+".\"\n");
          break;
        case 7:
          tell_object(you, 
            NM+" smiles and winks at you.\n"+
            "He then exclaims, \"Tell Errand the money will come soon!\"\n");
          tell_room(environment(), 
            ME+" smiles and winks at "+you->query_name()+".\n"+
            "He then says something to "+you->query_name()+".\n", ({ you }));
          break;
      }
      else {
        case 0..4:
          tell_object(you, 
            NM+" looks at you, then hurridly continues to work.\n");
          tell_room(environment(), 
            NM+" looks at "+you->query_name()+", then hurridly continues to work.\n", ({ you }));
          break;
        case 5:
          tell_room(environment(), 
            NM+" wipes his forehead and asks, \"Does his Excellency Wilson wish to see me?\"\n");
          break;
        case 6:
          tell_room(environment(),
            NM+" says, \""+you->query_name()+", tell Lord Wilson I shall be finished shortly.\"\n");
          break;
        case 7:
          tell_room(environment(),
            NM+" rummages through some papers as he works.\n");
          break;        
      }
    }
  }
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

