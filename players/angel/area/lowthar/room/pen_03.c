/*                                                                        *
 *      File:             /players/angel/area/lowthar/room/pen_03.c       *
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
"    "+HIY+"~ Rawley's farm ~"+NORM+"\n\
"+BROWN+"  This is the edge of town which is the only road that leaves Penrith.\n\
Towards the south there is a small barn where farmer Rawley keeps his\n\
oxen that can be seen. The closest village was Grimwood Vale to the\n\
southeast and Grim Wood forest lies past that to the east."+NORM+"\n";

  items =
  ({
  });

  dest_dir =
  ({
	"/players/angel/area/lowthar/room/pen_02",   "west",
    "/players/angel/area/lowthar/room/pen_03",   "southeast",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }