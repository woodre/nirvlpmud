/*                                                                    *
 *    File:             /players/angel/area/lowthar/room/pen_01.c     *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"
 
#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIY+"Penrith"+NORM;
  long_desc =
"    "+HIY+"~ Village road ~"+NORM+"\n\
"+BROWN+"    This is a small village composed of six or seven buildings\n\
and to the east of the village you see a small farm, however,\n\
it's the blacksmith shop to the north which attracts your\n\
attention"+NORM+".\n";

  items =
  ({
    "village",
    "",
    "buildings",
    "",
    "farm",
    "",
    "blacksmith",
    "",
    "shop",
    "",
  });

  dest_dir =
  ({
	"/players/angel/area/lowthar/room/pen_04",   "north",
	"/players/angel/area/lowthar/room/pen_02",   "east",
	"/players/angel/area/lowthar/room/start",    "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }