#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Doppleland!");
    set_long("\
You walk into a room full of what seem to be monsters, but you\n\
realize that they are Wussy Dopple Morphs!\n\
Some Alchemist must be on the prowl for them to have changed...\n");
    set_exits(([
        "west": "/players/scathe/cave/cave9",
        ]));
    set_light(1);
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("morph", this_object())) {
        x = 3;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/morph");
            move_object(monster,this_object());
        }
    }
}
