/*
*      File:            /players/lacar/area/crater/crater1.c
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
  if( !present("bush", this_object()) )
  {
    for(x=0; x<2; x++)
    {
  move_object(clone_object("/players/lacar/area/crater/npc/bush.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Crater 1";
  long_desc = 
  " In this part of the area the trees look as if they were  trying to\n\
make a wall to protect the forest. The trees are evenly spaced but\n\
seem to almost be touching.  They give way to two paths leading into\n\
the unknown.\n";
  

  items =
  ({
	  "trees",
	  "Different kinds of trees",
	  "wall",
	  "Trees lined up in a row",
	  "paths",
	  "Dirt paths leading in northern directions",
	  "forest",
	  "All different kinds of trees",
   });
dest_dir =
({
"/players/lacar/area/crater/archway","up",
"/players/lacar/area/crater/crater2","northwest",
"/players/lacar/area/crater/crater3","northeast",
});
}
