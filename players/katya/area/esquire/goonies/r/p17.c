/*
 *     p17.c              
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
  Small bits of the rocks on the rough walls have broken off to create\n\
small pebbles on the ground that has been mixed into the dirt.  A small\n\
path seems to be leading somewhere, seemingly dangerous.\n",

   items=({
     "rocks",
       "Little bits of rock are scattered around the ground",
     "rock",
       "Little bits of rock are scattered around the ground",
     "wall",
       "The walls of the tunnel is made out of sharp jagged rocks",
     "walls",
       "The walls of the tunnel is made out of sharp jagged rocks",
     "pebbles",
       "Small pebbles are mixed into the dirt on the ground",
     "pebble",
       "Small pebbles are mixed into the dirt on the ground",
     "ground",
       "The ground is covered in small pebbles and dirt",
     "dirt",
       "There is a thick layer of dirt pushed around the ground",
     "path",
       "A small path leads through the dark tunnels",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/p16",  "north",
        "/players/katya/area/esquire/goonies/r/p18",  "south",
   });}

 }
