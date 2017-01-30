inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("crouch")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/crouch.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIR+"Special Education"+NORM;
	long_desc =
		"This classroom has very few desks in it.  The walls are decorated with\n"+
		"a number line and several posters of kittens.  There is a teacher's\n"+
		"desk in the front of the room with a computer on it, as well as\n"+
		"a small table containing an overhead projector.\n";

   items =
   
   ({
         "desks",
         "Small, wooden desks for students",
         "walls",
         "Walls that have been painted white",
         "number line",
         "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11..",
         "posters",
         "A group of very young, cute kittens",
         "kittens",
         "Orange Tabby, Calico, Bengals, etc",
         "teacher's desk",
         "A large wooden desk with stacks of papers",
         "computer",
         "A Dell OptiPlex 3010",
         "table",
         "A small, wooden table that holds the overhead projector",
         "overhead projector",
         "A overhead projector that is turned off",
    });

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr6.c",	"west",
});
}
