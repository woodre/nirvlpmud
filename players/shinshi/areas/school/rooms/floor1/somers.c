inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);
   
   if(!present("somers")) { 
	   move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/somers.c"),this_object());
}
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"Mrs. Somers Classroom"+NORM;
   long_desc =
		"This room has six large tables in it instead of the usual desks.\n"+
		"There are four chairs around each table.  The room contains a\n"+
		"refrigerator and six ovens.  All around the walls are cabinets full of\n"+
		"kitchen supplies.  Off to one side is the teacher's desk and chair.\n";
   
   items =
   
   ({
         "tables",
         "Large, metal tables with sanitzer all over them",
         "chairs",
         "Sturdy, wooden chairs with green cushions",
         "refrigerator",
         "A large, white refrigerator",
         "ovens",
         "Large ovens used for baking",
         "walls",
         "Walls that have been painted white",
         "cabinets",
         "Some hold utensils, some hold plates, etc",
         "supplies",
         "Old bay, pepper, salt, flour, sugar, etc",
         "desk",
         "A large, wooden desk for the teacher",
         "chair",
         "A large, padded black chair for the teacher",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr17.c",	"east",
    });
}