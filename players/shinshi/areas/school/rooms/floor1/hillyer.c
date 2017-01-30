inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);
   
   if(!present("hillyer")){
	   move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/hillyer.c"), this_object());
   }
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"Mr. Hillyer's Classroom"+NORM;
   long_desc =
		"The desks in this room are set up in rows around three of the four\n"+
		"walls.  The fourth wall has a chalkboard on it, and at the end of that\n"+
		"wall, near the windows, is a teacher's desk with a computer and a\n"+
		"chair.  The room is rather bare other than that, and looks almost like\n"+
		"a garage.\n";
   
   items =
   
   ({
         "test",
         "Test this",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr18.c",	"south",
    });
}