/*
*      File:            /players/lacar/area/crater/crater4.c
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2007 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:                              
*      Notes:            
*      Change History
*/

#include <ansi.h>

inherit "/room/room";

int x;

reset(arg)
{
  ::reset(arg);
  if( !present("dowin", this_object()) )
  {
    for(x=0; x<2; x++)
    {
  move_object(clone_object("/players/lacar/area/crater/npc/dowin.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Crater 4";
  long_desc =
  " In this part of the area you see a few bushes amoung widly spaced trees.\n\
Beyond the trees all you can see is darkness. Suddenly a small squirel like\n\
creature scurries across your path and rushes into the next bush making\n\
vertually no noise at all.\n";

  items =
  ({
   "trees",
   "grayish green pine trees",
   "bushes",
   "small green trees",
   });
dest_dir =
({
"/players/lacar/area/crater/crater2","southeast",
"/players/lacar/area/crater/crater7","northwest",
"/players/lacar/area/crater/crater8","northeast",
});
}
