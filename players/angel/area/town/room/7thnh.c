/*                                                                    *
 *    File:             /players/angel/area/town/room/7thnh.c         *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           6/15/07                                       *
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
  if(arg) return;
  set_light(1);
  short_desc = "7th & North H";
  long_desc =
"  "+HIM+"Seventh and North H street"+NORM+"\n\
  H street is the furthest road north of the city.  There are\n\
sidewalks on both sides of the road with many large oak trees\n\
along each side.  To the south of H street is all houses and\n\
The elementary school is visible to the north.\n";

  items =
  ({
	"road",
	"It is a two lane road",
	"city",
	"It is a small quiet town where many people live",
	"sidewalks",
	"They appear to be well worn with many cracks",
	"trees",
	"Large oak trees with large leaves",
	"houses",
	"Average middle class homes",
	"school",
	"A long brick building with many windows",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/entrance.c",     "north",
    "/players/angel/area/town/room/8thnh",            "east",
    "/players/angel/area/town/room/6thnh",            "west",
  });
  move_object(clone_object("/players/angel/area/town/npc/multi_mover.c"), this_object());
}