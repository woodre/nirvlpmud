/*
*      File:            /players/lacar/area/park/rooms/unicornpark1.c
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:           11/22/06                   
*      Notes:            entrance of area
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
  short_desc = "Unicorn Park 1";
  long_desc =
  "  This is a forest area where unicorns have been known to roam. There\n\
are faint hoof prints in the grass. The sunlight filters through the\n\
trees, and makes patterns on the forest floor. The grass seems to reach\n\
upwards. There is a sweet smell in the air from the pine trees. There\n\
is alot of movement all around.\n";

  items =
  ({
    "prints",
    "Faint hoof prints leading in different directions",
    "forest",
    "A lush green forest",
    "grass",
    "Green and lush grass",
    "pine",
    "Trees with pine needles and cones hanging from the branches",
    "trees",
    "Thick green pine trees",
    "floor",
    "Green grass showing different prints",
   });
dest_dir =
({
"/room/ravine", "out",
"/players/lacar/area/park/rooms/unicornpark2",  "north",
});
}
