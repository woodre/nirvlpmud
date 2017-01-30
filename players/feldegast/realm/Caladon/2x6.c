/*
File: 2x6.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/14/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=2; y=6;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Gnarled old trees dot the foothills of the Caladonian countryside.\n\
To the north of you is a thick copse of trees.  To the east there\n\
appears to be some sort of building.  In the distant west you see\n\
a mountain range.\n";
  items=({
    "range",     "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "mountains", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "hills",     "The surrounding hills are dotted with trees",
    "trees",     "Tall, deciduous trees dot the hills",
    "copse",     "You can just barely make out a building in the middle of the copse",
    "building",  "You cannot make out its purpose from here",
  });
  dest_dir=({
    PATH+"2x7.c", "north",
    PATH+"1x6.c", "west",
    PATH+"3x6.c", "east",
    PATH+"2x5.c", "south",
  });
}

