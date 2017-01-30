#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
A small group of Draks reside here, and they swarm you\n\
as you enter their domain.\n");
    set_light(1);
    set_exits(([
        "east": "/players/scathe/cave/caved1",
        "north":"/players/scathe/cave/caved3",
        "west": "/players/scathe/cave/caved4",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
/* Changed from 6 to 4  -Snow */
        x = 4;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak");
            move_object(monster,this_object());
        }
    }
}

init() {
  ::init();
  add_action("north","north");
}

north() {
if(present("drak")) {
  write("The drak jumps in front of you and stops you.\n");
  return 1; }
else {
  this_player()->move_player("north#players/scathe/cave/caved3.c");
  return 1; }
}
