/*                                                                    *
 *    File:             /players/angel/area/lowthar/room/pen_04.c     *
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
"    "+HIY+"~ Blacksmith's yard ~"+NORM+"\n\
"+BROWN+"    This yard was once full of all the blacksmith's supplies he needed\n\
to create armors and swords for the kingdom. It appears it recently\n\
has been emptied.  Now every once in awhile you may see a young boy\n\
scouring the area for left over metal to sell."+NORM+"\n";

  items =
  ({
  });

  dest_dir =
  ({
	"/players/angel/area/lowthar/room/pen_01",   "south",
	"/players/angel/area/lowthar/room/pen_07",   "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }