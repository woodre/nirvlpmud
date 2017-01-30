#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Just for Kicks");
    set_long("\
  You enter a calm and serene garden, and you are overwhelmed at the\n\
beauty and fragrances which surround you.  A great deal of time and\n\
effort have been put into this accomplishment.  You have entered the\n\
domain of the Monks of the Dragon Fist Order.  Tread carefully stranger.\n");
    set_light(1);
    set_exits(([
	"north":"/players/scathe/cave/monk4",
	"south":"/players/scathe/cave/monk6",
	]));
}
void reset(int arg) {
    int x;
    object monster;

    ::reset(arg);
    if (!present("monk", this_object())) {
/* Changed from 4 to 2 -Snow */
	x = 2;
	while (x--) {
	    monster = clone_object("/players/scathe/monsters/monk");
	    move_object(monster, this_object());
	}
    }
}
