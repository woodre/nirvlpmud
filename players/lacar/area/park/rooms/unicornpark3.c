/*
*      File:            /players/lacar/area/park/rooms/unicornpark3.c
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:           11/22/06
*      Notes:            area
*      Change History
*/
 
#include <ansi.h>

inherit "/room/room";

int x;

reset(arg)
{
  ::reset(arg);
  if( !present("goblin", this_object()) )
  {
    for(x=0; x<4; x++)
    {
  move_object(clone_object("/players/lacar/area/park/npc/Goblin.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Unicorn Park 3";
  long_desc = 
"  The forest seems to be getting thicker here. The branches seem to\n\
be weaving themselves together. It is a little darker, and has a\n\
spooky feeling about it. The shadows make it seem like there are\n\
a lot of different things around.\n";

items =
  ({
	   "forest",
    "The forest becomes dark green, and seems to be closing in",
    "branches",
    "Thick lush foliage weaves in and out above you",
    "shadows",
    "Dark black moving areas",
    "trees",
    "Different size trees growing closer together",
     });
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark2",  "west",
"players/lacar/area/park/rooms/unicornpark4","north"
});
}
