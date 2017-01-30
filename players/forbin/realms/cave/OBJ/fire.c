/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qual'tor Miniquest
//  Function:     room atmosphere
//  Create Date:  2005.02.17
//  Last Edit:    2005.02.17 -Forbin
*/

#include "/players/forbin/realms/cave/cavedefine.h"

inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_light(2);
  set_id("fire");
  set_alias("atticus_miniquest_fire");
  set_short("A "+RED+"smoldering"+NORM+" fire");
  set_long(
    "A small fire burns in the center of the cave, casting flickering\n"+
    "light into the darkness.\n"); 
}

get() { return 0; }