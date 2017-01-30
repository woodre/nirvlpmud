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

inherit "obj/armor";

reset(arg) {
  set_name("tattered tunic");
  set_alias("tunic");
  set_short(HIW+"A tattered tunic"+NORM);
  set_long(
    "A short white tunic that looks to have been made for a fairly\n"+
    "large individual.  The front and the back are adorned with large\n"+
    "symbols of Qual'tor sown into the fabric.  It is faded and worn\n"+
    "from time and ill care.\n");
  set_ac(0);
  set_type("misc");  
  set_weight(1);
  set_value(8888);
}


