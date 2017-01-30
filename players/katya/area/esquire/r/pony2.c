/*
 *     pony2.c              
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
  A half of dozen rows are placed evenly about the room in front of a\n\
huge stage.  A large white screen slighty wiggles in a small breeze\n\
that is coming from the lobby.  A thin carpeted aisle leads from the \n\
door towards the stage.\n",

   items=({
     "screen",
       "The screen is huge and has life-like pictures",
     "large screen",
       "The screen is huge and has life-like pictures",
     "large white screen",
       "The screen is huge and has life-like pictures",
     "rows",
       "The rows of seats are in a perfect square, placed around the room",
     "seats",
       "The seats are in a perfect square, placed around the room",
     "aisle",
       "A thin aisle that makes a red path towards the screen",
     "carpet",
       "A red carpet that runs down the thin aisle",
     "stage",
       "A huge antique stage that sits in front of the rows of seats",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/pony1",  "north",
        "/players/katya/area/esquire/r/pony3",  "south",
   });}

 }
