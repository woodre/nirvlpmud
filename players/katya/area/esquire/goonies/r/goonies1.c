/*
 *     goonies1.c              
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
"  A wooden door has been propped open with a large trashcan.\n\
A sign sits above the door naming the current playing movie.\n\
The walls seem to be quite dirty around the movie poster that\n\
has been taped to the wall beside the door.\n",
  
  items=({
     "walls",
        "The walls seem to have large stains on them from being so old",
     "door",
        "A huge wooden door that leads to a movie room",
     "wooden door",
        "A huge wooden door that leads to a movie room",
     "sign",
        "Why don't you try and read it?",
     "movie poster",
        "A huge dragon flying over a road is on the poster with 'Reign of Fire' written on it",
     "poster",
        "A huge dragon flying over a road is on the poster with 'Reign of Fire' written on it",
     "trash can",
        "Large, black plastic trash can that is currently being used to prop the door open",
     "can",
        "Large, black plastic trash can that is currently being used to prop the door open",
     "tape",
       "A clear tape has been raggedly been torn off to place the poster on the door",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/goonies2",  "north",
        "/players/katya/area/esquire/r/w2",  "south",
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
                                 The Goonies\n\n\
                                 Rated PG-13\n");

   say(capitalize(this_player()->query_name())+" reads the sign.\n");

   return 1; }
