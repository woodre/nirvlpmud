/*
File: armshop.c
Author: Feldegast
Date: 09/25/99
Revised: 03/23/02
Description:
  An equipment shop.  Originally from the arena.
*/


#include "defs.h"

inherit ROOM;

reset(arg) {
  object vendor;
  if (arg) return;
  if (!present("vendor")) {
    vendor=clone_object(PATH+"shpkpr1.c");
    move_object(vendor,this_object());
  }
  set_light(1);
  short_desc="Armor Shop";
  long_desc=
"  This is a small but prosperous supply shop.  The sales room is\n"+
"around ten meters square and filled with racks of armor and equipment.\n"+
"A low counter runs along the side of the shop, behind which is a large\n"+
"sign listing prices.\n";
  dest_dir=({
    PATH+"marble6.c","north",
  });
  items=({
    "sign",
       "=================================================\n"+
       "=    A leather gauntlet    -     75 coins       =\n"+
       "=    A pair of boots       -    100 coins       =\n"+
       "=    A green cloak         -    100 coins       =\n"+
       "=    A crystal amulet      -    100 coins       =\n"+
       "=    A plumed helmet       -    125 coins       =\n"+
       "=    A steel shield        -    200 coins       =\n"+
       "=    A suit of scale mail  -    700 coins       =\n"+
       "=    A Quarterstaff        -   1000 coins       =\n"+
        "=================================================\n",
    "counter","A low wooden counter",
    "racks","Look, but don't touch"
  });
}
    
