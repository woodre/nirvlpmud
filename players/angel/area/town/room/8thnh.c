/*                                                                    *
 *    File:             /players/angel/area/town/room/8thnh.c         *
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

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "8th & North H";
  long_desc =
"    "+HIM+"Eighth and North H street"+NORM+"\n\
  H street is the furthest road north of the city.  There are\n\
sidewalks on both sides of the road with many large oak trees\n\
along each side.  The trees provide a lot of shade.  To the\n\
south of H street are many square blocks of houses along with\n\
the entrance of Beech Drive.\n";

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
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/8thng",     "south",
    "/players/angel/area/town/room/9thnh",     "east",
    "/players/angel/area/town/room/7thnh",     "west",
  });
}