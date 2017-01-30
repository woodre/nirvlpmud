/*                                                                        *
 *      File:             /players/angel/area/lowthar/room/pen_06.c       *
 *      Function:         room                                            *
 *      Author(s):        Angel@Nirvana                                   *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)        *
 *                                All Rights Reserved.                    *
 *      Source:           11/15/06                                        *
 *      Notes:                                                            *
 *                                                                        *
 *                                                                        *
 *      Change History:                                                   *
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
"    "+HIY+"~ Town Hall ~"+NORM+"\n\
"+BROWN+"    This is the inside of the administrative head of the city.\n\
Here the decisions regarding the town of Penrith are made. It is\n\
a simple room with a long wood table and what appears to be twenty\n\
chairs. You notice papers which look like important secret documents\n\
lying around."+NORM+"\n";

  items =
  ({
  });

  dest_dir =
  ({
	"/players/angel/area/lowthar/room/pen_02",   "north",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }