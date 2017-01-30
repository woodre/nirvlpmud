/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 950422 - created
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"

inherit ROOM;

void
create()
{
    ::create();
    set_short("Deep inside the rock");
    set_long("\
A suffocating sense of claustrophobia almost overwhelms you in the\n\
narrow confines of this tunnel. An acrid reek from an opening in\n\
the western wall seeps in mingling with the stale cold air. In the\n\
distance to the north, the tunnel descends and widens before forking\n\
into a northbound and an eastbound gallery. The tunnel continues to\n\
the south.\n\
There is a ladder sticking up from a small hole in the floor.\n");
    set_exits( ([
        "south": (PATH + "descent"),
        "west" : (PATH + "stable"),
        "east" : (PATH + "altar"),
        "north": (PATH + "throne"),
        "down" : (PATH + "garden"),
    ]) );
    set_items( ([
        "tunnel": "The tunnel leads south further into the cave...\n"+
                  "West to the dragon keeper's stable...\n"+
                  "East to the altar of sacrifice...\n"+
                  "North to the throne of Lord Shardak...\n"+
                  "Or down to the Imp's Garden...\n",
        ({ "western wall", "wall" }) : "\
The opening to the western wall leads to the dragon keeper's stable.\n",
        "gallery" : "Which gallery? (northbound/southbound)\n",
        "northbound gallery" : "\
The tunnel wraps perilously to the throne room.\n",
        "southbound gallery" : "\
The tunnel leads south, deeper into the grotto.\n",
       ]));
    set_light(0);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}
