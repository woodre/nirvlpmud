/*                                                                    *
 *    File:             /players/angel/area/town/room/10thna.c        *
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

reset(arg)
{
  ::reset(arg);
  if( !present("multi", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi.c"), this_object());
  if( !present("multi02", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi_02.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "10th & North A";
  long_desc =
"    "+HIY+"Tenth and North A street"+NORM+"\n\
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
    "/players/angel/area/town/room/10thnb", "north",
    "/players/angel/area/town/room/emain_10", "south",
  });
}