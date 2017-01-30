/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/qs.c        *
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
  short_desc = "~ Elven Queen's Square ~";
  long_desc =
"  The paths of the Queen's Square are made from Oak branches\n\
which inter-twine together to form wide paths which are easily\n\
navigated by the Elven folk, however people who are the Guests\n\
of the Elves are often quite terrified by the heights they have\n\
negotiated.  From the center of the Square you see three ornately\n\
carved wooden doors embossed with the golden scripts of the Elven\n\
language.  The two doors to the North appear to be the largest and\n\
depict the most elaborate carvings, hence you determine that they\n\
lead to the Elven Court. However you are unable to determine the\n\
purpose of the Chambers to the East and West.  From this point you\n\
may go to the North, South, East, or West.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
	"/players/angel/area/elvandar/room/greatc,        "north",
	"/players/angel/area/elvandar/room/s_06",         "south",
    "/players/angel/area/elvandar/room/atrium",       "east",
	"/players/angel/area/elvandar/room/chambers",     "west",
  });
}