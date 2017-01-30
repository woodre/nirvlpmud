/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/oak.c       *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           05/15/07                                      *
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
  short_desc = "~ Oak ~";
  long_desc =
"  The lush green carpet of the Elven Forest is adorned with\n\
golden, silver, crimson, and emerald leaves from the Massive\n\
Oak, you think to yourself that it is odd that one tree can\n\
have such an assortment of colours on its leaves, however you\n\
realize that this is no ordinary Oak, rather the entrance to\n\
the mythical City of Elvandar, heart of the Elven Forest.  Upon\n\
closer examination of the Oak, you can make out small steps\n\
carved into its girth, winding their way to the West, just as\n\
the sun, towards the Tree Top City.  From this point you may\n\
take the Stairs, towards Elvandar, or North, deeper into the\n\
Elven Forest.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/f_05",      "north",
	"/players/angel/area/elvandar/room/s_01",      "stairs",
  });
}