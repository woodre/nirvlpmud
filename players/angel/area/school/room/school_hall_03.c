/*                                                                              *
 *      File:             /players/angel/area/school/room/school_hall_03.c      *
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
"  Continuing down the long hallway, there are classrooms to the\n\
north and south. There is a bulletin board of some kind on the\n\
wall. Many students are seen gathering around the board reading\n\
a list that has just been posted!\n";

  items =
  ({
    "hallway",
    "This is a long corridor",
    "students",
    "They appear to be average school students",
    "rooms",
    "They seem to be average classrooms",
    "board",
    "The board is nicely decorated and displays different\n\
lists for school functions",
    "list",
    "The results from tryouts for the school play are listed by grades here",
    "class",
    "This is a group of students",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/grade_05", "north",
    "/players/angel/area/school/room/grade_02", "south",
    "/players/angel/area/school/room/school_hall_02", "east",
    "/players/angel/area/school/room/school_hall_04", "west",	
  });
}