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
  if(!arg && !root()) set_heart_beat(1);
  set_name("test armor");
  set_alias("armor");
  set_short("Test Char Armor");
  set_long(
    "  This is testing armor.  For Test Chars ONLY!\n");
  set_ac(0);
  set_type("amulet");
  set_weight(1);
  set_value(4500);
}


heart_beat() {
  if(!environment()) return destruct(this_object());
  environment()->heal_self(2000000);
}


