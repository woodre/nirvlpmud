/*
File: 9x9.c
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
  x=9; y=9;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  The land rises steeply here and finally ends in an impassable cliff\n\
to the east.  Beyond the cliff are the snowcapped peaks of the Spine\n\
of Allandria.  Just to the north is the River Siber.\n";
  items=({
    "river", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "siber", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "spine", "Many miles to the east, you see the snow-capped mountain range\n"+
             "known as the Spine of Allandria",
  });
  dest_dir=({
    PATH+"8x9.c","west",
    PATH+"9x8.c","south",
  });
}

