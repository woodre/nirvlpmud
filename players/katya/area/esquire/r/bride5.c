/*
 *     bride5.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "room/room";
      
reset(arg) {
  if(!arg)
  { 

  set_light(1);

  short_desc = RED+"The Fire Swamp"+NORM;

long_desc="\
  The soft ground in the fire swamp tremble at each step taken.\n\
Rumbles from under the ground can be seen as the dead leaves \n\
rattle at the bottom of the tree trunks.  Smoke rises out of a tiny\n\
hole in the ground shortly after a burst of flames shot straight up \n\
reaching for anything in its path.  Small footprints can be seen\n\
scattered around the soft ground.\n",

   items=({
     "fire swamp",
       "The fire swamp is a dangerous place to be, in its mysterious darkness",
     "swamp",
       "The fire swamp is a dangerous place to be, in its mysterious darkness",
     "fire bursts",
       "Fire bursts up out of the soft grounds trying to touch anything in sight",
     "fire",
       "Fire bursts up out of the soft grounds trying to touch anything in sight",
     "bursts",
       "Fire bursts up out of the soft grounds trying to touch anything in sight",
     "ground",
       "The soft ground seem to move under each step taken",
     "soft ground",
       "The soft ground seem to move under each step taken",
     "trees",
       "Giant trees surround the swamp, it almost seems they are stalking everything",
     "holes",
       "Small holes are hidden in the ground",
     "leaves",
       "Dead leaves are scattered across the ground of the swamp",
     "dirt",
       "Dirt shuffles in every step taken",
     "smoke",
       "Smoke rises from freshly scorched leaves that lay on the ground",
     "footprints",
       "Large footprints have been left at the base of a tree from some type of monster",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/bride4",  "north",
        "/players/katya/area/esquire/r/bride6",  "south",
   });
}
}
