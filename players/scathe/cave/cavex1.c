#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("An intersection");
    set_long("\
There are exits all round, each one taking you to some magical and\n\
fearsome creature.  Catch your breath now, for the foes you shall\n\
soon face will not be so giving.....\n");
    set_light(1);
    set_exits(([
	"east": "/players/scathe/cave/cavex",
	"west": "/players/scathe/cave/cavex2",
	"up":   "/players/scathe/cave/cavex5",
	"down": "/players/scathe/cave/cavex6",
	"north":"/players/scathe/cave/cavex4",
	]));
}
