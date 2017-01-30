/*
File: cave8.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/24/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(!present("arachnia"))
    move_object(clone_object(MON_PATH+"spiderlady.c"), this_object());
  if(arg) return;
  set_light(0);
  short_desc=AREANAME;
  long_desc=
"  This large cave is covered in sticky webs.  It appears to be\n\
habitated.  Tables and some chairs are scattered about.  Some are\n\
damaged and others have been smashed to splinters.  There is a foul\n\
smell, as though many things have died here.\n";
  items=({
    "cave", "The cave is approximately thirty meters across and several\n"+
            "meters high",
    "earth", "It surrounds you on all sides",
    "walls", "They are jagged and filled with nooks and crannies where evil\n"+
             "skittery things reside",
    "webs", "The webs are thick and sticky.  You'd hate to meet what made them",
    "wall", "They are jagged and filled with nooks and crannies where evil\n"+
            "skittery things reside",
    "tables", "They are all simply made and heavily used",
    "chairs", "They are all simply made and heavily used",
  });

  dest_dir=({
    PATH+"cave7.c", "north",
  });
}
