/*
 *     t31.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "room/room";

reset(arg) {

if(!present("mama")) {
move_object(clone_object("/players/katya/area/esquire/goonies/m/mama.c"),this_object());
}

  if(!arg)
  { 

   set_light(0);

   short_desc = HIK+"Dark Tunnel"+NORM;

   long_desc="\
  The damp tunnel seems to have come to a dead end.  All around is\n\
coarse walls, small edges of rock dangerously jet out in all angles.\n\
The soil on the ground is blended with rubble from the jagged wall.\n",

   items=({
     "tunnel",
       "The damp tunnel comes to a dead in",
     "damp tunnel",
       "The damp tunnel comes to a dead in",
     "end",
       "The end is surrounded by a large jagged rock wall",
     "dead end",
       "The end is surrounded by a large jagged rock wall",
     "rocks",
       "The rocks dangerously jet out of the solid stone wall",
     "rock",
       "The rocks dangerously jet out of the solid stone wall",
     "wall",
       "The walls of the tunnel is made out of coarse rocks",
     "walls",
       "The walls of the tunnel is made out of coarse rocks",
     "ground",
       "The ground is covered in small pebbles and soil",
     "soil",
       "There is a thick layer of dirt pushed around the ground",
     "edges",
       "The edges on the rock jet out, as if they are reaching out to get something or someone",
     "rubble",
       "Small pieces of rubble have broken off the wall and mixed into the soil on the ground",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/t21",  "north",
        "/players/katya/area/esquire/goonies/r/t32",  "south",
   });}

 }
