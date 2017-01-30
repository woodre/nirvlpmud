/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/glade.c     *
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
  short_desc = "~ Elven Glade ~";
  long_desc =
" Special attention has been placed upon the Sacred Glade by the\n\
Spellweavers, this is the nexus of magic which keeps the Forest\n\
alive and healthy.  In the center of the Sacred Glade there are\n\
seven ancient oak trees representing Truth, Justice, Honor, Loyalty,\n\
Courage, Reverence, and Knowledge which form the Circle of Light.\n\
Protective wards have been put into place to make sure that no one\n\
may defile the sanctity of this place with violence.  The Elven\n\
Brook flows from a small spring in the center of the Circle.  From\n\
this point you may continue North, East, South, West, deeper into\n\
the Elven Forest.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/f_01",      "north",
	"/players/angel/area/elvandar/room/f_05",      "south",
	"/players/angel/area/elvandar/room/f_03",      "east",  
	"/players/angel/area/elvandar/room/f_07",      "west",
  });
}