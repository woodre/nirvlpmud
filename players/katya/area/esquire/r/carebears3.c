/*
 *     carebears3.c              
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
"A very large movie screen that stretches up for miles.  The giant\n\
figures move about on the massive screen.  It is very hard to\n\
tell who and what they are doing this close up.  A tiny plaque\n\
sits on the edge of the stage where the large screen sits.\n",

   items=({
     "screen",
       "The screen is huge and has life like pictures",
     "movie screen",
       "The movie screen stretches up for miles as giant figures move around",
     "figures",
       "Giant figures move about on the screen",
     "figure",
       "Giant figures move about on the screen",
     "giant figures",
        "Giant figures move about on the screen",
     "plaque",
        "A small plaque sits on the edge of the stage.  It seems a bit unusal that it is here,\n\
         perhaps you should read it?",
     "stage",
        "The stage is made out of hard oak, and seems centuries old",
     "large screen",
        "The screen is huge and has life-like pictures",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/carebears2",  "west",
   });}

 }
 init() {
     ::init();

   add_action("read","read");
   add_action("touch","touch");
   }

   touch(arg) {

   if(arg != "screen") {

   notify_fail("Touch what?\n");
        return 0;
    }

   write("Beams of light spiral out of the screen, pulling you inside!\n");

   say(capitalize(this_player()->query_name())+" touches the screen and beams of light spiral out, pulling "+this_player()->query_objective()+" inside.\n");

   move_object(this_player(),"/players/katya/area/esquire/r/carebears4.c");
   return 1; }
   read(arg) {
   if(arg != "plaque") {

   notify_fail("Read what?\n");
        return 0;
    }
   write("\The plaque reads:\n\n\
                This screen is very, very old indeed.  A magical force\n\
                was placed upon it many centuries ago.  If some worthy\n\
                person comes along and touches it, that person will be\n\
                given a great honor.\n");

   say(capitalize(this_player()->query_name())+" reads the sign.\n");

   return 1; }
