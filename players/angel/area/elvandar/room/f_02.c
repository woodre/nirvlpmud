/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/f_02.c      *
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
dancing to a music you can not hear. You have never seen such an\n\
assortment of trees, beasts, birds, and all sorts of creatures in\n\
a forest, that's because the Elven Forest is alive with the power\n\
of magic.  Centuries upon centuries, the Elven Spellweavers have\n\
fashioned the Elven Forest to what you see before you, a vision of\n\
beauty and delight.  From this point you may continue South or West,\n\
deeper into the Forest.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/f_03",      "south",
	"/players/angel/area/elvandar/room/f_01",      "west",
  });
}