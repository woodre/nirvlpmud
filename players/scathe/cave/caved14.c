#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
The waiting area for the Drak Lord, you see a Drak curiously studying\n\
some object.  He looks up as you enter, and moves forward to kill you.\n");
    set_light(1);
    set_exits(([
        "west": "/players/scathe/cave/caved12",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 1;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak4");
            move_object(monster,this_object());
        }
    }
}
