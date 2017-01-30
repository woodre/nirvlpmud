/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/es_01.c     *
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
"  The paths of the Elven Square are made from Oak branches\n\
which inter-twine together to form wide paths that are easily\n\
navigated by the Elven folk, however people who are Guests of\n\
the Elves are often quite terrified of the heights they have\n\
negotiated.  In the center of the Square, which commonly\n\
occupied by a magnificent fountain in a Human city, the Elves\n\
have bound several branches to form a canopy from the sun's\n\
warmth, however you can look through the center of the Square\n\
and barely make out the features of the Forest beneath.  From\n\
this point you may go East or West, upon the Elven Paths, or\n\
North, onto the Spiral Stairs.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/s_05",      "north",
	"/players/angel/area/elvandar/room/es_03",     "east",
	"/players/angel/area/elvandar/room/es_02",     "west",
  });
}