/*
 *     pony1.c              
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
  Large wooden doors have been held open by two small grey rocks that\n\
are being shoved underneath the door. A small poster has been placed\n\
on the door of the featuremovie.  A small sign hangs above the movie\n\
poster. Lights from inside the movie flicker on the wall across from\n\
the room.\n",

   items=({
     "walls",
       "The walls seem to have large stains on them from being so old",
     "door",
       "Huge wooden doors that leads to a movie room",
     "wooden door",
       "A huge wooden door that leads to a movie room",
     "movie poster",
       "A pciture of little ponies glalloping across a bright field",
     "poster",
       "A pciture of little ponies glalloping across a bright field",
     "sign",
       "A small readable sign hangs above the poster.",
     "small sign",
       "A small readable sign hangs above the poster.",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/pony2",  "south",
        "/players/katya/area/esquire/r/w2",  "north",
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
        			My Little Pony\n");

   say(capitalize(this_player()->query_name())+" reads the sign.\n");

   return 1; }
