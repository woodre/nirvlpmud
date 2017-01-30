/*
File: cave2.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/13/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(!present("bear") && random(2))
    move_object(clone_object(MON_PATH+"bear.c"), this_object());
  if(arg) return;
  set_light(0);
  short_desc=AREANAME;
  long_desc=
"  The cave ends in a cul-de-sac filled with bones, bits of fur, and\n\
other detritus.  A large stalagmite and stalactite meet in the center\n\
of the cave.  A tunnel leads west.\n";
  items=({
    "cave", "reflexive",
    "cul-de-sac", "reflexive",
    "rock", "The cave walls appear to be predominantly limestone",
    "walls", "The cave walls appear to be predominantly limestone",
    "wall", "The cave walls appear to be predominantly limestone",
    "stalagmites", "They are delicate rock spikes on the ceiling of the cave",
    "stalactites", "They are delicate rock spikes on the floor of the cave",
    "stalagmite", "A large projection thrusts up from the floor of the cave until\n"+
                  "it meets and join a stalactite",
    "stalactite", "A large projection thrusts down from the ceiling of the cave until\n"+
                  "it meets and joins a stalagmite",
    "bones", "They appear to be the bones of small creatures such as rabbits or squirrels",
    "fur", "Bits and pieces of matted fur are scattered around the cave",
    "detritus", "Bits of bone and fur are scattered around the cave",
  });

  dest_dir=({
    PATH+"cave1.c", "west",
  });
}

