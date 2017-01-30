inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);
   
   if(!present("green")) { 
	   move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/green.c"),this_object());
}
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"Mrs. Green's Classroom"+NORM;
   long_desc =
		"A long counter runs from the door to one corner in this room. There\n"+
		"are four sinks equally spaced along the counter, with cabinets above\n"+
		"them.  There is a whiteboard in the front of the room, a teacher's\n"+
		"desk with a computer off to one side, and about twenty-five student\n"+
		"desks in the center.\n";
   
   items =
   
   ({
         "test",
         "Test this",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr15.c",	"east",
    });
}