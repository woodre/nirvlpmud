inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);

   if(!present("mader")) { 
	   move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/mader.c"),this_object());
}
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"Mrs. Mader's Classroom"+NORM;
   long_desc =
		"There are chalkboards on either side of this room.  In front of one\n"+
		"there is an overhead projector, and in front of the other is a\n"+
		"teacher's desk with a computer and a lot of neatly organized notes.\n"+
		"There are about twenty student desks in the center of the room.\n"+
		"The walls are decorated with posters showing numbers and colors in\n"+
		"French.\n";
   
   items =
   
   ({
         "test",
         "Test this",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr14.c",	"north",
    });
}