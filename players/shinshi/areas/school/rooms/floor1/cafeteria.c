inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);
   
if(!present("shinshi_male_student")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/student.c"),this_object());
}
if(!present("shinshi_female_student")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/student2.c"),this_object());
}
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"The Cafeteria"+NORM;
   long_desc =
		"This is a very large room filled with rows and rows of tables. Each\n"+
		"table has small, plastic seats connected to the table legs.  In the\n"+
		"front of the room there are three cafeteria lines.  To one side there\n"+
		"is a flight of stairs leading upward.  There is an opening in one wall\n"+
		"with a counter where trays can be left at the end of the meal.\n";
   
   items =
   
   ({
         "test",
         "Test this",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr7.c","south",
    });
}
