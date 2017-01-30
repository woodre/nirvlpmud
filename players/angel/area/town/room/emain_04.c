/*                                                                    *
 *    File:             /players/angel/area/town/room/emain_04.c      *
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
  short_desc = "East Main & 4th";
  long_desc =
"    "+HIB+"East Main and Fourth"+NORM+".\n\
  There is a large mansion to the northeast.  There are several\n\
large two and three story homes on Main Street in this area. All\n\
along main street there are large sidewalks for the citizens to\n\
get around town easily.\n";

  items =
  ({
	"mansion",
	"This is a three story brick home. It appears to have brilliant\n\
workmanship. Some of the windows in the second floor are made of colored\n\
glass. A marvelous site",
	"street",
    "Two way paved lanes with large side walks along the road",
    "sidewalks",
    "A paved path to walk along",
    "citizens",
    "Local people",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_05",       "east",
    "/players/angel/area/town/room/emain_03",       "west",
    "/players/angel/area/mansion/room/mansion_01",  "mansion",
  });
}