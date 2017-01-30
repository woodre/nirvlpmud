/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qualtor Miniquest
//  Function:     Armor
//  Create Date:  2005.07.16
//  Last Edit:    2005.07.16 -Forbin
//  Notable Changes:            
*/

#include "/players/forbin/realms/cave/cavedefine.h"

#define CRUSADER_SHIELD HIW+"Crus"+NORM+RED+"ader "+HIR+"("+NORM+RED+"+"+HIR+") "+NORM+RED+"Shi"+HIW+"eld"+NORM

inherit "obj/armor";

int Bonus;

reset(arg) {
  set_name("crusader shield");
  set_alias("shield");
  set_short(CRUSADER_SHIELD);
  set_long(
    "A full length,  white battle shield painted with the insignia of the\n"+
    "crusaders, a red cross emblazened on a white background.  It would make\n"+
    "for great protection in a fight.\n");
  if(Bonus) set_ac(2);
  else set_ac(1);
  set_type("shield");  
  set_weight(1);
  set_value(2000);
}

set_bonus() { Bonus = 1; set_ac(2); }

int do_special(object owner) {
  if(!random(6)) {
    tell_object(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as you block your attacker with the "+
      CRUSADER_SHIELD+"!\n");
    tell_room(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as "+capitalize((string)owner->query_name())+ 
      "blocks "+(string)owner->query_possessive()+" attacker with the "+
      CRUSADER_SHIELD+"!\n", ({ owner}) );
    return 0;
  }
  return 0;
}

locker_arg() { return ""+Bonus; }
locker_init(arg) { Bonus = atoi(arg);  }
restore_thing(str) { restore_object(str); return 1; }
save_thing(str) { save_object(str); return 1; }
generic_object() { return 1; }