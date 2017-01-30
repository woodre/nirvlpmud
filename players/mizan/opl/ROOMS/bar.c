inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg)
{
    object barkeep, paul;

    if (arg) return;
    set_light(1);

    short_desc = "The Beaver Piss Factory";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "The Beaver Piss Factory - Brewery, Grill, and Chainsaw Repair"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +

        "    In an abrupt change of decor, things suddenly went from full frontal Las\n" +
        "  Vegas to warp speed PLAID as you enter this mishmash of an Irish themed bar.\n"+
        "  Stained and splintered mahogany mouldings haphazardly frame the place, and\n"+
        "  a variety of tacky faux-vintage artwork adorn anywhere which was once bare\n"+
        "  walls in an effort to hide the urine and bloodstains... presumably.\n" +
        "  There is a huge handwritten sign that should be read, listing drinks and\n"+
        "  meals available. Yes, you can repair chainsaws here too. Just read the sign.\n";

    items = ( {

        "floor",
        "The floor appears to be made of some fairly high quality bathroom tile.",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/lounge.c", "south",
    });

    if (!paul)
    {
        paul = clone_object("/players/mizan/opl/beasties/paul.c");
        move_object(paul, this_object());
    }

    if (!barkeep)
    {
        barkeep = clone_object("/players/mizan/opl/beasties/barkeep.c");
        move_object(barkeep, this_object());
    }

    set_no_clean(1);
}

init()
{
    ::init();
    add_action("on_read", "read");
}

on_read(string str)
{
    if(!str || str != "sign") return 0;

    write("A large, beat-up sign has the following written on it:\n"+
    "\n"+
    "DRINK MENU                      COST\n"+
    "A pint of stout                 1000 coins\n"+
    "A shot of whisky                3000 coins\n"+
    "A cockpunch                     5000 coins\n"+
    "\n"+
     "'order stout', 'order whisky', or 'order cockpunch'\n"+
    "for drink service. NO FIGHTING IN THIS ESTABLISHMENT.\n"+
    "\n"+
    "Chainsaw repair is temporarily unavailable.\n"+
    "Repair master awaiting arm transplant.\n"+
    "TRANSACTIONS ARE IN GOLD COINS ONLY\n"+
    "-- WE THANK YOU FOR YOUR PATRONAGE --\n");
    return 1;
}

query_no_fight()
{
    return 1;
}
