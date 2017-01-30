/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/dr01.c      *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/08/08                                      *
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
  short_desc = "Thanagar";
  long_desc =
"Dirt Road      \n";

  items =
  ({
  });
  dest_dir =
  ({
	"/players/angel/area/thanagar/room/rstall.c",	"north",
	"/players/angel/area/thanagar/room/gshack.c",	"south",
	"/players/angel/area/thanagar/room/dr02.c",  	"east",
	"/players/angel/area/thanagar/room/base.c",  	"west",
  });
}