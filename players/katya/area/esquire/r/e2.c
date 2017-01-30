/*
 *     e2.c              
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

   long_desc=
"  The floor of the hall is covered in an antique looking red carpet.\n\
Coming attraction posters cover the white walls of the theatre.\n\
There are large wooden doors that lead to the movie rooms.\n",

   items=({
     "carpet",
       "The bright red carpet runs all along the floors meeting each\n"+
       "room with a bit of style",
     "red carpet",
       "The bright red carpet runs all along the floors meeting each\n"+
       "room with a bit of style",
     "floor",
       "The floor is covered in red carpet",
     "movies",
       "The hallway leads down to the movies that are already started playing",
     "posters",
       "A huge colorful dragon with flaming breath has been printed on the poster",
     "walls",
       "The walls are a plain white",
     "white walls",
       "The walls are a white with coming attraction posters scattered across it",
     "theatre",
       "The theatre seems to be a bit run down",
     "doors",
        "Two sets of wooden doors leading to two different movie rooms",
     "wooden doors",
        "Two sets of wooden doors leading to two different movie rooms",
      "movie rooms",
        "A light can barely be seen coming out of the movie rooms",
      "rooms",
        "A light can barely be seen coming out of the movie rooms",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/e1",  "west",
        "/players/katya/area/esquire/r/carebears1","east",
        "/players/katya/area/esquire/r/bride1","south",
   });}

 }
