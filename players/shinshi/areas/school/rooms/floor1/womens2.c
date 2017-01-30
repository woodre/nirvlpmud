inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);
   
if(!present("shinshi_female_student")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/student2.c"),this_object());
}
   
   if(arg) return;
   set_light(1);
   short_desc = HIW+"Women's Room"+NORM;
   long_desc =
		"One wall of this room is lined with mirrors and sinks.  Along the\n"+
		"opposite wall there are five stalls with toilets inside.  The stall\n"+
		"dividers are covered in random graffiti.  There is a vending machine\n"+
		"on the wall that dispenses feminine hygiene products.\n";
   
   items =
   
   ({
         "wall",
         "A large, white brick wall",
         "mirrors",
         "Large, dirty mirrors",
         "sinks",
         "Sinks that are covered in dirt",
         "wall",
         "stalls",
         "Five toilets in different stalls",
         "toilets",
         "Rusty toilets",
         "stall dividers",
         "Thick plastic dividers keep the stalls seperate",
         "graffiti",
         "Vulgar words are written everywhere",
         "vending machine",
         "It sells tampons but they're out of stock",
         "dirt",
         "A thick layer of dirt covers the sink",
         "vulgar words",
         "FUCK! CUNT! BITCH TITS",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr18.c",	"out",
    });
}