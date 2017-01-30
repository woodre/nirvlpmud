/*                                                                    *
 *    File:             /players/angel/area/town/room/track_01.c      *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/07                                      *
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
  short_desc = "Main Street Tracks";
  long_desc =
"    "+BROWN+"Train tracks"+NORM+"\n\
  The train tracks cross main street and several other locations\n\
in town. The tracks also run into the factories for quicker\n\
distribution. There is a historical sign off to the right with\n\
the tracks 'history'.\n";

  items =
  ({
  "tracks",
  "These are normal railroad tracks. They run through the\n\
west side of town",
});
  dest_dir =
  ({
    "/players/angel/area/town/room/wmain_03", "east",
    "/players/angel/area/town/room/hw_355", "west",
  });
}

init()
  {
  ::init();
  add_action("list_it","history");
  }
  list_it()
  {
  write(
  "The train tracks cross main street and several other locations\n\
in town. The tracks also run into the factories for quicker\n\
distribution. Today the town bears the growth of Indianapolis\n\
metropolitan area which began to develop in the late nineteen\n\
century with the implementation of the Indianapolis and Indian\n\
Central Railway that helped to stimulate its expansion. The\n\
railway helped to develop the area in the beginning of the century.\n\
This strategic location makes Gas City an important piece in the\n\
region's economy and, at the same time, it challenges the county\n\
development.\n\n");
  return 1;
}