/*
*      File:            /players/lacar/area/park/rooms/unicornpark4.c
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:           11/22/06
*      Notes:            area
*
*      Change History
*/

#include <ansi.h>

inherit "/room/room";

int x;

reset(arg)
{
  ::reset(arg);
  if( !present("fgiant", this_object()) )
  {
    for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/lacar/area/park/npc/fgiant.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Unicorn Park 4";
  long_desc = 
"  The trees come to end in this area. There is what appears to be a\n\
mound as big as a mountain in the middle of a clearing. It looks like\n\
a cross between a house and a cave. The grass is very sparse here. The\n\
air seems empty of sound.\n";

  items =
  ({
    "forest",
    "Is off to the south",
    "mound",
    "A really tall mound of dirt made into a house",
    "grass",
    "The grass, what little of it there is, is in patches of brown",
    "house",
    "A mound of dirt packed with openings for a door and window",
    "cave",
    "A mound of dirt packed with openings for a door and window",
    "clearing",
    "An sparse area with grass and a mound in the middle",
 });
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark3","south",
"/players/lacar/area/park/rooms/unicornpark5","north"
});
}
