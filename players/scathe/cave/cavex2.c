#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("School Of Hard Knocks");
    set_long("\
You happen upon a makeshift training grounds, which was built around\n\
the arrival of the Wandering Warrior.  He takes a break from training\n\
pupils to challenge you.  Will you accept?\n");
    set_light(1);
    set_exits(([
	"east": "/players/scathe/cave/cavex1",
	]));
}

void reset(int arg) {
    object monster;

    ::reset(arg);
    if (!present("warrior", this_object())) {
	monster=clone_object("/players/scathe/monsters/warrior");
	move_object(monster, this_object());
    }
}

void init() {
   ::init();
   add_action("dir","pick");
}
status dir() {
   write("The warrior slaps away your greedy hands\n");
   this_player()->hit_player(10);
   return 1;
}
