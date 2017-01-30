/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/stallm.c    *
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
  short_desc = "~ Elven Mare's Stall ~";
  long_desc =
"  The walls of the Elven Mare's Stall have been carved directly\n\
into the middle of the ancient Oak and sealed with healing energies\n\
to make sure that the Oak remains alive and healthy.  On the Western\n\
wall there are several sacks of Elven Oats for the Mares to eat and\n\
fresh sweet hay for them to rest upon.  The Mares are looked after\n\
with the greatest of detail since they are free beasts and choose to\n\
remain in the magical forest and serve the Royal Court by their own\n\
choice.  From this point you may go to the West, into the Stables.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/stables",     "west",
  });
}