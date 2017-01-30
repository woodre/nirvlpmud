/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        City of Keats
 *  Function:     generic weapon
 *  Create Date:  2004.06.03
 *  Last Edit:    2004.06.07 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("coldsteel longsword");
  set_alt_name("longsword");
  set_short("Coldsteel longsword");
  set_long(
    "  Over four feet long, this sword is forged from a black metal known\n"+
    "as coldsteel in Keats.  It's dull blackness reflects almost no light;\n"+
    "because of this and it's ability to hold a sharp edge, it is the\n"+
    "favored material for weaponsmithing in the City.  A foot-long wooden\n"+
    "handle wrapped tightly in cloth allows a firm grip.\n");
  set_type("sword"); 
  set_class(18);
  set_weight(4);
  set_value(1000);
}

