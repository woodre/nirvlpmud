/*                                                                        *
 *      File:             /players/angel/area/lowthar/room/pen_02.c       *
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
"    "+HIY+"~ Market ~"+NORM+"\n\
"+BROWN+"    This is an open market that lines the street. Normaly you would \n\
be able to find every thing that you want to buy but, it is too early\n\
for any merchants to be open. "+NORM+"\n";

  items =
  ({
  });

  dest_dir =
  ({
	"/players/angel/area/lowthar/room/pen_05",   "north",
	"/players/angel/area/lowthar/room/pen_06",   "south",
	"/players/angel/area/lowthar/room/pen_03",   "east",
	"/players/angel/area/lowthar/room/pen_01",   "west",
    
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }