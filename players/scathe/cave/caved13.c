#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
This is the room of the Guardian Drak.  His sole purpose is to defend\n\
the Drak Lord.  He towers over you and attacks as you enter the room.\n");
    set_light(1);
    set_exits(([
        "west": "/players/scathe/cave/caved15",
		"east":"/players/scathe/cave/caved10.c",
        ]));
}

mixed _east(string arg) {
   if (present("drak", this_object())) {
      write("The drak snarls at you.\n");
      return 1;
   }
   return "/players/scathe/cave/caved14";
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 4;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak7");
            move_object(monster,this_object());
        }
    }
}
