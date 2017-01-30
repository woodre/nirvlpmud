#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("The Chopping Block");
    set_long("\
Present in this room are a blood covered rock slab, and a very large\n\
man in black with a very large axe.  He looks like he has used this\n\
axe before, and it not afraid to again.  He motions you toward the\n\
stone as you enter.....Will you put up a fight, or go in pieces?????\n");
    set_light(1);
    set_exits(([
        "up":   "/players/scathe/cave/cavex1",
        ]));
}

void reset(int arg) {
    object monster;

    ::reset(arg);
    if (!present("executioner", this_object())) {
        monster=clone_object("/players/scathe/monsters/axeman");
        move_object(monster, this_object());
    }
}

void init() {
   ::init();
   add_action("dir","pick");
}
status dir(string arg) {
   write("The executioner thumps you with the haft of the axe\n");
   this_player()->hit_player(10);
   return 1;
}
