/*
*      File:             /players/lacar/area/park/rooms/unicornpark7.c 
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
   if( !present("gryffon", this_object()))
  {
    for(x=0; x<2; x++)
    {
  move_object(clone_object("/players/lacar/area/park/npc/gryffon.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Unicorn Park 7";
  long_desc = 
"  This is the top of the redwood tree, and the view is magnificent\n\
from up here. The tree tops look so luscious, and are a deep green in\n\
color. It looks like one giant green carpet layed out. The sky is so\n\
blue that it can almost pass for water.\n";

  items =
  ({
    "redwood",
    "A very tall tree",
    "top",
    "A lush green foliage",
    "sky",
    "A very blue sky",
    "carpet",
    "Green tree tops",
    "trees",
    "Green foliage from the tops of trees",
    "tree",
    "Green foliage from the top of the redwood",
 });
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark6","down",
"/players/lacar/area/park/rooms/unicornpark8","north",
});
}
