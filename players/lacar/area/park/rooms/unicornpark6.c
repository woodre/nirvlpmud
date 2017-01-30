/*
*      File:            /players/lacar/area/park/rooms/unicornpark6.c
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:           11/22/06
*      Notes:            area
*      Change History:
*/

#include <ansi.h>
#define DEST "/players/lacar/area/park/rooms/unicornpark7"

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("fairyf", this_object()))
  move_object(clone_object("/players/lacar/area/park/npc/fairyf.c"), this_object());
   if( !present("fairym", this_object()))
  move_object(clone_object("/players/lacar/area/park/npc/fairym.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Unicorn Park 6";
  long_desc = 
"  This is a forest of just trees that go as far as the eye can see.\n\
They stand so high that there is barely any sunlight coming through\n\
the leaves. There are pine trees, a few birch trees, some oaks, and\n\
one single redwood. \n";

  items =
  ({
	 "trees",
	 "A lot of different trees",
	 "pine",
	"Trees with pine needles and cones hanging from the branches",   
	"birch",
	"White bark with cinnamon tones and branches having red leaves",
	"oak",
	"Broad-leaved trees",
	"redwood",
	"A tall tree made for climbing",
    "cones",
    "Scaly fruit of trees of the pine family",
    "branches",
    "Wooden limbs of different colors and shapes",
    "needles",
    "Lots of needle-shaped leaves",
    "leaves",
    "A varity of different colors and shapes",
 });
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark5","west",
});
}

void init() {
  ::init();
  add_action("do_climb", "climb");
}

status do_climb(string arg) {
  if (!arg) {
    notify_fail("Climb what?\n");
    return 0;
  }

  if (arg == "tree") {
    notify_fail("Climb which tree?\n");
    return 0;
  }

  if (arg == "redwood" || arg == "redwood tree") {
    this_player()->move_player("by climbing the redwood#"+DEST);
    return 1;
  }

  notify_fail("Climb what?\n");
  return 0;
}
