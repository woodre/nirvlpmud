inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
#include "/players/jareel/define.h"
#define MOCO move_object(clone_object

reset(arg) {
  if(!present("link_1"))  {
    MOCO("/players/sami/area/coinarea/npc/link.c"),this_object()); }

   if(arg) return;
     set_light(0);
   set_short("Holo Cavern");
long_desc =
  "The cave finally appears to be at a end. The water has seemed to pool\n"+
  "on the floor at the back of the cave. The floor is an unsafe place to\n"+
  "walk due to its uneven and sharp nature. It is almost as if the cave is \n"+
  "a living entity; breathing and listening.\n",

   items =
    ({
    "roof",
    "A 10' roof, jagged and worn by the constant erosion caused by the water.",
	"rocks",
	"Piles of different shaped rocks lay scattered about.",
	 "water",
	 "A pool of water calm and still.",
	 "walls",
	 "An almost metallic substance covers the walls, reflecting what small light there is.",
	 "floor",
	 "The floor dips in many places, jagged rocks protruding from places"+
	 " that would appear to be impossible.",
	 "substance",
	 "Not quite solid, yet not quite a liquid, it is hard to determine exactly\n\
	 what this metallic material is.",
	
});
add_exit("/players/sami/area/coinarea/r24","north");
}
