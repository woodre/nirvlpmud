/*                                                                              *
 *      File:             /players/angel/area/school/room/school_hall_01.c      *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "School Hall";
  long_desc =
"  This is the long hallway that runs from one side of the\n\
school to the other side. All of the rooms connect to this\n\
hallway. The students' classwork can be seen hanging on the\n\
wall including some nice art projects they have completed.\n";

  items =
  ({
    "hallway",
    "This is a long corridor",
    "rooms",
    "There are many standard class rooms",
    "art projects",
    "There are several painting hanging on the wall. From the smell\n\
of things they just finished the paintings",
    "class work",
    "You see some interesting poems the students wrote\n\
in English class",
    "school",
    "This is a large brick building",
    "wall",
    "The walls are tan covered with students work",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/entrance", "east",
    "/players/angel/area/school/room/school_hall_02", "west",
  });
}