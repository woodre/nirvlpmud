inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "The Hall of Statistical Achievements";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "The Hall of Statistical Achievements"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +

        "    Of all the areas within the Proving Grounds, this is the place which makes\n" +
        "  the only attempt to look stately and uncluttered. A giant dome gracefully\n"+
        "  covers this hall, of which a magical book on a grand podium makes its place\n"+
        "  as the centerpiece. This is where player records within the Proving Grounds is\n"+
        "  automatically archived and kept.\n";

    items = ( {

        "floor",
        "The floor appears to be made of some fairly high quality bathroom tile.",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/entrance.c", "north",
    });

    set_no_clean(1);
}

init()
{
    ::init();
}

