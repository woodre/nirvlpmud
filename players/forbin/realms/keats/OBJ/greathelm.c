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
  set_name("helm");
  set_short("A Visored GreatHelm");
  set_long(
    "  This is a large one-piece greathelm with a coldsteel visor covering\n"+ 
    "all but the eye slits.  It is of perfect workmanship, and has long\n"+ 
    "silver swords engraved on each side.\n");
  set_ac(1);
  set_type("helmet");  
  set_weight(1);
  set_value(450);
 
}

