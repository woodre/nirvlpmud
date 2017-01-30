#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("teacher", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/teacher_01.c"), this_object());  
  if( !present("student", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/student_01.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = "1st Grade";
  long_desc =
"  This is the 1st grade classroom. In the corner are several\n\
stacks of sleeping mats. It appears students' lay on the floor\n\
when they take their afternoon nap. Looking around the room the\n\
students' desks appear to be in clusters scattered around the room.\n";

  items =
  ({
    "sleeping mats",
    "The sleeping mats are blue and red. They don't look very comfortable",
    "desk",
    "You see some desks in clusters. They seem to be brand new",
    "floor",
    "there are different rugs that appear to be educational",
    "class",
    "This is a group of young students",
    "room",
    "This is a space where students gather",
    "classroom",
    "It is full of educational material",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/school_hall_02", "north",	
  });
}
