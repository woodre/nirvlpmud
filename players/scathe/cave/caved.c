#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("A tunnel in a cavern");
    set_long("\
The monsters to the north are tough, and some of the last ones are\n\
very tough, and only high level characters or a group of mid level\n\
people should attempt them.  More dangers lurk further down.....\n");
    set_exits(([
        "up":   "/players/scathe/cave/cave2",
        "north":"/players/scathe/cave/caved1",
        "south":"/players/scathe/cave/monk1",
        "down": "/players/scathe/cave/cavex",
        ]));
    set_light(1);
}
