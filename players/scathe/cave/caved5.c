#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
As you traverse down the slippery cavern, Draks swirl towards you\n\
to block your progress.\n");
    set_light(1);
    set_exits(([
        "east": "/players/scathe/cave/caved4",
        "northwest":"/players/scathe/cave/caved6",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 2;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak2");
            move_object(monster,this_object());
        }
    }
}
