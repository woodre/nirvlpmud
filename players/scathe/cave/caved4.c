#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
The Draks in this cavern seem a bit bigger and stronger than the ones\n\
to the east.  However, they also rely on numbers for their strength.\n");
    set_light(1);
    set_exits(([
        "east": "/players/scathe/cave/caved2",
        "west": "/players/scathe/cave/caved5",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
/* Changed from 5 to 3  -Snow */
        x = 3;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak2");
            move_object(monster,this_object());
        }
    }
}
