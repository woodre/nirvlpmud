/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        City of Keats
 *  Function:     generic armor
 *  Create Date:  2004.06.03
 *  Last Edit:    2004.06.08 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "obj/armor";

reset(arg) {
  set_name("full plate");
  set_alias("plate");  
  set_short("Royal FullPlate");
  set_long(
    "  This is a set of steel plates which cover the chest, shoulders, and\n"+ 
    "back.  The symbol of Keats is emblazoned upon the breastplate.\n");
  set_ac(3);
  set_type("armor");
  set_weight(3);
  set_value(3000);
}

