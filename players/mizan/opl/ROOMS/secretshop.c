inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "A secret shop";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "Hodson's Wide World of Legal Contraband"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +

        "   Sandwiched between the main store and parts unknown is this\n"+
        "  strange little place. Locked cabinets from floor to ceiling house\n"+
        "  many unmarked cardboard boxes, their contents unknown. A narrow\n"+
        "  service desk with bars in front gives the only hint of interaction\n"+
        "  between you and whoever is running this place. The seat behind the\n"+
        "  counter is unoccupied, and aside from a service bell there is\n"+
        "  nothing else on the desktop space itself.\n";

    items = ( {

        "floor",
        "The floor appears to be made of some fairly high quality bathroom tile.",

        "bell",
        "Perhaps you could 'ring' this bell.",

        "counter",
        "It is covered with a large, hard plastic sheet.",

    });


    set_no_clean(1);
}


init()
{
    ::init();
    add_action("on_ring", "ring");
}

on_ring(string str)
{
    if(!str || str != "bell") return 0;

    write("You ring the service bell. There doesn't seem to be anyone nearby.\n");
    say(this_player()->query_name() + " rings the service bell.\n");
    return 1;
}

