/*
 *     carebears1.c              
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
  The hall leads straight to a large, propped open door.  On the \n\
door is a big movie poster.  A white sign sits above the wooden\n\
door.  Light sneaks out across the floor of the room.\n",

  items=({
     "door",
       "A huge wooden door that leads to a movie room",
     "wooden door",
       "A huge wooden door that leads to a movie room",
     "sign",
       "A readable large sign",
     "movie poster",
       "The poster is of 'The Carebear's Movie'",
     "poster",
       "The poster is of 'The Carebear's Movie'",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/carebears2",  "east",
        "/players/katya/area/esquire/r/e2",  "west",
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
The sign reads:\n\n\
              Feature Presentation is:\n\n\
		The Carebear's Movie\n");

   say(capitalize(this_player()->query_name())+" reads the sign.\n");

   return 1; }
