/*
File: 4x9.c
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
  x=4; y=9;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  To the north of you, the River Siber flows from west to east.  To\n\
the south the land rises into foothills dotted with trees.  The ground\n\
here is swampy and difficult to travel.\n";
  items=({
    "river", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "siber", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "foothills", "The hills to the south of you are dotted with trees",
    "hills", "The hills to the south of you are dotted with trees",
    "hill", "The hills to the south of you are dotted with trees",
    "trees", "Tall, deciduous trees dot the hills",
    "ground", "It is swampy and difficult to travel",
  });
  dest_dir=({
    PATH+"3x9.c","west",
    PATH+"5x9.c","east",
    PATH+"4x8.c","south",
  });
}

