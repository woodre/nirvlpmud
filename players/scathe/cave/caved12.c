#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
There is a small Drak in this room, and he seems to be under orders\n\
as he hisses excitedly at your approach, and charges at you.\n");
    set_light(1);
    set_exits(([
        "south":"/players/scathe/cave/caved11",
        "east": "/players/scathe/cave/caved14",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 1;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak2");
            move_object(monster,this_object());
        }
    }
}
