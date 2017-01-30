/*
 *     basement.c              
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

   short_desc = "Diner Basement";

   long_desc="\
  A small basement of an old summer diner.  A fireplace sits in the\n\
opposite wall of the door.  Next to the only door is a large freezer. \n\
Large stacks of boxes are scattered around the basement.  Across the\n\
room from the freezer is a huge black machine, beside the machine is\n\
a water container.\n",

   items=({
     "basement",
       "A small basement filled with odds and ends",
     "fireplace",
       "A small fireplace that seems big enough for someone to 'climb down' it",
     "wall",
       "The walls are old, dirty white color, that probably hasn't been cleaned for ages",
     "walls",
       "The walls are old, dirty white color, that probably hasn't been cleaned for ages",
     "door",
       "A big door that leads out",
     "freezer",
       "A freezer that contains frozen items.  The door seems like it might be able to open",
     "boxes",
       "Large stacks of old boxes are scattered with piles of dust on them",
     "black machine",
       "A large black machine that makes counterfeit fifty dollar bills",
     "machine",
       "A large black machine that makes counterfeit fifty dollar bills",
     "water container",
       "The water jug that normally sits on the container has been knocked off on to the floor",
     "container",
       "The water jug that normally sits on the container has been knocked off on to the floor",
     "water",
       "Water has been spilt all over the floor linking down into the fireplace",
     "floor",
       "The filthy floor is soaked in water",
   });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/goonies3",  "out",
   });}

 }
   init() {
    ::init();

   add_action("climb","climb");
   add_action("open","open");

   }

   climb(arg){
     if(arg != "down") {
     notify_fail("What direction are you trying to climb?\n");
     return 0;
     }
   write("You climb down the fireplace.\n");
   say(capitalize(this_player()->query_name())+" climbs down the fireplace.\n");
   move_object(this_player(),"/players/katya/area/esquire/goonies/r/stunnel.c");
   return 1;
   }

   open(arg){
     if(arg != "freezer") {
     notify_fail("Open what?\n");
     return 0;
     }
   write("You open and enter the freezer.\n");
   say(capitalize(this_player()->query_name())+" opens and enters the freezer.\n");
   move_object(this_player(),"/players/katya/area/esquire/goonies/r/freezer.c");
   return 1;
   }
