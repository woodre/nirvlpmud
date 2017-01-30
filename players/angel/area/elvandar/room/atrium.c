/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/atrium.c    *
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
  short_desc = "~ Atrium Of The Temple ~";
  long_desc =
"  The walls of the Atrium of the Temple have been\n\
carved directly into the middle of the ancient Oak\n\
and sealed with healing energies to make sure that\n\
the Oak remains alive and healthy.  The walls of the\n\
Atrium are adorned with elegant tapestries which depict\n\
Tomas' victories against the vile, corruptible, and evil\n\
inhabitants of Primula.  Elven globes, magical lights,\n\
line the walls of the Temple and cast playful shadows\n\
upon the smooth wooden floor.  You ponder the mysteries\n\
and meaning of life as you approach the Inner Sanctum of\n\
the Temple.  From this point you may go to the North, or\n\
West, back into the Queen's Square.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/temple,     "north",
	"/players/angel/area/elvandar/room/qs",        "west",
  });
}