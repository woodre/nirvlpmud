/*                                                                    *
 *    File:             /players/angel/area/town/room/10th_country.c  *
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
  if(arg) return;
  set_light(1);
  short_desc = "10th";
  long_desc =
"  This area is outside of the city.  There are many large\n\
oak trees everywhere you can see.  A dirt road leads to the\n\
south.\n";

  items =
  ({
    "city",
	"It can be seen towards the south",
	"trees",
	"Large oak trees with large leaves",
	"road",
	"A small, well-worn, dirt road",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/10thnh",   "south",
  });
}