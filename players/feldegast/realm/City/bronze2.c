/*
File: bronze1.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
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
"  Bronze street ends here in front of the infamous Coliseum of\n\
Calador, an institution that is the stuff of myth and legend.  The\n\
coliseum itself is a huge circular building whose high walls dominate\n\
the cityscape for miles around.  The coliseum's gates are, as always,\n\
open to all who seek to enter.\n";
  items=({
    "coliseum",  "A huge circular building with high walls",
    "street",    "The street is clean and well-maintained",
    "building",  "A huge circular building with high walls",
    "walls",     "The walls are tall and made of granite",
    "cityscape", "Talls buildings rise all around you",
    "gates",     "As always, they are open to all who seek to enter",
  });
  dest_dir=({
    "/players/feldegast/arena/rooms/foyer","north",
    PATH+"bronze1","south"
  });
}   
