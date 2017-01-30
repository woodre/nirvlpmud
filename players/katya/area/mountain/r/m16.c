/*
 *     m16.c              
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "/players/vertebraker/closed/std/room";


reset(arg) {
  if(!arg)
  { 

   if(!present("tangle"))
  {
    move_object(clone_object("/players/katya/area/mountain/m/tangle.c"),
      this_object());
  }
   set_light(1);

   short_desc = HIK+"Lijiang"+NORM;

   long_desc="\
   Small gray stones spread over the soft ground, as ancient trees\n\
reach for the heavens.  All around are twinkling rainbow of lights,\n\
trees as the ascending dance to the composition of the winds.\n\
Supple green moss crawls across the small stones on the\n\
malleable ground.\n",

 items=({
"stones",
	"Small ash colored minerals bond together creating a smooth oval shaped stone",
"stone",
	"Small ash colored minerals bond together creating a smooth oval shaped stone",
"ground",
	"Pliable earth covered by velvety moss that creep over the ash stones",
"earth",
	"Pliable earth covered by velvety moss that creep over the ash stones",
"trees",
	"Ancient ample trees bursting of life blossom in the melody of the fresh breeze",
"tree",
	"Ancient ample trees bursting of life blossom in the melody of the fresh breeze",
"wind",
	"The soft breeze sways through the vast branches of the massive trees",
"winds",
	"The soft breeze sways through the vast branches of the massive trees",
"breeze",
	"The soft breeze sways through the vast branches of the massive trees",
"branches",
	"Enormous branches are thick with vivid jade leaves swaying in the brisk wind",
"branch",
	"Enormous branches are thick with vivid jade leaves swaying in the brisk wind",
"heavens",
	"Brilliant fusion of colors surge through the sky",
"heaven",
	"Brilliant fusion of colors surge through the sky",
"lights",
	"There are not presently any lights to observe",
"light",
	"There are not presently any lights to observe",
"rainbow",
	"There are not presently any lights to observe",
"rainbows",
	"There are not presently any lights to observe",
"moss",
	"Velvety green vegetation creep along the gray stones on the malleable ground",
   });

      add_exit("/players/katya/area/mountain/r/m15","west");
      add_exit("/players/katya/area/mountain/r/m17","east");
      add_exit("/players/katya/area/mountain/r/m11","southeast");
      add_exit("/players/katya/area/mountain/r/m10","southwest");
      add_exit("/players/katya/area/mountain/r/m20","northwest");
      add_exit("/players/katya/area/mountain/r/m21","northeast");
set_chance(10);
add_msg("Flickering lights sneak out from behind the trees.\n\n"+
RED+"                                                                 *"+NORM+"\n"+
BLINK+BLU+"             *"+NORM+"\n"+
YEL+"                                               *"+NORM+"\n"+
BLINK+GRN+"                                                                      *"+NORM+"\n"+
HIK+"                       *"+NORM+"\n"+
BLINK+WHT+ "                                             *"+NORM+"\n"+
BLINK+MAG+"       *"+NORM+"\n"+
CYN+"                                                                                          *"+NORM+"\n\n");

}
 }
