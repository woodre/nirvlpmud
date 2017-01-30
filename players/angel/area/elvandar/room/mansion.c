/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/mansion.c   *
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
  short_desc = "~ Noble's Mansion ~";
  long_desc =
"  The walls of the Noble's Mansion have been carved directly into\n\
the middle of the ancient Oak and sealed with healing energies to\n\
make sure that the Oak remains alive and healthy.  On the Northern\n\
and  Southern walls of the Mansion there are ornately and delicately\n\
woven tapestries depicting the Royal Court and honor's that this Clan\n\
has achieved through out the centuries.  While warm and comfortable,\n\
the Mansion is more elaborate than the Commoner's House, but not as\n\
splendid as you have expected.  From this point you may go West, upon\n\
the Elven Paths.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/es_05",     "west",
  });
}