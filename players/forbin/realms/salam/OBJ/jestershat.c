/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     generic armor
 *  Create Date:  2004.06.05
 *  Last Edit:    2004.06.05 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/realms/salam/salamdefine.h"
inherit "obj/armor";

reset(arg) {
  set_name("hat");
  set_alias("jesters hat");
  set_short(HIC+"A Je"+HIY+"ster"+HIG+"'s Hat"+NORM);
  set_long(
    "  A silly looking hat with three tassels which hand down from it.\n"+
    "Each of them are different colors:  blue, yellow, and green.\n");
  set_ac(0);
  set_type("helmet");  
  set_weight(1);
  set_value(150);
 
}

