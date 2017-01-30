/*
 *     pony3.c              
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
A small aisle leads up to a large wooden stage that has a screen\n\
that seems to sparkle from the lights.  The screen reaches up to\n\
the ceiling and spreads from one wall to the other.  The large\n\
screen seems tohave a magical presence to it, almost as if its\n\
calling out to be touched.\n",

   items=({
        "screen",
           "The screen is huge and has life like pictures",
        "stage",
           "The stage is made out of hard oak, and seems centuries old",
        "large screen",
            "The screen is huge and has life like pictures",
        "rows of seats",
            "The rows of seats are in a perfect square, placed around the room",
        "aisle",
             "A small red carpeted aisle leads up to the movie screen",
        "red carpet",
             "The red carpet comes down from the hallway and reaches the large antique stage",
        "carpet",
            "The red carpet comes down from the hallway and reaches the large antique stage",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/pony2",  "north",
   });}

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

   say(capitalize(this_player()->query_name())+" touches the screen and beams of light spiral out, pulling "+this_player()->query_objective()+" inside.\n");   move_object(this_player(),"/players/katya/area/esquire/r/pony4.c");
   return 1; }
