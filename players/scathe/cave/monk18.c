#include "lib.h"
inherit ROOM;

mixed _south(string arg) {
    if (present("elder", this_object())) {
	write("The Elder will not let you pass.\n");
	return 1;
    }
    return "/players/scathe/cave/monk19";
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
	"west":"/players/scathe/cave/monk17",
	"south":"/players/scathe/cave/monk19",
	]));
}
void reset(int arg) {
    int x;
    object monster;

    ::reset(arg);
    if (!present("elder", this_object())) {
/* Changed from 2 to 0  -Snow */
	x = 0;
	while (x--) {
	    monster = clone_object("/players/scathe/monsters/elder");
	    move_object(monster, this_object());
	}
    }
}
