inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);
   
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
         "/players/shinshi/areas/school/rooms/floor1/hallwayr17.c",	"south",
         "/players/shinshi/areas/school/rooms/floor1/hallwayr19.c",	"west",
         "/players/shinshi/areas/school/rooms/floor1/hillyer.c",	"north",
         "/players/shinshi/areas/school/rooms/floor1/mens2.c",	"mens",
         "/players/shinshi/areas/school/rooms/floor1/womens2.c",	"womens",
    });
}