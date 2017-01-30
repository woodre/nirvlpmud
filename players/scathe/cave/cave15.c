#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Doppleland!");
    set_long("\
Here stands the Grime Reaper, supreme Wussy Dopple.  Laying about\n\
the room are little spy sheets with descriptions of the powers of\n\
other guilds....The Alchemist ones are most prominent of the group.\n\
The Grime Reaper is busy reviewing the sheets to change names, and\n\
add spells to his Wussy Guild........\n\
Warning: Grime is kinda tough, so watch out unless you are level\n\
4 or 5, or have some good stats.\n");
    set_exits(([
        "north":"/players/scathe/cave/cave12",
        ]));
    set_light(1);
}

void reset(int arg) {
    object monster;

    ::reset(arg);
    if (!present("grime", this_object())) {
        monster=clone_object("/players/scathe/monsters/grime");
        move_object(monster,this_object());
    }
}
