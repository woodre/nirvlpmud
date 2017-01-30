/*
File: cave1.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/13/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_light(0);
  short_desc=AREANAME;
  long_desc=
"  This cave expands greatly the further into the rock it goes.  The\n\
atmosphere is thick and moist and the walls of the cave are covered in\n\
a sheen of sweat.  A row of stalagmites lines the cave wall.\n";
  items=({
    "cave", "reflexive",
    "rock", "The cave walls appear to be predominantly limestone",
    "walls", "The cave walls appear to be predominantly limestone",
    "wall", "The cave walls appear to be predominantly limestone",
    "stalagmites", "They are delicate rock spikes on the ceiling of the cave",
  });

  dest_dir=({
    PATH+"9x8.c","out",
    PATH+"cave2.c", "east",
  });
}

