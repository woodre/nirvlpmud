/*
 *     t2.c              
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

   if(!present("bunny"))
  {
    move_object(clone_object("/players/katya/area/mountain/m/bunny2.c"),
      this_object());
  }
   set_light(1);

   short_desc = HIK+"Lijiang"+NORM;


   long_desc="\
   A thin layer of soft ashen snow rest over the rigid rocky earth.  \n\
The snow covered trees shiver in the brisk wind.  Massive boulders\n\
lay on the ground next to an enormous barrier of solid gray rock.  \n",

 items=({
"snow",
	"Fresh fallen ashen snow envelop all in sight",
"earth",	
	"Soft ashen snow encases the rigid earth",
"trees",
	"Vast snow covered branches quiver in the glacial wind",
"tree",
	"Vast snow covered branches quiver in the glacial wind",
"branches",
	"Vast snow covered branches quiver in the glacial wind",
"branch",
	"Vast snow covered branches quiver in the glacial wind",
"wind",
	"You can not see the wind",
"boulders",
	"Enormous gray boulders fallen to the earth from the peak of the wall.\n"+
	"It seems to be hiding a crack in the barrier\n",
"boulder",
	"Enormous gray boulders fallen to the earth from the peak of the wall.\n"+
	"It seems to be hiding a crack in the barrier\n",
"barrier",
	"Gigantic wall of rock that ascends to the sky\n"+
	"It looks like the boulders are hiding something?",
"crack",
	"Small crack is broken into the side of the huge barrier\n"+
	"Maybe you could enter into it?",
   });

      add_exit("/players/katya/area/mountain/r/m21","southeast");


}
}

   init() {
     ::init();

   add_action("enter","enter");
   }

   enter(arg) {

   if(arg != "crack") {

   notify_fail("Enter what?\n");
   return 0;
  }

   write("You enter the crack in the barrier!\n");

   say(capitalize(this_player()->query_name())+" enters the crack in the barrier.\n");
   move_object(this_player(),"/players/katya/area/mountain/r/c1.c");
   return 1; }
