inherit "/room/room";
#include <ansi.h>

reset(arg)
{
   ::reset(arg);
   
   if(arg) return;
   set_light(1);
   short_desc = HIR+"Men's Room"+NORM;
   long_desc =
   		"One wall of this room is lined with mirrors and sinks.  Along the\n"+
		"opposite wall there are two stalls with toilets inside as well as\n"+
		"three urinals.  The stall dividers are covered in random graffiti.\n"+
		"There is an odd smell in here, a mix of cleaners and years of piss.\n";
   
   items =
   
   ({
         "test",
         "Test this",
    });
   
   dest_dir =
   ({
         "/players/shinshi/areas/school/rooms/floor1/hallwayr18.c",	"out",
    });
}