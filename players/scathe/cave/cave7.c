#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Doppleland!");
    set_long("\
You have found a room full of Dopple Pets!!  They don't run like\n\
Dopps, so be careful, they are a little harder to kill.\n");
    set_light(1);
    set_exits(([
        "east": "/players/scathe/cave/cave6",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("dpet", this_object())) {
        x = 4;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/dpet");
            move_object(monster,this_object());
        }
    }
}
