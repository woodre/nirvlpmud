/*
 *     D5.c              
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
  The damp tunnel seems to have come to a dead end.  All around are\n\
coarse walls, small edges of rock dangerously jet out in all angles.\n\
A small crack sits in between a couple of edges.  The soil on the\n\
ground is blended with rubble from the jagged wall.\n",

   items=({
     "tunnel",
       "The damp tunnel comes to a dead end",
     "damp tunnel",
       "The damp tunnel comes to a dead end",
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
     "crack",
       "A small crack, allows a small bit of light to 'squeeze' through",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/t42",  "south",
   });}

 }

   init() {
     ::init();

   add_action("squeeze","squeeze");
   }

   squeeze(arg) {

   if(arg != "crack") {

   notify_fail("Touch what?\n");
   return 0;
    }

   write("You squeeze through the crack in the rock!\n");

   say(capitalize(this_player()->query_name())+" squeezes through the crack in the wall and "+this_player()->query_pronoun()+" disappears.\n");
   move_object(this_player(),"/players/katya/area/esquire/goonies/r/goonies3.c");

   return 1;
 }
