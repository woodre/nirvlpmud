/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/rf.c        *
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
  short_desc = "~ The Fork ~";
  long_desc =
"  The crystal clear waters of the Elven River appear to be moving\n\
a little quicker at the Fork, to the West you can hear what you\n\
believe to be the roar of thunder, perhaps there is a storm brewing\n\
in the distance, while to the East the river slowly makes its winding\n\
way to the ancient City, and to the North the horizon of the City of\n\
Migaard is slowly being consumed by the beautiful sights of the Elven\n\
Forests.  Due to the magical nature of the Elven Forest you are\n\
either basked in the glow of the warm sunshine or pale moon light,\n\
there only appears to be one season in the forest, that of spring.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/er_02",     "north",
	"/players/angel/area/elvandar/room/ef",        "east",
	"/players/angel/area/elvandar/room/wf",        "west",
  });
}