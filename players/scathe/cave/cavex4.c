#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("A noisy place");
    set_long("\
Your eyes wince and your ears pop as you enter the lair of the mighty\n\
Dragonne.  Hmm, maybe you should go south now before it takes notice\n\
of you.....\n");
    set_light(1);
    set_exits(([
        "south":"/players/scathe/cave/cavex1",
	"north":"/players/scathe/cave/cavexdem.c",
        ]));
}

void reset(int arg) {
    object monster;

    ::reset(arg);
    if (!present("dragonne", this_object())) {
        monster=clone_object("/players/scathe/monsters/dragonne");
        move_object(monster, this_object());
    }
}

init() {
  ::init();
  add_action("north","north");
}

north() {
if(present("dragonne")) {
  write("The dragonne blocks your path!\n"); return 1; }
else {
  this_player()->move_player("north#players/scathe/cave/cavexdem.c");
  return 1; }
}
