#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Target Practice");
    set_long("\
As you enter the room you notice many targets hanging as if someone\n\
were shooting at them.  Lo and behold, there is an archer here,\n\
sharpening his skill.  Hmm, you think he might be looking at you as\n\
if you were a target instead of a person.....\n");
    set_light(1);
    set_exits(([
        "down": "/players/scathe/cave/cavex1",
        ]));
}

void reset(int arg) {
    object monster;

    ::reset(arg);
    if (!present("archer", this_object())) {
        monster=clone_object("/players/scathe/monsters/bowman");
        move_object(monster, this_object());
    }
}

void init() {
   ::init();
   add_action("dir","pick");
}
status dir() {
   write("The archer pops you with a bolt for your troubles\n");
   this_player()->hit_player(10);
   return 1;
}
