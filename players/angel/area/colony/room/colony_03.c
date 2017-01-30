#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Colony Way Subdivision"+NORM;
  long_desc =
"  The road continues to curve around in Colony Way. This\n\
subdivision seems to be very quiet. The only noise heard around\n\
here is the birds chirping. The view of this subdivision is\n\
exquisite with all the rolling hills and large oak trees.\n\
225 Colony Way is toward the east.\n";

  items =
  ({
    "road",
    "It is a concrete paved road, top of the line",
    "subdivision",
    "This is an area of land composed of subdivided lots",
    "birds",
    "They are ordinary blue birds flying around from tree to tree",
    "hills",
    "They are well-defined natural elevation's smaller than a mountain",
    "oak",
    "These are numerous monoecious deciduous or evergreen trees\n\
and shrubs of the genus Quercus, bearing acorns as fruit",
    "trees",
    "This is a perennial woody plant having a main trunk and with\n\
a distinct crown",
  });
  dest_dir =
  ({
    "/players/angel/area/colony/room/colony_02", "southwest",
    "/players/angel/area/colony/room/colony_04", "east",
  });
}

init() {
  ::init();
    add_action("enter","225");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_13.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
