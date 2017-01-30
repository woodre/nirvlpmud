#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Newbie Land");
    set_long("\
This is Scathe's Wussy Dopple Newbie land.  The monsters to\n\
the south are a bit tougher than the ones at this intersection\n\
so be careful, and remember to turn on those wimpies!!!\n");
    set_exits(([
        "south":"/players/scathe/cave/cave15",
        "west": "/players/scathe/cave/cave13",
        "north":"/players/scathe/cave/cave9",
        "east": "/players/scathe/cave/cave14",
        ]));
    set_light(1);
}
