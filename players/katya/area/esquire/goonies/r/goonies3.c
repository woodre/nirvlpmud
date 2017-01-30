/*
 *     goonies3.c              
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
"A large screen is at the front of the room.  It seems to come\n\
alive when it is touched.  The stage lies in front of a dozen\n\
rows of seats, meeting them at the red carpet.\n";

   items=({
     "screen",
        "The screen is huge and has life-like pictures",
     "stage",
        "The stage is made out of hard oak, and seems centuries old",
     "large screen",
        "The screen is huge and has life-like pictures",
     "rows of seats",
        "The rows of seats are in a perfect square, placed around the room",
     "seats",
        "The seats are in a perfect square, placed around the room",
     "red carpet",
        "The red carpet comes down from the hallway and reaches the large antique stage",
     "carpet",
        "The red carpet comes down from the hallway and reaches the large antique stage",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/goonies2", "south",
   });
}

   }
   init() {
     ::init();

   add_action("touch","touch");
   }

   touch(arg) {

   if(arg != "screen") {

   notify_fail("Touch what?\n");
   return 0;
    }

   write("Beams of light spiral out of the screen, pulling you inside!\n");

   say(capitalize(this_player()->query_name())+" touches the screen and beams of light spiral out, pulling "+this_player()->query_objective()+" inside.\n");
   move_object(this_player(),"/players/katya/area/esquire/goonies/r/basement.c");
   return 1; }
