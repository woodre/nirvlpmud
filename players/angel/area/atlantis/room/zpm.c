/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/zpm.c       *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/15/07                                      *
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
  short_desc = "ZPM";
  long_desc =
"      "+WHT+"~ Z.P.M. OUTLET ROOM ~"+NORM+"\n\
"+HIB+"  The heart of Atlantis is the Z.P.M. outlet room. At the center\n\
of this chamber is a triangular space where up to three Zero\n\
Point Modules can network to provide power to the city for\n\
thousands of years. Any Z.P.M. slot can run the city by itself,\n\
but the units can also take turns powering the city."+NORM+"\n";

  items =
  ({
    "chamber",
    "a large room",
    "slot",
    "a place where the zpm connects to the power source",
    "unit",
    "a zpm",
    "units",
    "the zpm's",
    "zpm",
    "zero point module",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_17.c",     "west",
  });
}