/*                                                                              *
 *      File:             /players/angel/area/school/room/grade_03.c            *
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
    move_object(clone_object("/players/angel/area/school/npc/teacher_03.c"), this_object());  
  if( !present("student", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/student_03.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "3rd Grade";
  long_desc =
"  This is the 3rd grade classroom. The teacher seems to be\n\
teaching information for the standarized test the students\n\
will be taking next week called TEKS . There are several centers\n\
set up in the classroom to assist the students in their learning\n\
process. There also appears to be some type of a chart on the wall.\n";

  items =
  ({
    "centers",
    "There are four separate centers, each one has a different purpose",
    "chart",
    "This is a behavior management program geared towards improving\n\
students behavior",
    "teks",
    "Teaxs Essiental Knowledge and Skills, a standardized test",
    "room",
    "a classroom full of environmental print",
    "students",
    "Average school aged students",
    "wall",
    "It's a wall",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/school_hall_04", "north",	
  });
}
