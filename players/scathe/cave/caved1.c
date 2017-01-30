#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Caverns");
    set_long("\
You have entered the cavern of the Draks.  Draks are similar to\n\
dragons but their greatest asset lie not in brute power, but in\n\
their incredible speed.  Draks vary from being small and savage\n\
to extremely large and powerful.  Many adventures await you....\n");
    set_exits(([
        "south":"/players/scathe/cave/caved",
        "west": "/players/scathe/cave/caved2",
        ]));
   set_light(1);
}
