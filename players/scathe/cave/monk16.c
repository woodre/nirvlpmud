#include "lib.h"
inherit ROOM;

mixed _west(string arg) {
    if (present("master", this_object())) {
	write("The Master will not let you pass.\n");
	return 1;
    }
    return "/players/scathe/cave/monk15";
}

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
	"north":"/players/scathe/cave/monk14",
	"west":"/players/scathe/cave/monk15",
	]));
}
void reset(int arg) {
    int x;
    object monster;

    ::reset(arg);
    if (!present("master", this_object())) {
/* Changed from 3 to 2  -Snow */
	x = 2;
	while (x--) {
	    monster = clone_object("/players/scathe/monsters/mmaster");
	    move_object(monster, this_object());
	}
    }
}
