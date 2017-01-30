/*                      /                                             *
 *    File:             /players/sami/area/coinarea/r1.c   *
 *    Function:         room                                          *
 *    Author(s):        Sami@Nirvana                                  *
 *    Copyright:        Copyright (c) 2014 Sami                       *
 *                              All Rights Reserved.                  *
 *    Source:                   09/                                   *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
#include "/players/jareel/define.h"

reset(arg) {
object obj;
  if(!present("norm"))  {
    MOCO("/players/sami/area/coinarea/npc/scientist.c"),this_object()); }
	if(!present("teleporter"))   {
	MOCO("/players/sami/teleporter.c"),this_object()); }
   if(arg) return;
   set_light(1);
   set_short("Arcade Entrance");
  long_desc =
  "Large crevices make up this huge cave. Shadows dance across\n"+
  " the walls in a hurried manner. A large "+BOLD+"sign"+NORM+" is posted\n"+
  " on the shadowy archway.\n";

   items =
    ({
	"walls",
	 "an almost metallic substance covers the walls, reflecting what small light there is.",
    "shadows",
    "Figures appear then quickly disappear, taunting you from inside the cave.",
     "crevices",
	 "Large folds of rock, made from millions of years of corrosion,\n"+
	 " form the walls of this cave. There is some unknown substance on\n"+
	 " the walls.",
	 "sign",
     ""+HIR+"Warning"+NORM+": This area is intended for Mid-High level players.\n\
     Venture freely, at your own risk. Also items in vending\n\
	 machine are limited to one per person. You have been warned.",
	 "archway",
	 "A rather large and menacing archway, made crudely out of stone, and some\n\
	 kind of metallic material in which you have never seen before.",
	 "substance",
	 "Not quite solid, yet not quite a liquid, it is hard to determine exactly\n\
	 what this metallic material is.",
	 "metallic",
	 "A semi liquid substance."
	 
	
});
obj = clone_object("/players/sami/closed/machine.c");
    move_object(obj,this_object());

add_exit("/players/sami/area/coinarea/r2","east");
add_exit("room/mount_pass.c","out");
}
