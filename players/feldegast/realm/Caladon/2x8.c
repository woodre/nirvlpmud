/*
File: 2x8.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 10/23/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=2; y=8;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Low foothills dotted with trees surround you on all sides.  To the\n\
west of you, a black tower is silhouetted by the Storncrag mountains.\n\
To the south of you is a copse of trees.\n";
  items=({
    "mountains", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "storncrag", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "foothills", "The surrounding hills are dotted with trees",
    "hills", "The surrounding hills are dotted with trees",
    "hill", "The surrounding hills are dotted with trees",
    "trees", "Tall, deciduous trees dot the hills",
    "copse", "You can just barely make out a building in the middle of the copse",
  });
  dest_dir=({
    PATH+"2x9.c","north",
    PATH+"1x8.c","west",
    PATH+"3x8.c","east",
    PATH+"2x7.c","south",
  });
}
