inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);

   if(!present("thompson")){
	   move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/thompson.c"), this_object());
   }
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"Mr. Thompson's Classroom"+NORM;
   long_desc =
		"In this room, there is a student computer on one side of the door.  On\n"+
		"the other side is a row of sinks.  There are a few large trash cans in\n"+
		"the back of the room, and the walls are decorated with student art\n"+
		"projects.  A colorful sculpture hangs from the ceiling.  There is a\n"+
		"chalkboard in the front of the room, and a teacher's desk and overhead\n"+
		"projector across from the door.\n";
   
   items =
   
   ({
         "computer",
         "An older Dell computer",
         "door",
         "A large wooden door with a small window",
         "sinks",
         "Sinks stained with paint",
         "trash cans",
         "Trash cans filled with paper towels and newspapers",
         "walls",
         "Large, white bricks",
         "student art",
         "Well-drawn art from previous graduates",
         "art projects",
         "Well-drawn art from previous graduates",
         "chalkboard",
         "A large black chalkboard",
         "teacher's desk",
         "A large wooden desk for the teacher",
         "overhead projector",
         "An overhead projector that is currently turned off",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr16.c",	"west",
    });
}