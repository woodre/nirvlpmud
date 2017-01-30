/*
 *     e1.c              
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
  The east hallway seems to be quite long.  Red carpet has been\n\
laid on the floor leading to the movies that are currently\n\
being played.  A man sized poster of the 'Goonies' has been hung\n\
on the plain white walls.  A large sign hangs from the white \n\
spackled ceiling.\n",

   items=({
     "east hallway",
       "The east hallway seems quite long, with it's red carpeting\n"+
       "reaching into the darkness",
     "hallway",
       "The east hallway seems quite long, with it's red carpeting\n"+
       "reaching into the darkness",
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
     "poster",
       "A man sized poster of the movie 'Goonies' has been placed on the wall",
     "goonies",
       "A large poster of the movie 'Goonies' is on the wall",
     "walls",
       "The walls are a plain white with only a few posters scattered across it",
     "plain white walls",
       "The walls are a plain white with only a few posters scattered across it",
     "sign",
       "A large readable neon sign",
     "white spackled ceiling",
       "The white spackled ceiling looks as if it has not been fixed in years",
     "spackled ceiling",
       "The white spackled ceiling looks as if it has not been fixed in years",
     "ceiling",
       "The white spackled ceiling looks as if it has not been fixed in years",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/entrance",  "west",
        "/players/katya/area/esquire/r/e2",  "east",
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
         	1)  The Carebear's Movie\n\n\
         	2)  Princess Bride\n");

   say(capitalize(this_player()->query_name())+" reads the sign.\n");

   return 1; }
