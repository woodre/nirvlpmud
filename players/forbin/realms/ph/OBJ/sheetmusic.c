/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Phish - Fee Area
//  Function:     Item
//  Create Date:  2004.09.02
//  Last Edit:    2004.09.02 -Forbin
//  Notable Changes:
*/

#include "/players/forbin/define.h"
inherit "obj/treasure" ;

id(str) { return (::id(str) || str == "sheet" || str == "music" ||  
                  str == "sheet of music" || str == "sheet music"); }

reset(arg) {
  if(arg) return;
  set_short(HIW+"A sheet of music"+NORM);
  set_long(
    "  This is a creme piece of paper that has sheet music written on\n"+
    "it.  From the notes and bars on it, it looks like a very complex\n"+
    "song with lots of tempo changes and time shifts.\n");
  set_weight(1);
  set_value(1);
}
