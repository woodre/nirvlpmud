inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);

   if(!present("trecanelli")){
	   move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/trecanelli.c"), this_object());
   }
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"Mr. Trecanelli's Classroom"+NORM;
   long_desc =
		"There is a locked cage containing power tools next to the door in this\n"+
		"room.  More than thirty desks in the open area of the room face the\n"+
		"chalkboard.  The room also has a teacher's desk and chair, and an\n"+
		"overhead projector.\n";
		   
   items =
   
   ({
         "cage",
         "A cage filled with power tools",
         "power tools",
         "Power drills, pipe clamps, chisels, miter saws, etc.",
         "door",
         "A large wooden door with a small window",
         "desks",
         "Small wooden desks for students",
         "teacher's desk",
         "A large wooden desk for the teacher",
         "chair",
         "A large, comfortable chair bought for the teacher",
         "overhead projector",
         "An overhead projector which is currently turned off",
         "power driils",
         "Tools used for wood shop",
         "pipe clamps",
         "Tools used for wood shop",
         "chisels",
         "Tools used for wood shop",
         "miter saws",
         "Tools used for wood shop",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr19.c",	"south",
    });
}
