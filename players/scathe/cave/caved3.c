#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
You have disturbed several Draks in a side tunnel.\n\
They welcome you with slashing teeth, and cutting claws.\n"+
"It looks like you could possible go a little farther to\n"+
"the north but it's pretty dark that way.\n");
    set_light(1);
    set_exits(([
        "south":"/players/scathe/cave/caved2",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
/* Changed from 5 to 3  -Snow */
        x = 3;
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
  write("The small drak steps in front of you and hisses..\n");
  return 1; }
else {
  this_player()->move_player("north#players/scathe/cave/cavex3.c");
  return 1; }
}
