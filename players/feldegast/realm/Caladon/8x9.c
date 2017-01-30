/*
File: 8x9.c
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
  x=8; y=9;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  To the north of you, the River Siber flows from west to east.  To\n\
the east, the land slopes upwards towards the mountain range known as\n\
the Spine of Allandria.\n";
  items=({
    "river", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "siber", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "foothills", "The hills to the south of you are dotted with trees",
    "hills", "The hills to the south of you are dotted with trees",
    "hill", "The hills to the south of you are dotted with trees",
    "tree", "A weeping willow tree hangs over the river",
    "land", "reflexive",
    "spine", "Many miles to the east, you see the snow-capped mountain range\n"+
             "known as the Spine of Allandria",
  });
  dest_dir=({
    PATH+"7x9.c","west",
    PATH+"9x9.c","east",
    PATH+"8x8.c","south",
  });
}

