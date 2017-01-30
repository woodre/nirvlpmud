/*
 *     bride6.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */


#include <ansi.h>

inherit "room/room";

reset(arg)
{
  if(!present("wesley"))
  {
    move_object(clone_object("/players/katya/area/esquire/m/wesley.c"),
      this_object());
  }
  if(!present("buttercup"))
  {
    move_object(
        clone_object("/players/katya/area/esquire/m/buttercup.c"),
        this_object());
  }

/* I moved the code to add the monsters _before_ the check for an */
/* arg in the reset function. This will check each time the room  */
/* resets if a monster is present and clone a new one.            */
 
  if(!arg)
  { 
    set_light(1);

    short_desc = ""+RED+"The Fire Swamp"+NORM+"";

    long_desc="\
  Trees sway in the thick wind that can be seen floating by.  Smoke\n\
rises out of the flaming pits.  Sandtraps seem to be every where,\n\
but very hard to locate them.  Leaves have fallin from the surrounding\n\
trees, covering up much of everything.  Large bushes border the area.\n",

    items=({
     "flaming pits",
       "The fire swamp is a dangerous place to be, in its mysterious darkness",
     "trees",
       "Giant trees sway in the coarse wind",
     "wind",
       "The coarse wind is thick and grey",
     "sandtraps",
       "Huge sandtraps are hidden in the ground",
     "leaves",
       "Dead leaves are scattered across the grounds of the swamp",
     "smoke",
       "Smoke rises from freshly scorched leaves that lay on the ground",
     "bushes",
       "Large bushes surround the whole area",
    });

    dest_dir=({
      "/players/katya/area/esquire/r/bride5",  "north",

    });
  }
}

