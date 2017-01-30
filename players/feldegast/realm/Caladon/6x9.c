/*
File: 6x9.c
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
  x=6; y=9;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  To the north of you, the River Siber flows from west to east.  A\n\
weaping willow tree hangs over the river here.  To the south, the land\n\
becomes rockier and hilly.\n";
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
  });
  dest_dir=({
    PATH+"5x9.c","west",
    PATH+"7x9.c","east",
    PATH+"6x8.c","south",
  });
}

