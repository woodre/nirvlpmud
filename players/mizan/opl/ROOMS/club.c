inherit "/room/room.c";
#include "/obj/ansi.h"

object poker;

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "The Severed Head";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "The Severed Head - OverPowerLord's Employee Lounge"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +

        "    A spectacularly comfortable looking lounge greets you. The walls are\n"+
        "  adorned with pictures from the younger days of MUD gaming- a distant\n"+
        "  and more elegant age... A giant picture of Beek, Lan, Blackthorn, and\n"+
        "  OverPowerLord himself grouped in front of an SGI Power Challenge server\n"+
        "  in some sort of ribbon cutting ceremony takes a prominent place in the\n" +
        "  lounge area. Clusters of tables are neatly gathered along the walls\n"+
        "  and it suddenly dawns on you that this is REAL sunlight, albeit hundreds\n"+
        "  of feet underground. It must be piped in via a fiber optic bundle\n"+
        "  or something cool like that.\n";

    items = ( {

        "floor",
        "The floor appears to be made of some fairly high quality granite tile.",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/hole.c","north",
    });

    if (!poker)
    {
        poker = clone_object("/players/mizan/opl/environs/poker_machine.c");
        move_object(poker, this_object());
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

