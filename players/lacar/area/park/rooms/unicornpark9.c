/*
*      File:             /players/lacar/area/park/rooms/unicornpark9.c
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

reset(arg)
{
 ::reset(arg);
   	if( !present("gryffon", this_object()))
    {
  move_object(clone_object("/players/lacar/area/park/npc/gryffon.c"), this_object());
}

 ::reset(arg);
  set_light(1);
  short_desc = "Unicorn Park 9";
  long_desc = 
"  This is the top of a large oak tree. The view is breathtaking from\n\
up here. The trees seem to become larger and closer together. They are\n\
a lighter green in color. The sun seems to make things a little\n\
brighter and makes it warmer. The sky seems to be more of a baby blue\n\
color, and close enough to touch.\n";

  items =
  ({
    "oak",
    "A very sturdy, tall tree",
    "top",
    "A lush light green foliage",
    "sky",
    "Baby blue in color",
    "sun",
    "A very bright yellow ball in the sky",
    "tree",
    "A very sturdy, tall oak",
    "trees",
    "Lush green trees",
    "view",
    "Breathtaking sight of the top of the trees",
    
 });
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark8","west",
"/players/lacar/area/park/rooms/unicornpark10","down",
});
}
