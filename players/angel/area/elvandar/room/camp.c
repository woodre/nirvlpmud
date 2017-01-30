/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/camp.c      *
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
  short_desc = "~ Camp ~";
  long_desc =
" The small fire in the center of the Camp casts evil little\n\
shadows upon the rock out cropping, which partially conceals\n\
the Dark Elf war party.  Distant Cousins of the Forest Elves,\n\
they possess some of the same qualities of the Forest Elves.\n\
However to confuse them would be an insult you might not\n\
survive to regret.  You can make out at least two tents, which\n\
means there are probably at least three Dark Elves or their\n\
minions.  While you are at an advantage due to being on higher\n\
ground you can not see into the camp clearly due to the glowing\n\
embers of the fire.  From this point you may continue East,\n\
deeper into the Forest.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/f_06",      "east",
  });
}