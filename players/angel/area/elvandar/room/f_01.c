/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/f_01.c      *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
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
their branches and leaves inter-twining above your heads, forming\n\
an arch signifying the entrance to the Elven Forest.  You have\n\
never seen such an assortment of trees, beasts, birds, and all\n\
sorts of creatures in a forest, that's because the Elven Forest\n\
is alive with the power of magic.  Centuries upon centuries, the\n\
Elven Spellweavers have fashioned the Elven Forest to what you see\n\
before you, a vision of beauty and delight.  From this point you may\n\
continue North, to the Elven River, South, East, or West, deeper\n\
into the Forest.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/ford",      "north",
	"/players/angel/area/elvandar/room/glade",     "south",
	"/players/angel/area/elvandar/room/f_02",      "east",
	"/players/angel/area/elvandar/room/f_08",      "west",
  });
}