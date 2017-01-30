/*
File: bronze1.c
Author: Feldegast
Date: 11/02/98
Description:
  Bronze Street.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Bronze Street";
  long_desc=
"  Bronze street is a narrow, cobbled thoroughfare, lined with shops.\n"+
"Mercenaries, guards, and other swashbucklers come here to purchase\n"+
"the finest arms and equipment in the eight duchies.  Above one of the\n"+
"shops on the west side of the street is a sign with an eagle's claw\n"+
"on it.  On the east side, there is another sign saying 'Kager's Repair\n"+
"Shop'.  To the south you see a crowded plaza.\n";
  items=({
    "shops","On the west end of the street is the Eagle's Claws, a weapon\n"+
            "store, and on the east side is Kager's Repair Shop",
    "sign","The sign with the Eagle's Claw on it is for Eagle's Claws, and the\n"+
           "other reads,\"Kager's Repair Shop\"",
    "plaza","The Plaza of the Merchants is directly to the south",
  });
  dest_dir=({
    PATH+"bronze2","north",
    PATH+"wepshop","west",
    PATH+"repshop","east",
    PATH+"plaza","south"
  });
}   
