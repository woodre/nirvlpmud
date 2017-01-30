/*
*      File:             /players/lacar/area/park/rooms/unicornpark10.c
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
   if( !present("ladybug", this_object()))
  {
    for(x=0; x<3; x++)
	 { 
	move_object(clone_object("/players/lacar/area/park/npc/ladybug.c"), this_object());
}
}
  ::reset(arg);
  set_light(1);
  short_desc = "Unicorn Park 10";
  long_desc =
  "  There is a large oak tree surrounded by flowers. The field is\n\
full of all different colored flowers. The sun seems to make things a\n\
little brighter and warmer. The sky seems to be more of a baby blue\n\
color, and makes everything more cheerful.\n";

  items =
  ({
    "oak",
    "A very sturdy, tall tree",
    "flowers",
    "Different wild flowers",
    "sky",
    "Baby blue in color",
    "sun",
    "A very bright yellow ball in the sky",
    "tree",
    "A tall sturdy oak",
    "field",
    "open area of brightly colored flowers",
});
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark9","up",
"/players/lacar/area/park/rooms/unicornpark5","south",
"/players/lacar/area/park/rooms/unicornpark11","north",
});
}