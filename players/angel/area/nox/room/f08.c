inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f08.c            *
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
  short_desc = "forest";
  long_desc =
"    ~A Bend in the Path~\n\
  This is a point where the path bends to the north.\n\
Giant, ancient trees tower over everything on all sides.\n";

  items =
  ({
	"tree",
    "A giant red wood tree that looks to be over 100 years old",
    "trees",
    "Giant red wood trees that look to be over 100 years old",
    "path",
    "A well worn trail",
    "paths",
    "Well worn trails",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f09.c",    "north",
    "/players/angel/area/nox/room/f07.c",    "east",
  });
}
