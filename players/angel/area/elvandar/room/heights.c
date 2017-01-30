/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/heights.c   *
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
  short_desc = "~ Heights Of Elvandar ~";
  long_desc =
"  To the West are the Spiral Stairs, winding from East to West,\n\
just as the rising and setting motion of the sun, which connect\n\
the Tree Top City of Elvandar and the Elven Forest.  While you\n\
suppress the urge to look down, you feel your heart rising higher\n\
and higher in your throat with pure exhilaration.  From the\n\
Heights of Elvandar you can barely make out the features of the\n\
Tree Top City and Elven Forest beneath.  You may look out upon\n\
the magical lands and see dragons engaged in mortal combat in the\n\
skies to the North.  From this point you may continue to the West,\n\
to the City of Elvandar and the Elven Forest below.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
	"/players/angel/area/elvandar/room/s_07",      "down",
  });
}