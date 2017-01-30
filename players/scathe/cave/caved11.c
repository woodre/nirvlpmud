#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
The Drak in this room glowers at you as you enter.  It mutters\n\
in a language you do not understand as it moves to attack you.\n");
    set_light(1);
    set_exits(([
        "west": "/players/scathe/cave/caved10",
        "north":"/players/scathe/cave/caved12",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 1;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak6");
            move_object(monster,this_object());
        }
    }
}
