/*
File: 3x9.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(!random(2)) {
    while(!present("sheep 3"))
      move_object(clone_object(MON_PATH+"sheep"),this_object());
    if(!present("shepherd"))
      move_object(clone_object(MON_PATH+"shepherd"),this_object());
  }
  if(arg) return;
  x=3; y=9;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Just to the north of you the River Siber flows from the Storncrag\n\
mountains to the west and off to the east.  To the south the land rises\n\
into foothills dotted with trees.  By the side of the river here is a\n\
small pasture.\n";
  items=({
    "river", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "siber", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "mountains", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "storncrag", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "foothills", "The hills to the south of you are dotted with trees",
    "hills", "The hills to the south of you are dotted with trees",
    "hill", "The hills to the south of you are dotted with trees",
    "trees", "Tall, deciduous trees dot the hills",
    "pasture", "The grass here appears to have been well-chewed",
  });
  dest_dir=({
    PATH+"2x9.c","west",
    PATH+"4x9.c","east",
    PATH+"3x8.c","south",
  });
}

