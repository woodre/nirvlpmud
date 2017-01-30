/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Flame Forest
 *  Function:     Saleable item on mob
 *  Create Date:  2004.01.27
 *  Last Edit:    2004.01.27 -Forbin
 *  Notable Changes:
 */ 

#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "tail" || str == "lizard tail"); }

reset(arg) {
  if(arg) return;
  set_short(HIK+"An ash "+HIR+"lizard"+NORM+" tail");
  set_long("  The severed tail of an ash lizard.  People have been known\n"+
           "to pay handsomely for one - but you can't imagine why.\n");           
  set_weight(1);
  set_value(300+201);
}

query_save_flag()  { return 1; }
