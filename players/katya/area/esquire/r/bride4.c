/*
 *     bride4.c              
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

  long_desc=
"  The fire swamp is surrounded by dark and mysterious trees.\n\
The soft ground seems to shake with every step.  Fire bursts\n\
out of small holes in the ground that are cleverly covered by\n\
dirt and dead leaves that have blown off large trees.  Large\n\
footprints have been left around the base of a huge tree.\n",

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
       "Dead leaves are scattered across the grounds of the swamp",
     "dirt",
       "Dirt shuffles with every step taken",
     "footprints",
       "Large footprints have been left at the base of a tree by some type of monster",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/bride5",  "south",
        "/players/katya/area/esquire/r/bride3",  "out",
   });}

}
