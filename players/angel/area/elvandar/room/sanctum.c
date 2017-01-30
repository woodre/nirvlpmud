/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/sanctum.c   *
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
  short_desc = "~ Spellweaver's Sanctum ~";
  long_desc =
"  The walls of the Spellweaver's Sanctum have been carved\n\
directly in the middle of the ancient Oak and sealed with\n\
healing energies to make sure that the Oak remains alive and\n\
healthy.  The walls of the Sanctum are lined with wooden book\n\
shelves with glass doors which contain the collective whole of\n\
the Elven knowledge, from the time that the first words were\n\
placed upon a Vellum Scroll, to the current events of the Goblin's\n\
War, the Spellweavers are constantly collecting, collating and\n\
cataloguing all the information they can get with in their grasp.\n\
From this point you may go to the North, into the Spellweaver's\n\
Chambers.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/chambers,     "north",
	
  });
}