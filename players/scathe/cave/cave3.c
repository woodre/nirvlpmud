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
        "south":"/players/scathe/cave/cave6",
        "west": "/players/scathe/cave/cave4",
        "north":"/players/scathe/cave/cave2",
        "east": "/players/scathe/cave/cave5",
        ]));
    set_light(1);
}
