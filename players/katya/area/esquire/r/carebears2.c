/*
 *     carebears2.c              
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
  A semi-large movie room with a dozen rows of seats for people\n\
to sit and enjoy the movie.  A large white movie screen hangs\n\
on the huge wooden stage in front of the seats.  A short aisle\n\
leads up to the screen.\n",  

   items=({
     "screen",
       "The screen is huge and has life-like pictures",
     "large screen",
       "The screen is huge and has life-like pictures",
     "large movie screen",
       "The screen is huge and has life like pictures",
     "rows of seats",
       "The rows of seats are in a perfect square, placed around the room",
     "seats",
       "The seats are in a perfect square, placed around the room",
     "aisle",
       "A thin aisle that makes a path towards the screen",
     "thin aisle",
       "A thin aisle that makes a path towards the screen",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/carebears1",  "west",
        "/players/katya/area/esquire/r/carebears3",  "east",
   });}

 }
