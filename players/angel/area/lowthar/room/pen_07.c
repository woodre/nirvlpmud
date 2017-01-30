/*                                                                    *
 *    File:             /players/angel/area/lowthar/room/pen_07.c     *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)      *
 *                              All Rights Reserved.                  *
 *    Source:           12/23/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIY+"Penrith"+NORM;
  long_desc =
"    "+HIY+"~ Blacksmith shop ~"+NORM+"\n\
"+BROWN+"    This large room is filled with various tools that hang on the\n\
wall in the process of being crafted or in a state of readiness.\n\
There is a strange glow coming from the west wall where the forge\n\
lies."+NORM+"\n";

  items =
  ({
  });

  dest_dir =
  ({
	"/players/angel/area/lowthar/room/pen_04",   "east",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }