/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Keats
//  Function:     npc atmosphere
//  Create Date:  2005.06.30
//  Last Edit:    2005.06.30 -Forbin
*/

#include "/players/forbin/realms/keats/keatsdefine.h"

inherit "/obj/treasure";

reset(arg) 
{
  if(arg) return;
  set_id("spellbook");
  set_alias("nazal_fake_spellbook");
  set_short(GRN+"Nazal's magic spellbook ["+HIG+"*"+NORM+GRN+"]"+NORM);
  set_long("A fake spellbook object.\n"); 
}
