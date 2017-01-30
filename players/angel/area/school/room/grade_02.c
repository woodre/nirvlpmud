/*                                                                              *
 *      File:             /players/angel/area/school/room/grade_02.c            *
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
    move_object(clone_object("/players/angel/area/school/npc/teacher_02.c"), this_object());
  if( !present("student", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/student_02.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "2nd Grade";
  long_desc =
"  This is the 2nd grade classroom. This is a very lively\n\
classroom. Students are very active and noisy when they are\n\
working on an art project. This room stays very clean because\n\
they just got new flooring.\n";

  items =
  ({
    "art project",
    "There are several painting hanging on the wall.  From the smell\n\
of things they just finished the paintings",
    "project",
    "a project is something the teacher assigns the students to complete",  
    "desks",
    "You see the desks arranged in a semicircular and the student all\n\
seem to have a clear view of the teacher",
    "desk",
    "The desk is made of wood and metal. The top lid lifts up so Items\n\
can be placed inside",
    "flooring",
    "This appears to be brand new carpet",
    "classroom",
    "A room full of environmental print", 
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/school_hall_03", "north",	
  });
}
