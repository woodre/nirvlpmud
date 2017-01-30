#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Colony Way Subdivision"+NORM;
  long_desc =
"  As the road continues to curve around Colony Way a large\n\
flock of birds flies overhead. This subdivision has a country\n\
feeling. This is a wonderful environment to enjoy that Colony\n\
Way has to offer. 226 Colony Way is toward the northwest.\n";

  items =
  ({
    "road",
    "It is a concrete paved road, top of the line",
    "subdivision",
    "This is an area of land composed of subdivided lots",
    "birds",
    "They are ordinary blue birds fling around from tree to tree",
    "country",
    "This is an area outside of the city, a rural area",
    "environment",
    "The rich environment is filled with trees, bird, green\n\
grass, and a rich fresh air smell",
  });
  dest_dir =
  ({
    "/players/angel/area/colony/room/colony_03", "west",
    "/players/angel/area/colony/room/colony_05", "northeast",
  });
}

init() {
  ::init();
    add_action("enter", "226");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_14.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
