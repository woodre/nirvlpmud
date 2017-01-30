#include "/players/guilds/bards/bard_lib/lib.h"
inherit ROOM;

void create() {
    ::create();
    set_long("You are in a laboratory.\nThis is a test of the random room.\n");
    set_short("Laboratory");
    add_smell("dominant", "You sense the smell of old grease and welding.\n");
    add_item("laboratory", "There are nuts and bolts everywhere.\n");
    add_monster("/players/balowski/examples/giant", 1);
    set_monster_frequency(10);
    set_light(1);
}
