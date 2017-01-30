/*
 *     w1.c              
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
  Antique looking red carpet flows down the west hallway.  Movie posters\n\
are spread widely apart on the walls.  The only thing seen down the long\n\
hallway is a faded light sneaking from underneath the door of the movie\n\
rooms.  A large sign, with the movie listings, sways over head.\n",

   items=({
     "red carpet",        
       "The carpet looks quite ragged",
     "carpet",
       "The carpet looks quite ragged",
     "west hallway",
       "The long hallway leads to the movie rooms on the west side of the theatre",
     "hallway",
       "The long hallway leads to the movie rooms on the west side of the theatre",
     "movie posters",
       "The movie posters are spread across the walls of the theatre",
     "posters",
       "The movie posters are spread across the walls of the theatre",
     "walls",
       "The walls are plain white with only movie posters scattered across them",
     "faded light",
       "The faded light can barely been seen in the darkness down the hall",
     "light",
       "The faded light can barely been seen in the darkness down the hall",
     "door",	
       "The doors are closed and slightly allowing a faded light to escape",
     "rooms",
       "The rooms are hidden in the darkness down the hall",
     "sign",
       "A large sign",
     "movie listings",
       "To see the movie listings, please read the sign",
     "listings",
       "To see the movie listings, please read the sign",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/entrance",  "east",
        "/players/katya/area/esquire/r/w2",  "west",
   });}

 }
  init() {
     ::init();
   add_action("read","read");
   }
   read(arg) {
   if(arg != "sign") {

   notify_fail("Read what?\n");
        return 0;
    }
   write("\
		The following movies are playing:\n\n\
		1)  My Little Pony\n\n");

   say(capitalize(this_player()->query_name())+" reads the sign.\n");

   return 1; }
