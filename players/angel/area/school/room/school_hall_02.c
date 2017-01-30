/*                                                                              *
 *      File:             /players/angel/area/school/room/school_hall_02.c      *
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
  if( !present("librarian", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/librarian_01.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "school hall";
  long_desc =
"  Continuing down the long hallway classrooms begin to appear\n\
to the north and south. All of the rooms connect to this hallway.\n\
There is a large open Library to the north with students reading\n\
silently. Library announcements are hung on the wall!\n";

  items =
  ({
    "hallway",
    "This is a long corridor, about 200 yards",
    "students",
    "They are average school students",
    "rooms",
    "These are standard class rooms",
    "wall",
    "Nothing special, just a wall",
    "library",
    "This Library is very large and open. You feel very comfortable\n\
in this room. There are several large tables with thick leather\n\
covered chairs",
    "announcement",
    "Book fair coming up on January 15. Get a flier to take \n\
home to your parents",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/library_01", "north",
    "/players/angel/area/school/room/grade_01", "south",
    "/players/angel/area/school/room/school_hall_01", "east",
    "/players/angel/area/school/room/school_hall_03", "west",
  });
}