/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Mob Treasure
//  Create Date:  2006.10.08
*/

#include "/players/tristian/lib/ClubFeddefine.h"
inherit "obj/treasure.c";

reset(arg) {
   if(arg) return;
   
   set_id("A bar of soap");
   set_alias("soap");
   set_short("A bar of soap");
   set_long(
      "This is a half used bar of soap.  It is slippery and almost\n"+
      "slips out of your hand.  Aren't you glad you caught it before\n"+
      "you had to bend over and pick it up.\n");
   set_value(500);
   set_weight(1);
}
