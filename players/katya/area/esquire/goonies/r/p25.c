/*
 *     p25.c              
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
       "At the base of one of the walls is a little opening",
     "walls",
       "At the base of one of the walls is a little opening",
     "opening",
       "An opening at the base of a wall.  Someone might be able to 'slide down' it",
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
        "/players/katya/area/esquire/goonies/r/p24",  "west",
   });}

 }

   init() {
   ::init();

   add_action("slide","slide");
   }

   slide(arg) {
   if(arg != "down"){
   notify_fail("What are you wanting to slide?\n");
   return 0;
   }

   write("You enter a little opening and slide down a short watery tunnel.\n");
   say(capitalize(this_player()->query_name())+" enters an opening.\n");
   move_object(this_player(),"/players/katya/area/esquire/goonies/r/w1.c");
   return 1; 
   }
