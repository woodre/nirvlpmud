inherit "/room/room.c";
#include "/obj/ansi.h"
object uncle;
object machine;

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "A very sketchy room";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "Uncle Touchy's Laboratory"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +

        "   The festive and tacky decor of Overpowerlord's realm gives way to a creepy\n"+
        "  and downright weird atmosphere here. It's almost as if this giant room were\n"+
        "  not meant for the masses to trudge into. An eclectic mixture of vintage\n"+
        "  pinups, Japanese anime, hentai, and tentacle rape images adorn the walls.\n"+
        "  Everything seem to have a layer of grease covering it, which also goes\n"+
        "  against the sort of relatively high standards you are used to within the\n"+
        "  Proving Grounds of the Overpowerlord... unless this particular place is\n"+
        "  some sort of front for another operation...\n";

    items = ( {

        "floor",
        "The floor is gritty concrete, covered with sawdust and sand.",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/giftshop.c", "north",
    });

    if (!uncle)
    {
        uncle = clone_object("/players/mizan/opl/beasties/uncle_touchy.c");
        move_object(uncle, this_object());
    }

    if (!machine)
    {
        machine = clone_object("/players/mizan/opl/environs/vending-machine.c");
        move_object(machine, this_object());
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

