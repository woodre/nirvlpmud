/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        City of Keats
 *  Function:     generic weapon
 *  Create Date:  2005.06.30
 *  Last Edit:    2005.06.30 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "obj/weapon.c";

reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("A staff of yew");
  SetMultipleIds(({"staff","staff of yew","yew staff"}));
  set_short("A staff of "+HIY+"yew"+NORM);
  set_long(
    "A simple staff carved from a limb of a yew tree.  The length of wood\n"+
    "is slightly twisted, and all the bark has been removed save for a small\n"+
    "bit at the very tip.  A small hollow has be made and an onyx gem has\n"+
    "been inserted into the hole.  Magical runes and symbols are intricately\n"+
    "engraved along its length.\n");
  set_type("staff"); 
  set_class(15);
  set_weight(2);
  set_value(500);
}

