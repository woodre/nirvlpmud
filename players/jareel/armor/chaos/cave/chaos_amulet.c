/*
 *      File:                   /players/jareel/armor/chaos/woods2/chaos_amulet.c
 *      Function:               This is part of the full chaos set
 *      Author(s):              Jareel@Nirvana
 *      Copyright:              Copyright (c) 2006 Jareel
 *                                      All Rights Reserved.
 *      Source:                 8/11/06
 *      Approved by:            
 *      Notes:                  This is the amulet for the Chaos set
 *      Properties:             Spirit 0,80,0 (This protects vs Mondar/Londros/Special attcks)
 *      Full Set:               Nothing
 *      AC Value:               0
 *                                              
 *      Change History:
 */

/* 
 * Function name:  
 * Description:    
 * Arguments:      
 * Returns:        
 */

#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
#define NAME HIK+"Dark "+NORM+RED+"Cha"+HIR+"os "+HIK+"Amulet"+NORM
#define CCC HIK+"<("+HIR+"*"+HIK+")>"+NORM

string *Armor_pieces;


reset(arg) 
{

  ::reset(arg);

  set_name("chaos amulet");
  set_params("physical",0,0,0);
  set_params("Jareel",0,80,"spirit_pro"); /* Only usefull in my area */
  set_ac(0);
  set_value(1200);
  set_weight(1);
  set_type("amulet");
  set_short(NAME);
  set_long(
    "Dark obsidian polished to a mirror finish, this disc reflects spiritual energy.\n");

  /* Put the id's for your special armors required in here */

  Armor_pieces = ({ "chaos_armor", "chaos_amulet", "chaos_helm", "chaos_boots", "chaos_gloves", "chaos_chest", "chaos_shield", "chaos_misc", "chaos_pants", "chaos_ring", "chaos_underwear", "chaos_earring", "chaos_bracers", "chaos_necklace", "chaos_cloak", "chaos_belt" });
     }

status id(string arg) { return ( ::id(arg) || arg == "chaos_amulet" || arg == "amulet" || arg == "chaos amulet"); }

status check_full_set() {
  int i;

  if(!USER) return 0; 
  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if (!t || !((status)t->query_worn()))
      return 0;
  }
  return 1;
}

string short() {

  if (check_full_set())
    return (NAME+"    ("+NORM+HIG+"Set of Chaos"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(NAME+" (worn)");

  return NAME;
}

do_special(owner) {
  int i;
  if(!ATT || random(1000) > 51) /* hits 5% of the time VS NPC only */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }
  if(ATT->is_npc())
    ATT->heal_self(-(1+random(5)));
      else ATT->hit_player(1+random(5), "other|evil");
  tell_room(environment(USER),
   ""+HIK+" <("+HIR+"*"+NORM+HIK+")>"+HIK+" Fury washes over "+environment()->query_name()+"'s body "+NORM+HIK+" <("+HIR+"*"+NORM+HIK+")>\n"+NORM);
  return 0;
}

spirit_pro(){   /* 80 resistance vs allied spirit attacks in Jareels area */
    write(MAG+"\n       ***Spirit energy is absorbed by the Amulet***\n\n"+NORM);
  return 1;
}
