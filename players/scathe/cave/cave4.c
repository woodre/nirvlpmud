#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Doppleland!");
    set_long("\
You are in a newbie zone filled with wimpy little dopples for your\n\
beating pleasure.  These shouldn't be to hard to kill, and are a\n\
great way to start off your adventuring career.\n");
    set_light(1);
    set_exits(([
        "east": "/players/scathe/cave/cave3",
        ]));
}

void reset(int arg) {
    object  monster;
    int     x;

    ::reset(arg);
    if (!present("dopp", this_object())) {
        x = 5;
        while (x--) {
            monster = clone_object("/players/scathe/monsters/dopp");
            move_object(monster, this_object());
        }
    }
}
