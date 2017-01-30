/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/temple.c    *
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
  short_desc = "~ Temple Of Tomas ~";
  long_desc =
"  The walls of the Temple have been carved directly into\n\
the middle of the ancient Oak and sealed with healing energies\n\
to make sure that the Oak remains alive and healthy.  Elegant\n\
tapestries adorn the walls of the Temple, depicting the history\n\
of the Elven folk, from the time of the Great Beginning to the\n\
Blessed Isles, every aspect of Elven life has been represented in\n\
the Temple.  Wooden benches line the Northern and Southern walls\n\
of the Temple so that the devoted may have a place to rest, meditate,\n\
and contemplate the lessons of their ancestors.  From this point\n\
you may go South, into the Temple's Atrium.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
	"/players/angel/area/elvandar/room/atrium",     "south",
  });
}