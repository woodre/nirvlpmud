inherit "/room/room.c";
#include "/obj/ansi.h"

object bunny;
object tripod;

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "A Rabbit Hole";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "The Rabbit Hole - Bunny's Office"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +

        "    You wriggle through the narrow entrance and find yourself in a rabbit\n"+
        "  den of some sort. It's exceptionally clean and spacious for just one\n"+
        "  rabbit of course, and with the enormous, granite desk to one side being\n"+
        "  currently vacant you realize that this must also double as OverPowerLord's\n"+
        "  executive office. It is also exceptionally well lit for a rabbit den as\n"+
        "  well. This would probably be attributed to some of the fiber optic sunlight\n"+
        "  magic being shunted off to this room. This must be where the OverPowerLord\n"+
        "  runs his business and entertains his corporate guests.\n";

    items = ( {

        "floor",
        "The floor appears to be made of very hard pack dirt.",

        "desk",
        "Hewn from a solid chunk of granite, it is covered with resumes and job posting data.\n",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/club.c","south",
    });

    if (!tripod)
    {
        tripod = clone_object("/players/mizan/opl/beasties/tripod.c");
        move_object(tripod, this_object());
    }


    if (!bunny)
    {
        bunny = clone_object("/players/mizan/opl/beasties/bunny.c");
        move_object(bunny, this_object());
    }

    set_no_clean(1);
}

init()
{
    ::init();
}

query_no_fight()
{
    return 1;
}

