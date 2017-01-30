/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/stall.c     *
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
  short_desc = "~ Elven Stallions Stall ~";
  long_desc =
" The walls of the Elven Stallions Stall have been carved directly\n\
into the middle of the ancient Oak and sealed with healing energies\n\
to make sure that the Oak remains alive and healthy.  On the Eastern\n\
wall there are several sacks of Elven Wheat for the Stallions to eat\n\
and fresh sweet hay or them to rest upon.  The Stallions are looked\n\
after with the greatest of detail since they are free beasts and choose\n\
to remain in the magical forest and serve the Royal Court by their own\n\
choice.  From this point you may go to the east, into the Stables.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/stables",     "east",
  });
}