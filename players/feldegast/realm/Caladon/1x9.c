/*
File: 1x9.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=1; y=9;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Just to the north of you, the River Siber flows down from its\n\
headwaters in the Storncrag mountains to the west and off to the east.\n\
To the south and east of you are rolling hills dotted with trees.  On\n\
top of one such hill you see a tall black tower.\n";
  items=({
    "river", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "siber", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "headwaters", "You can't make them out from here",
    "mountains", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "storncrag", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "hills", "The hills to the south and west of you are dotted with\n"+
             "trees",
    "trees", "Tall, deciduous trees dot the hills",
    "tower", "The tall black tower sits on top of the highest hill\n"+
             "for miles around",
  });
  dest_dir=({
    PATH+"2x9.c","east",
    PATH+"1x8.c","south",
  });
}

