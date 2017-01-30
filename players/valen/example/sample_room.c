/*                                                                    *
 *    File: (EXAMPLE)  /players/angel/area/thanagar/room/entrance     *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/07                                      *
 *    Notes:            Area Entrance                                 *
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
  short_desc = "Short Room Name";
  long_desc =
"  This is just some text to give the sample room some fill so that \n\
it doesn't look empty when Katya looks at it for an example of \n\
something roomy and spacious in a good neighborhood\n";

  items =
  ({
    "item",
    "description",
    "another",
    "It looks like this",
  });
  dest_dir =
  ({
    "/room/vill_green.c",           "green",
    "/players/vital/workroom.c",    "home",
  });
}
