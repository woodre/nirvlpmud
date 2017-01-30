/*
*      File:            /players/lacar/area/crater/crater8.c
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
  short_desc = "Crater 8";
  long_desc =
  "  \n\
\n\
\n\
\n\
\n";

  items =
  ({

   });
dest_dir =
({
"/players/lacar/area/crater/crater4","southwest",
"/players/lacar/area/crater/crater5","southeast",
"/players/lacar/area/crater/crater12","north",
});
}
