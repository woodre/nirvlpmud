/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/throne.c    *
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
  short_desc = "~ Elven Throne Chamber ~";
  long_desc =
"  The walls of the Throne Chamber had been formed from\n\
the branches of the ancient Oak, centuries upon centuries,\n\
the Spellweavers have applied their magics to shape and\n\
mold the branches as the Oak matured into what it is this\n\
day.  On the Northern wall there are two golden thrones,\n\
the largest of which has been positioned in the center of\n\
the Chamber and clearly is occupied by the Ruling Lord or\n\
Lady of Elvandar.  From this Chamber the Queen makes the\n\
decisions which will affect her people for decades and\n\
centuries, long after the mortal men have traveled to the\n\
Bless Isles and been forgotten. From this point, you may go\n\
to the South, into the Great Chamber.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
	"/players/angel/area/elvandar/room/greatc",     "south",
  });
}