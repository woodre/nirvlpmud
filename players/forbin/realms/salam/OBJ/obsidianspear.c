/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     generic weapon
 *  Create Date:  2004.06.05
 *  Last Edit:    2004.06.05 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/realms/salam/salamdefine.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("spear");
  set_alias("obsidian spear");
  set_short(HIK+"Obsidian Spear"+NORM);
  set_long(
    "  Almost six feet long and tipped with a serrated barb at each\n"+
    "end, this is a dangerous looking weapon.  Forged from black\n"+
    "obsidian, it has a nice balance and is almost as hard as diamond.\n"+
    "In the hands of someone skilled, this could be very dangerous.\n");
  set_type("spear"); 
  set_class(17);
  set_weight(5);
  set_value(1000);
}

