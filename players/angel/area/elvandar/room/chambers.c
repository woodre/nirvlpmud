/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/chambers.c  *
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
  short_desc = "~ Spellweaver's Chambers ~";
  long_desc =
"  The walls of the Spellweavers Chambers have been carved\n\
directly in the middle of the ancient Oak and sealed with\n\
healing energies to make sure that the Oak remains alive and\n\
healthy.  The Spellweavers serve as the Counselors to the\n\
Queen's Court and have thousands and thousands of volumes and\n\
tomes of ancient lore and history in order to assist the Queen\n\
in making her decisions.  Not many of the Elven folk have the\n\
knowledge or skills required to under go the rigorous training\n\
of an Spellweaver and hence their words are heeded much attention\n\
when they make their voice known on a matter.  From this point you\n\
may go South, or East, into the Queen's Court.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/sanctum",     "south",
	"/players/angel/area/elvandar/room/qs",          "east",
  });
}