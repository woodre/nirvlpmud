inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f03.c            *
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
"    ~A Corner Path~\n\
  This path is fairly even and well-used, so the going is not as rough\n\
as the previous paths. Giant, ancient trees tower over everything\n\
on all sides.\n";

  items =
  ({
	"trees",
    "Giant red wood trees that look to be over 100 years old",
    "tree",
    "A giant red wood tree that looks to be over 100 years old",
    "path",
    "A well worn trail",
    "paths",
    "Well worn trails",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f06.c",    "north",
    "/players/angel/area/nox/room/f02.c",    "east",
  });
}
