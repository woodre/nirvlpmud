/*
 *     t21.c              
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

   short_desc = HIK+"Dark Tunnel"+NORM;

   long_desc="\
  The dark tunnel has extremely rough walls.  The ground is made up\n\
of dirt and little bits of rock that has broken off the tunnel walls.\n\
The dark, damp tunnel sharply curves in many different directions.\n",

   items=({
     "tunnel",
       "The dark tunnel is layered in sharp rocks turning in many directions",
     "dark tunnel",
       "The dark tunnel is layered in sharp rocks turning in many directions",
     "damp tunnel",
       "The dark tunnel is layered in sharp rocks turning in many directions",
     "rocks",
       "Little bits of rock are scattered around the ground",
     "rock",
       "Little bits of rock are scattered around the ground",
     "wall",
       "The walls of the tunnel is made out of sharp jagged rocks",
     "walls",
       "The walls of the tunnel is made out of sharp jagged rocks",
     "ground",
       "The ground is covered in small pebbles and dirt",
     "dirt",
       "There is a thick layer of dirt pushed around the ground",
     "directions",
       "The tunnel flows in many different directions",
     "direction",
       "The tunnel flows in many different directions",
     "hidden path",
       "A small path leads through the dark tunnels",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/t20",  "west",
        "/players/katya/area/esquire/goonies/r/t22",  "east",
        "/players/katya/area/esquire/goonies/r/t31",  "south",
   });}

 }
