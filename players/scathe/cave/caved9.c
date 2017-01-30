#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
The caverns here are far more spacious than the ones previously\n\
traveled in.  There is a rumbling sound that travels to you from\n\
somewhere deeper in the caverns.....\n");
    set_light(1);
    set_exits(([
        "south":"/players/scathe/cave/caved8",
        "north":"/players/scathe/cave/caved10",
        ]));
}
