/*
*      File:            /players/lacar/area/park/rooms/unicornpark2.c
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
  if( !present("giant", this_object()) )
  {
    for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/lacar/area/park/npc/giant.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Unicorn Park 2";
  long_desc = 
"  This is more of the forest where unicorns have been known to roam.\n\
The prints in the grass look bigger. The grass seems to sway with the\n\
trees. The leaves cause a pattern on the grass as the branches move.\n\
There is a fresh feeling all around.\n";

  items =
  ({
    "prints",
    "Giant heavy foot prints leading east",
    "forest",
    "A lush green forest",
    "grass",
    "Green and lush grass",
    "leaves",
    "Dark green leaves",
    "branches",
    "Different size and shape branches from the trees",
    "trees",
    "Different size, shapes and kinds of green lush trees",
 });
dest_dir =
({
"players/lacar/area/park/rooms/unicornpark1", "south",
"players/lacar/area/park/rooms/unicornpark3","east"
});
}
