/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     Crown for King of Salamites
 *  Create Date:  2004.06.04
 *  Last Edit:    2004.06.10 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "obj/armor";

reset(arg) {
  set_name("crown of coal");
  set_alias("crown");
  set_short(HIK+"Crown of Coal"+NORM);
  set_long(
    "  Black as night and smooth as glass, this twisted mass of coal has\n"+
    "been fashioned into a crown.  Six malformed spires give the crown a\n"+
    "disjointed, yet somewhat regal look.  A single red gem has been set\n"+
    "into the center of the crown's front.\n");
  set_ac(2);
  set_type("helmet");  
  set_weight(1);
  set_value(4500);
}


