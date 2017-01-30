/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/f_05.c      *
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
  short_desc = "~ Elven Forest ~";
  long_desc =
"  Two ancient and massive oak trees appear to bend over the path,\n\
the branches and leaves inter-twining above your heads, forming an\n\
arch signifying the entrance to the City of Elvandar.  You have\n\
never seen such an assortment of trees, beasts, birds, and all\n\
sorts of creatures in a forest, that's because the Elven Forest is\n\
alive with the power of magic.  Centuries upon centuries, the Elven\n\
Spellweavers have fashioned the Elven Forest to what you see before\n\
you a vision of beauty and delight.  From this point you may\n\
continue on to the South to the City of Elvandar, North, East, or\n\
West, deeper into the Forest.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/glade",     "north",
	"/players/angel/area/elvandar/room/oak",       "south",
	"/players/angel/area/elvandar/room/f_04",      "east",
	"/players/angel/area/elvandar/room/f_06",      "west",
  });
}