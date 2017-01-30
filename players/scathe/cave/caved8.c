#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
These Draks are slightly larger than their medium cousins.\n\
They peer at you, as if there were some intelligence behind their\n\
gleaming black eyes....\n");
    set_light(1);
    set_exits(([
        "south":"/players/scathe/cave/caved6",
        "north":"/players/scathe/cave/caved9",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 4;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak4");
            move_object(monster,this_object());
        }
    }
}
