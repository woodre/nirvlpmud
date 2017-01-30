inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f06.c            *
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
"    ~A Broad Path~\n\
  This branch of the path widens out after a short distance, and\n\
there are noticeable signs of heavy use. There are footprints here\n\
of an unknown origin. The trees are thinner and smaller in this part\n\
of the forest, giving the impression that it has been recently\n\
cleared.\n";

  items =
  ({
	"trees",
    "The Red wood trees here are a good bit younger and more scarce",
	"tree",
    "The Red wood tree is a good bit younger",
    "footprints",
    "These prints seem to look similar to human prints,\n\
     but something seems a bit off",
    "forest",
    "many large trees and shrubs clumped together",
    "path",
    "A well worn trail",
    "paths",
    "Well worn trails",
    "shrubs",
    "Small red bushy leaves with an array of beautiful blooms\n\
which look siminular to Crape myrtles",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f03.c",    "south",
    "/players/angel/area/nox/room/f05.c",    "east",
    "/players/angel/area/nox/room/f07.c",    "west",
  });
}
