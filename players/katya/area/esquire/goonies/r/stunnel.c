/*
 *     stunnel.c              
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

   set_light(0);

   short_desc = HIK+"Dark Tunnel"+NORM;

   long_desc="\
  This seems to be a start of a dark tunnel.  The walls are made out\n\
of jagged rocks and slimy moss and mud.  The ground is a mixture of\n\
dirt, rocks and splashes of water spilt from the basement.\n",

   items=({
     "tunnel",
       "A dark tunnel that seems to lead into the darkness",
     "dark tunnel",
       "A dark tunnel that seems to lead into the darkness",
     "walls",
       "The walls are nasty looking, covered in slimy moss and mud",
     "wall",
       "The walls are nasty looking, covered in slimy moss and mud",
     "rocks",
       "The rocks are quite jagged and sharply jet out of the wall",
     "moss",
       "Slimy moss covers the tunnel walls",
     "mud",
       "Wet mud covers for the walls and ground of the dark tunnel",
     "water",
       "Water has splashed down onto the ground from the basement diner above",
     "basement",
       "A rather large basement is right above the start of the tunnel",
    });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/p1.c",  "east",
   });}

 }

   init() {
    ::init();

   add_action("climb","climb");

   }

   climb(arg){
     if(arg != "up") {
     notify_fail("What direction are you trying to climb?\n");
     return 0;
     }
   write("You climb up the wall into the basement.\n");
   say(capitalize(this_player()->query_name())+" climbs up the wall into the basement.\n");
   move_object(this_player(),"/players/katya/area/esquire/goonies/r/basement.c");
   return 1;
   }
