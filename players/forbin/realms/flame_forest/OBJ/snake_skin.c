/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Flame Forest
 *  Function:     Saleable item on mob
 *  Create Date:  2004.01.27
 *  Last Edit:    2004.06.04 -Forbin
 *  Notable Changes:
 */ 

#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "skin" || str == "snakeskin"
                            || str == "snake skin" || str == "smoldersnakeskin"); }

reset(arg) {
  if(arg) return;
  set_short(HIK+"A smolder"+NORM+"snake skin");
  set_long("  This is a strip of thin skin from a smoldernake.  It has a gray.\n"+
           "color to it, with a black and white spiral pattern down its length.\n");           
  set_weight(1);
  set_value(100+151);
}

query_save_flag()  { return 1; }
