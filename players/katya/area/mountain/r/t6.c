/*
 *     t6.c              
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

   if(!present("oak"))
  {
    move_object(clone_object("/players/katya/area/mountain/m/oak.c"),
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
        "Enormous gray boulders fallen to the earth from the peak of the wall",
"boulder",
        "Enormous gray boulders fallen to the earth from the peak of the wall",
"barrier",
        "Gigantic wall of rock that ascends to the sky",
"crack",
        "Small crack is broken into the side of the huge barrier\n"+
        "Maybe you could squeeze into it?",
   });

      add_exit("/players/katya/area/mountain/r/t4","southwest");
      add_exit("/players/katya/area/mountain/r/t5","southeast");

}
}

