#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Colony Way Subdivision"+NORM;
  long_desc =
"  Towards the north it appears Colony Way is coming to an end.\n\
A circle drive with large oak trees in the center can be seen.\n\
Looking around there appears to be forest areas scattered around\n\
inside the walls providing security and privacy to the home owners.\n\
228 Colony Way is toward the west.\n";

  items =
  ({
    "circle",
    "A planar region bounded by a circle in this case it is a\n\
traffic circle",
    "drive",
    "This is a private road that connects the houses and garages\n\
with the street.",
    "oak",
    "These are numerous monoecious deciduous or evergreen trees\n\
and shrubs of the genus Quercus, bearing acorns as fruit",
    "tree",
    "This is a perennial woody plant having a main trunk and with\n\
a distinct crown",
    "forest",
    "There are dense growth of trees, plants, and underbrush\n\
covering a large area",
    "walls",
    "The walls are formed by the large fences that have gone up",
    "owner",
    "They are wealthy people of diverse backgrounds",
  });
  dest_dir =
  ({
    "/players/angel/area/colony/room/colony_06", "north",
    "/players/angel/area/colony/room/colony_04", "southwest",
  });
}

init() {
  ::init();
    add_action("enter","228");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_15.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
