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

#define CRUSADER_BREASTPLATE HIW+"Crus"+NORM+RED+"ader "+HIR+"("+NORM+RED+"+"+HIR+") "+NORM+RED+"Breast"+HIW+"plate"+NORM

inherit "obj/armor";

int Bonus;

reset(arg) {
  set_name("breastplate");
  set_alias("plate");
  set_short(CRUSADER_BREASTPLATE);
  set_long(
    "Several metal plates interlock to form this sturdy breastplate.\n"+
    "The armor has been painted gleaming white, and the shape of a large\n"+
    "cross has been hammered into the center, both front and back, their\n"+
    "faint lines traced with powered ruby.  The emblem of Qual'tor is\n"+
    "painted over the heart.\n");
  if(Bonus) set_ac(5);
  else set_ac(3);
  set_type("armor");  
  set_weight(4);
  set_value(8888);
}

set_bonus() { Bonus = 1; set_ac(5); }

int do_special(object owner) {
  if(!random(8)) {
    tell_object(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as you block your attacker with the "+
      CRUSADER_BREASTPLATE+"!\n");
    tell_room(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as "+capitalize((string)owner->query_name())+ 
      "blocks "+(string)owner->query_possessive()+" attacker with the "+
      CRUSADER_BREASTPLATE+"!\n", ({ owner}) );
    return 0;
  }
  else if(!random(9)) {
    tell_object(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as you block your attacker with the "+
      CRUSADER_BREASTPLATE+"!\n");
    tell_room(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as "+capitalize((string)owner->query_name())+ 
      "blocks "+(string)owner->query_possessive()+" attacker with the "+
      CRUSADER_BREASTPLATE+"!\n", ({ owner}) );
    return 0;
  }
  else if(!random(10)) {
    tell_object(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as you block your attacker with the "+
      CRUSADER_BREASTPLATE+"!\n");
    tell_room(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as "+capitalize((string)owner->query_name())+ 
      "blocks "+(string)owner->query_possessive()+" attacker with the "+
      CRUSADER_BREASTPLATE+"!\n", ({ owner}) );
    return 0;
  }
  return 0;
}

locker_arg() { return ""+Bonus; }
locker_init(arg) { Bonus = atoi(arg);  }
restore_thing(str) { restore_object(str); return 1; }
save_thing(str) { save_object(str); return 1; }
generic_object() { return 1; }
