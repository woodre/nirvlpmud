/*                                                                              *
 *      File:             /players/angel/area/school/room/grade_04.c            *
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
    move_object(clone_object("/players/angel/area/school/npc/teacher_04.c"), this_object());
  if( !present("student", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/student_04.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "4th Grade";
  long_desc =
"   This is the 4th grade classroom. The students are gathered on\n\
the floor for independent reading. The room is nicely decorated\n\
with a retro historical look. When you look around the room you see\n\
there are several statues that sit just behind the teachers desk.\n";

  items =
  ({
    "statues",
    "These statues look like grey marble and are about 10' tall.\n\
These statues are of great historical philosophers. Some of\n\
the statues are of Socrates, Plutarh, Plato, Aristotle, Quintilian,\n\
Charlemagne, and many others. ",
    "class work",
    "You see short stories written in english class",
    "floor",
    "You see new carpet",
    "teachers desk",
    "There are stacks of papers on the desk,\n\
you also notice a bible on the corner", 
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/school_hall_04", "south",
  });
}