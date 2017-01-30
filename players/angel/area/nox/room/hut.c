inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/hut.c            *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           07/01/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>


reset(arg)
{
  ::reset(arg);
if(arg) return;
  set_light(1);
  short_desc = "Large hut";
  long_desc =
"    ~A large Hut~\n\
  This is the living quarters of the Nox Family.  It is a large\n\
open area with a couple of mats, a table with six chairs, and two\n\
rocking chairs.  Everything in this room appears to have been\n\
made from item within the forest.\n";

  items =
  ({
    "mats",
    "They appear to be made from tree leaves",
    "mat",
    "It appears to be made from tree leaves",
    "table",
    "It looks like it was made from dead trees",
    "chairs",
    "They look like they're made from dead trees",
    "chair",
    "It looks like it was made from dead trees",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f12.c",    "down",	
  });
}
