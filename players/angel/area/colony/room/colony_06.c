#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Colony Way Subdivision"+NORM;
  long_desc =
"  This is the end of Colony Way. There is a large circle\n\
drive here. In the center of the circle drive there are several\n\
large oak trees with ivy and other plants covering the ground\n\
around them. This area is very well-manicured and appears to be\n\
very vital. 227 Colony Way is toward the east and 230 is to the\n\
west.\n";

  items =
  ({
    "circle",
    "A planar region bounded by a circle in this case it is a\n\
traffic circle",
    "drive",
    "This is a private road that connects a houses and garages\n\
with the street.",
    "oak",
    "These are numerous monoecious deciduous or evergreen trees\n\
and shrubs of the genus Quercus, bearing acorns as fruit",
    "tree",
    "This is a perennial woody plant having a main trunk and with\n\
a distinct crown",
    "ivy",
    "These are trailing evergreen plants of the genus Hedera native\n\
to the Old World, they have palmately lobed leaves, root-bearing\n\
stems, and small green flowers grouped in umbels",
    "plants",
    "These plants have no permanent woody stem, they appear to\n\
be herbs",
    "ground",
    "The solid surface of the earth",
    "manicured",
    "Clip and trim evenly and closely. A well manicure a hedge",
    "vital",
    "It is full of life and animated",
  });
  dest_dir =
  ({
    "/players/angel/area/colony/room/colony_05", "south",
  });
}

init() {
  ::init();
    add_action("enter", "227");
    add_action("walk", "230");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_17.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

walk(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_16.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
