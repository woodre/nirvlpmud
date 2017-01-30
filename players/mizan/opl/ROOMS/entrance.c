inherit "/room/room.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

object greeter;

void reset(int arg)
{
    call_other(ENVIRON_DM, "???");

    if (arg) return;
    set_light(1);

    short_desc = "Entrance to the Proving Grounds of the OverPowerLord";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "Welcome to the Proving Grounds of the OverPowerLord!"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +
        "    Spread out before you is a large plaza that has the qualities of a\n" +
        "  gaudy Las Vegas casino combined with the hopeless optimism of Disney\n"+
        "  World mixed together. Your adventurer's heart can't help but beat\n"+
        "  aflutter at all of the large, gaudy billboards and whatnot.\n"+
        "  The Proving Grounds consist of a giant underground maze which can be\n"+
        "  reached by entering the passageway downwards. Sitting before you in\n"+
        "  this plaza is a large portrait of the OverPowerLord himself, smiling\n"+
        "  maginamously at all who stand before it. To the north is the path\n"+
        "  back to the village spine. To the east is a giant themed sports lounge\n"+
        "  and bar complex. To the west is an open air mall carrying gear tailored\n"+
        "  for repeat adventuring customers of the Proving Grounds.\n" +
/*        "  " + HIY + "TYPE 'wtf' FOR A FREE PARK GUIDE\n" +*/
        "  " + HIY + "GO EAST FOR BOOZE\n" +
        "  " + HIY + "GO WEST FOR MERCH\n" +
        "  " + HIR + "GO DOWN TO KILL THINGS\n" + NORM + NORM;

    items = ( {

        "floor",
        "The floor appears to be made of some fairly high quality granite slabs.\n"+
        "It really looks like some good stuff.",

        "portrait",
        "The broad and grinning smile of the OverPowerLord beckons you further\n"+
        "south, where the entrance to his proving grounds awaits.",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/landing.c", "down",
        "/players/mizan/opl/ROOMS/giftshop.c", "west",
        "/players/mizan/opl/ROOMS/lounge.c", "east",
        "/room/wild1.c", "north",
        /*    "/players/mizan/opl/ROOMS/stathall.c","south", */
    });

    if (!greeter)
    {
        greeter = clone_object("/players/mizan/opl/beasties/greeter.c");
        move_object(greeter, this_object());
    }

    set_no_clean(1);
}

init()
{
    ::init();
}

query_no_fight() {
    return 1;
}
