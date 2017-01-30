/*                                                                    *
 *    File:             /players/angel/area/town/room/10thng.c        *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/07                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("multi02", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/town/npc/multi_02"), this_object());
    }
  }
  if(arg) return;
  set_light(1);
  short_desc = "10th & North G";
  long_desc =
"    "+HIY+"Tenth and North G street"+NORM+"\n\
  This road is at the edge of town.  There are sidewalks on both\n\
sides of the road with many large oak trees along each side.  The\n\
trees provide plenty of shade for people looking for cover.\n";

  items =
  ({
	"road",
	"It is a two lane road",
	"town",
	"It is a small quiet city where many people live",
	"sidewalks",
	"They appear to be well worn with many cracks",
	"trees",
	"Large oak trees with large leaves",
	"people",
	"There are people scurrying here and there",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/10thnh",     "north",
    "/players/angel/area/town/room/10thnf",     "south",
  });
}