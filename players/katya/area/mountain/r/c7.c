/*
 *     c7.c              
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(!arg)
  { 

   if(!present("uruloki"))
  {
    move_object(clone_object("/players/katya/area/mountain/m/uruloki.c"),
      this_object());
  }
   set_light(0);

   short_desc = HIK+"Dragons Den"+NORM;

   long_desc="\
   A massive cavity with jagged edged rock jetting out of the wall.\n\
The ground is mucky from the dripping water from over head.  The \n\
walls are covered in a slimy moss texture, causing the rocks to be \n\
extremely slick. There does not seem like there is an obvious way \n\
to get out.\n",

 items=({
"wall",
	"Jagged rock stick out of the wall, maybe you should try to climb the wall?",
"walls",
	"Jagged rock stick out of the wall, maybe you should try to climb the wall?",
"cavity",
	"An enormous opening  with jagged edged rock.",
"ground",
	"A slimy moss grows over the muddy ground",
"water",
	"Puddles form on the ground  from where the water has splattered",
"waters",
	"Puddles form on the ground  from where the water has splattered",
"moss",
	"Slimy, green plantation that creeps over the grounds and walls",
"rock",
	"Gray rocks jet out of the walls with serrated edges",
"rocks",
	"Gray rocks jet out of the walls with serrated edges",

 });

}
}


   init() {
     ::init();
   add_action("climb","climb");
   }

   climb(arg) {

   if(arg != "wall") {

   notify_fail("Climb what?\n");
   return 0;
  }

   write("You climb up the wall, grabbing onto a tree root pulling yourself up out of the hole!\n");

   say(capitalize(this_player()->query_name())+" climbs up the wall, grabbing onto a tree root, pulling "+this_player()->query_objective()+"self up out of the hole!\n");
   move_object(this_player(),"/players/katya/area/mountain/r/c6.c");
   return 1; }
