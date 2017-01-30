/*
 *     goonies2.c              
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
  A small room of seats that sit in short rows.  There is a large\n\
movie screen that sits in front of the seats waiting for the movie\n\
to start.  Speakers are hung on the walls to provide surround sound.\n\
An aisle in between the rows lead up to the large screen.\n",

   items=({
     "screen",
       "The screen is huge and has life-like pictures",
     "large screen",
       "The screen is huge and has life-like pictures",
     "large movie screen",
       "The screen is huge and has life-like pictures",
     "rows of seats",
       "The rows of seats are in a perfect square, placed around the room",
     "seats",
       "The seats are in a perfect square, placed around the room",
     "speakers",
       "Large black speakers that can be barely seen in the darkness of the room",
     "walls",
       "The walls seem to have large stains on them from being so old",
     "aisle",
       "A thin aisle that makes a red path towards the screen",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/goonies3",  "north",
        "/players/katya/area/esquire/goonies/r/goonies1",  "south",
   });}

 }
