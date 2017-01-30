/*
*      File:            /players/lacar/area/crater/crater.2.c
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
    for(x=0; x<4; x++)
    {
  move_object(clone_object("/players/lacar/area/crater/npc/dowin.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Crater 2";
  long_desc ="This area has been hit by a meteor and it is not known how it has \n\
affected this place. The ground slants down a little and the grass has\n\
started to change color. The trees seem to take on a life if thier\n\
own.\n";
  items =
  ({

   });
dest_dir =
({
"/players/lacar/area/crater/crater1", "southeast",
"/players/lacar/area/crater/crater4",  "northwest",
"/players/lacar/area/crater/crater5",  "northeast",
});
}
