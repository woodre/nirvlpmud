/*
 *      File:                   /players/jareel/armor/chaos/woods2/chaos_belt.c
 *      Function:               This is part of the full chaos set
 *      Author(s):              Jareel@Nirvana
 *      Copyright:              Copyright (c) 2006 Jareel
 *                                      All Rights Reserved.
 *      Source:                 8/11/06
 *      Approved by:            
 *      Notes:                  This is the belt piece for the Chaos set
 *      Properties:             AC 2
 *      Full Set:               Nothing
 *      Full Forged Set:        Nothing
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
#define NAME HIK+"Dark "+NORM+RED+"Cha"+HIR+"os "+HIK+"Belt"+NORM

string *Armor_pieces;


reset(arg) 
{
  ::reset(arg);

  set_name("chaos belt");
  set_ac(2); 
  set_value(1200);
  set_weight(1);
  set_type("belt");
  set_short(NAME);
  set_long(
    "\n"+
    "\n"+
    "\n"+
    "\n");
  /* Put the id's for your special armors required in here */

  Armor_pieces = ({ "chaos_armor", "chaos_amulet", "chaos_helm", "chaos_boots", "chaos_gloves", "chaos_chest", "chaos_shield", "chaos_misc", "chaos_pants", "chaos_ring", "chaos_underwear", "chaos_earring", "chaos_bracers", "chaos_necklace", "chaos_cloak", "chaos_belt" });
  }

status id(string arg) { return ( ::id(arg) || arg == "chaos_belt" || arg == "belt" || arg == "sash" || arg == "chaos belt"); }

status check_full_set() {
  int i;

  if(!USER) return 0; /* verte, damn noobs, heh */
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
    return (NAME+"      ("+NORM+HIG+"Set of Chaos"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(NAME+" (worn)");

  return NAME;
}
