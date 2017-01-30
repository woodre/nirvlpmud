/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/house.c     *
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
  short_desc = "~ Commoner's House ~";
  long_desc =
"  The walls of the Commoner's House have been carved directly\n\
into the middle the ancient Oak and sealed with healing energies \n\
to make sure that the Oak remains alive and healthy.  On the\n\
Eastern walls there are several beautiful paintings of ancient\n\
Warriors, forgotten wars, and ancestors who have passed on to the\n\
Blessed Isles.  The House, while warm and comfortable, lacks the\n\
elaborate decor that you would have expected of an Elf.  To the\n\
North there is a wooden door which leads to the sleeping chambers.\n\
From this point you may go East, upon the Elven Paths.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/es_04",     "east",
  });
}