inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);
   
   if(!present("zimmerman")){
	   move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/zimmerman.c"), this_object());
   }
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"Mrs. Zimmerman's Classroom"+NORM;
   long_desc =
		"There are twenty-four desks in this room, grouped in six small groups\n"+
		"of four.  Four windows let in the light, brightening the room. Along\n"+
		"one wall there is a teacher's desk, with a bookcase behind it. There\n"+
		"are painting supplies stored on a shelf, and to one side of the door\n"+
		"is some kind of folder system.\n";
   
   items =
   
   ({
         "desks",
         "Small wooden desks for each student",
         "windows",
         "Large windows that let in the light",
         "light",
         "The light is blinding",
         "wall",
         "Large, white bricks",
         "teacher's desk",
         "The teacher's large wooden desk",
         "bookcase",
         "Biograpies of famous artists",
         "painting supplies",
         "Brushes, paint, etc.",
         "shelf",
         "A shelf filled with painting supplies",
         "door",
         "A large wooden door with a small glass window",
         "folder system",
         "A folder system to keep works seperated",
         "brushes",
         "Slightly used painting brushes",
         "paint",
         "Red, blue, yellow, green, etc.",
         "painting brushes",
         "Slightly used brushes used for painting",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr20.c",	"north",
    });
}