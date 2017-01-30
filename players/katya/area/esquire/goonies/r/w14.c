/*
 *     w142.c              
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

   set_light(0);

   short_desc = HIK+"Dark Cavern"+NORM;

   long_desc="\
  A large cavern filled waist deep with dark and murky water.  Rock\n\
walls surround the pool of water.  The top of the water ripples, as \n\
if something underneath the water is moving around.  A large shadowy \n\
object hovers over the water in the distance.\n",

   items=({
     "carvern",
       "A large cavern that looks like it has been caved in",
     "water",
       "The water is very dark and murky",
     "wall",
       "The rock walls tower over the pool of water",
     "walls",
       "The rock walls tower over the pool of water",
     "rock",
       "The walls are made out of solid rock from a cave in that happened long ago",
     "pool",
       "The water is very dark and murky",
     "pool of water",
       "The water is very dark and murky",
     "pool water",
       "The water is very dark and murky",
     "ripples",
       "Ripples are made on the surface of the water by something hiding underneath it",
     "object",
       "You should try and get closer to the object to find out what it is",
     "shadowy object",
       "You should try and get closer to the object to find out what it is",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/w13.c",  "south",
        "/players/katya/area/esquire/goonies/r/wt5.c",  "southeast",
        "/players/katya/area/esquire/goonies/r/w1.c",  "northeast",
        "/players/katya/area/esquire/goonies/r/wt1.c",  "east",
   });}

 }
