#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("A tunnel in a cavern");
    set_long("\
An opening to the west will lead you to more danger and rewards.\n\
Proceed carefully as the monsters in this area are very strong.\n");
    set_light(1);
    set_exits(([
        "up":   "/players/scathe/cave/caved",
        "west": "/players/scathe/cave/cavex1",
        ]));
}
