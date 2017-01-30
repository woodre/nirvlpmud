/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/f_03.c      *
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
"  Massive and ancient oak trees tower above you as you stand\n\
on the lush green carpet of the Elven Forest, leaves of gold,\n\
silver, crimson, and emerald sway to and fro in the warm breezes,\n\
dancing to a music you can not hear.  You have never seen such\n\
an assortment of trees, beasts, birds, and all sorts of creatures\n\
in a forest, that's because the Elven Forest is alive with the\n\
power of magic.  Centuries upon centuries, the Elven Spellweavers\n\
have fashioned the Elven Forest to what you see before you, a\n\
vision of beauty and delight.  From this point you may continue\n\
on to the North, South and West, deeper into the Forest.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/f_02",      "north",
	"/players/angel/area/elvandar/room/f_04",      "south",
	"/players/angel/area/elvandar/room/glade",     "west",
  });
}