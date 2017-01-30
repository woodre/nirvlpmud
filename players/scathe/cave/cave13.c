#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Doppleland!");
    set_long("\
As you enter, you notice these Wussy Dopples are a bit different\n\
from those you've slain before.  They seem to admire their badges\n\
a little too much, and wave it in your face.\n\
They must be the Wussy Leaders.....\n");
    set_exits(([
        "east": "/players/scathe/cave/cave12",
        ]));
    set_light(1);
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("dlead", this_object())) {
        x = 2;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/dlead");
            move_object(monster,this_object());
        }
    }
}
