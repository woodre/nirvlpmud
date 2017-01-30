/*
*      File:            /players/lacar/area/crater/crater5.c
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
  if( !present("", this_object()) )
  {
    for(x=0; x<4; x++)
    {
  move_object(clone_object(""), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Crater 5";
  long_desc =
  " In this part of the area half of the pine trees had become burnt\n\
due to the force of the meteor crashing down. In certain places some\n\
of the wild flowers try to reform and bloom. The ground is slanted\n\
northward and the grass is starting to turn from brown to green.\n\
\n";

  items =
  ({

   });
dest_dir =
({
"/players/lacar/area/crater/crater2","southwest",
"/players/lacar/area/crater/crater3","southeast",
"/players/lacar/area/crater/crater9","northeast",
"/players/lacar/area/crater/crater8","northwest",
});
}
