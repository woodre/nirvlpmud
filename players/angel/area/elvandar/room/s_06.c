/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/s_06.c      *
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
  short_desc = "~ Stairs ~";
  long_desc =
"  From East to West, just as the rising and setting motion\n\
of the sun, the Spiral Stairs wind to and fro the Tree Top\n\
City of Elvandar and the Elven Forest.  While you attempt to\n\
suppress the urge to look down, you feel your heart rising\n\
higher in higher in your throat with pure exhilaration.  In\n\
the distance you can barely make out the features of the City\n\
above or the Forest beneath. The steps of the Spiral Stairs\n\
have been carefully carved into the side of the massive oak,\n\
with a great deal of care and detail to make sure the Oak is\n\
not harmed.  From this point you may continue up the stairs,\n\
to the Tree Top City, or down, to the Elven Forest.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/qs",        "stairs",
	"/players/angel/area/elvandar/room/es_06",     "down",
  });
}