/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/stables.c   *
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
  short_desc = "~ Elven Stables ~";
  long_desc =
"  The walls of the Elven Stables have been carved directly\n\
into the middle of the ancient Oak and sealed with healing\n\
energies to make sure that the Oak remains alive and healthy.\n\
There are several wooden pegs on the Northern wall for the\n\
Stable Boy to hang up the Elven Stallion's golden bit and\n\
bridle.  The Stallions are rare indeed, not only do they\n\
possess the ability to fly, but only a dozen or more are\n\
known to be in existence to this day.  Only one of the Royal\n\
Court may command the Stallions and as such they are rarely\n\
seen outside of Elvandar.  From this point you may go to the\n\
North to the Spiral Stairs, or East and West into the Stalls.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/s_02",       "north",
	"/players/angel/area/elvandar/room/stall",      "east",
	"/players/angel/area/elvandar/room/stallm",     "west",
  });
}