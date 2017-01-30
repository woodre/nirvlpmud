#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
Upon entering this cavern, you immediately notice the two large\n\
Draks.  They are as large as most adult dragons, while retaining\n\
the speed their race is feared for.  You might want to reconsider\n\
disturbing them any further.\n");
    set_light(1);
    set_exits(([
        "south":"/players/scathe/cave/caved9",
        "east": "/players/scathe/cave/caved11",
	"west":"/players/scathe/cave/caved13.c",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 2;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak5");
            move_object(monster,this_object());
        }
    }
}

init() {
  ::init();
  add_action("west","west");
}

west() {
if(present("drak")) {
  write("The large drak hisses and pushes you back.\n"); return 1; }
else {
  this_player()->move_player("west#players/scathe/cave/caved13.c");
  return 1; }
}
