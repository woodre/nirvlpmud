inherit "/room/room.c";
#include "/obj/ansi.h"

object board;

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "Observation Deck of the OverPowerLord";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "The Observation Deck"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +

        "    An absolutely staggering number of flatscreen displays greets you\n"+
        "  upon entering this room. The walls seem to be solid rock here, and more\n"+
        "  carved into the side of earth than in the lounge, which has a half-built\n"+
        "  open patio sort of feel. Upon looking closer at some of the monitors,\n"+
        "  you discover that they are trained upon some of the other levels in the\n"+
        "  proving ground itself. There is a sort of voyeuristic glee in sitting\n"+
        "  here observing all the carnage... and you're tempted to do just that.\n";

    items = ( {

        "floor",
        "The floor appears to be made of some fairly high quality bathroom tile.",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/lounge.c", "north",
    });

    set_no_clean(1);

    if (!board)
    {
        board = clone_object("/players/mizan/opl/environs/top-player-board.c");
        move_object(board, this_object());
    }

}

init()
{
    ::init();
}

