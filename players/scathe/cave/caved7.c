#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
More Draks sneak along this side corridor, hoping to catch an easy\n\
snack by surprise......\n");
    set_light(1);
    set_exits(([
        "east": "/players/scathe/cave/caved6",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
/* Changed from 4 to 3 -Snow */
        x = 3;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak3");
            move_object(monster,this_object());
        }
    }
}
