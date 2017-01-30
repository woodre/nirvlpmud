#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Newbie Land (joy joy!)");
    set_long("\
Fun fun fun, more Dopples and other critters\n\
for your exp gaining pleasure!\n");
    set_light(1);
    set_exits(([
        "west": "/players/scathe/cave/cave7",
        "east": "/players/scathe/cave/cave8",
        "north":"/players/scathe/cave/cave3",
        "south":"/players/scathe/cave/cave9",
        ]));
}
