/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/er_03.c     *
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
  short_desc = "~ Elven River ~";
  long_desc =
" Finally you have reached the source of the thunderous noise,\n\
which sounded like a storm in the distance but in reality is\n\
the rush of crystal clear water cascading over a stone ledge,\n\
down hundreds of feet, to crash upon the rocks below creating\n\
the legendary Elven mists.  The waters of the River begin pulling\n\
your canoe quickly towards your impending fate.  With all your\n\
strength you put your back into the paddle and push off towards\n\
the East and calmer waters.  On the shores you can see the crafts\n\
of more unfortunate adventurers littering the banks, several appear\n\
to have large holes tore into the keel by the jagged edges of rocks\n\
just below the surface.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/wf",      "east",
	"/players/angel/area/elvandar/room/water",   "south",
  });
}