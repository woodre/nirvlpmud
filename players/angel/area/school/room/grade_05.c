/*                                                                              *
 *      File:             /players/angel/area/school/room/grade_05.c            *
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
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("teacher", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/teacher_05.c"), this_object());
  if( !present("student", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/student_05.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "5th Grade";
  long_desc =
"  This is the 5th grade classroom. This walls are filled with\n\
diverse environmental print in the room. A student from any\n\
background would feel comfortable in this class. You also notice\n\
that the teacher has a whole bookcase filled with educational\n\
teaching books.\n";

  items =
  ({
    "teachers desk",
    "There are stacks of papers on the desk, you also notice a bible\n\
on the corner",
    "books",
    "They are siting on the bookcase, you may be able to look at\n\
the titles.",
    "bookcase",
    "You see a large bookcase filled with educational books. you may be\n\
able to look at the titles of the books with the proper knowledge",
    "titles",
    "Teaching students with diverse needs\n\
Communication in action\n\
Teaching reading today\n\
Foundations of American Education",
    "print",
    "Posters, signs, pictures and the like",
    "wall",
    "It's a wall",
    "class",
    "A room full of students",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/school_hall_03", "south",
  });
}