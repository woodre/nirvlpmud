/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/es_08.c     *
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
  short_desc = "~ Elven Square ~";
  long_desc =
" The paths of the Elven Square are made from Oak branches which
inter-twine together to form wide paths that are easily navigated by
the Elven folk, however people who are the Guests of the Elves are
often quite terrified of the heights they have negotiated.  In the center
of the Square, which is commonly occupied by a magnificent fountain
in a Human city, the Elves have bound several branches to form a
canopy from the sun's warmth, however you can look through the
center of the Square and barely make out the features of the Forest
beneath.  From this point you may go East or West, upon the Elven
Paths.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/es_06",     "east",
	"/players/angel/area/elvandar/room/es_07",     "west",
  });
}