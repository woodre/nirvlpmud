#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
As you slide through the opening, you see some medium sized Draks\n\
gazing at you with great contempt.\n");
    set_light(1);
    set_exits(([
        "southeast":"/players/scathe/cave/caved5",
        "west": "/players/scathe/cave/caved7",
        "north":"/players/scathe/cave/caved8",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 4;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak3");
            move_object(monster,this_object());
        }
    }
}
