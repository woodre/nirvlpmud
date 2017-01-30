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
   short_desc = HIW+"A Hallway"+NORM;
   long_desc =
   		"This hallway has large bricks carefully cemented together to\n"+
		"form the white walls. The bricks have been painted white, many\n"+
		"different times. The paint is starting to chip away from the\n"+
		"lack of a good painting in awhile.\n";
   
   items =
   
   ({
         "test",
         "Test this",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr12.c",	"east",
         "/players/shinshi/areas/school/rooms/floor1/hallwayr14.c",	"west",
    });
}