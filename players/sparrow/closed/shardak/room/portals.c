/*
 * Portal room. Fast passage to important rooms
 * Balowski@Nirvana, October '95
 * revised by Vertebraker
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
inherit ROOM;

void
create()
{
    ::create();
    set_short("The Portals");
    set_long("\
Changing winds whirl around, arising from nowhere. One instant biting\n\
cold, the next burning hot. Wailing voices of imprisoned souls cross\n\
dimensions in this warped space. Many wavering holes torn in the fabric\n\
of space provide swift passage to several key locations in Nirvana.\n\
The portals are: North, northeast, east, southeast, south, southwest,\n\
northwest, and west.\n\
You can also go back 'out' to the grotto.\n");
    set_exits(([
        "northwest" : "/room/ravine",
        "northeast" : "/room/plane12",
        "southwest" : "/room/eastroad2",
        "southeast" : "/room/sea",
	  "north" : "/room/vill_green",
        "south" : "/players/catwoman/tl",
	  "east" : "/players/saber/ryllian/rift",
        "west" : "/room/south/sforst24",
        "out" : "/players/vertebraker/closed/shardak/room/grotto",
    ]));
    set_items(([
      ({ "portals", "holes", "wavering holes" }) : "\
The northern     portal leads to the village green.\n\
The northeastern portal leads to a marble shrine.\n\
The eastern      portal leads into a rift in the space/time continuum.\n\
The southeastern portal leads to the sea.\n\
The southern     portal leads to the thieves' lockers.\n\
The southwestern portal leads to the wheel of time.\n\
The northwestern portal leads to the ravine.\n\
The western      portal leads to the dark forests.\n",
    ]));
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}
