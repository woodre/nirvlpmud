/*
File: 1x7.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 12/24/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=1; y=7;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  The Storncrag mountains tower to the west of you, making further\n\
passage impossible.  To the north of you a tall black tower sits atop\n\
a hill and to the east is a copse of trees.\n";
  items=({
    "mountains", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "storncrag", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "hills", "The hills to the south and west of you are dotted with\n"+
             "trees",
    "trees", "Tall, deciduous trees dot the hills",
    "tower", "The tall black tower sits on top of the highest hill\n"+
             "for miles around",
    "copse", "You can just barely make out a building in the middle of the copse",
  });
  dest_dir=({
    PATH+"1x8.c","north",
    PATH+"2x7.c","east",
    PATH+"1x6.c","south",
  });
}

