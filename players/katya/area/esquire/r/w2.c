/*
 *     w2.c              
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

  short_desc = "The Esquire";

  long_desc="\
  The dirty white walls are plastered with old movie posters from the\n\
fifties.  The red carpet, that looks like it has been here since\n\
longer than the posters, is shredding at the base of the walls.\n\
Separated evenly down the hallway, are antique light fixtures.\n\
The light reflecting out of the fixtures prances around the hall.\n\
There are two large doors that have been propped open and \n\
lead to the movie room.\n",

   items=({
     "walls",
        "The walls seem to have large stains on them from being so old",
     "white walls",
        "The walls seem to have large stains on them from being so old",
     "posters",
        "The posters are of old black and white movies",
     "movie posters",
        "The posters are of old black and white movies",
     "doors",
        "A huge wooden door that leads to a movie room",
     "door",
        "A huge wooden door that leads to a movie room",
     "wooden doors",
        "A huge wooden door that leads to a movie room",
     "fixtures",
        "Old glass light fixtures have been placed evenly apart down the hall",
     "light fixtures",
        "Old glass light fixtures have been placed evenly apart down the hall",
     "light",
        "Light figures dance down the hall",
     "light figures",
        "Light figures dance down the hall",	
     "carpet",
        "Antique looking carpet flows down the hall running underneath each door",
     "red carpet",
        "Antique looking carpet flows down the hall running underneath each door",
     "hallway",
        "A short musty hall, with old red carpet flowing down it",
     "hall",
        "A short musty hall, with old red carpet flowing down it",
     "base",
        "The base of the wall the red carpet is shredding to pieces",
     "movie room",
        "The movie room is very dim",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/w1",  "east",
        "/players/katya/area/esquire/r/pony1",  "south",
   });}

 }
