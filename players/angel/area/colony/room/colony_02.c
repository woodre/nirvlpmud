#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Colony Way Subdivision"+NORM;
  long_desc =
"  Colony Way continues on towards the northeast. The owners in\n\
this subdivision appear to have five to ten-acres of land each.\n\
The properties are surrounded by elegant wrought-iron fencing\n\
with a sidewalk in front of the fence. 223 Colony Way is toward\n\
the east and 224 is to the northwest.\n";

  items =
  ({
    "owners",
    "They are wealthy people of diverse backgrounds",
    "subdivision",
    "This is an area of land composed of subdivided lots",
    "land",
    "A tract that may be owned, together with everything growing\n\
or constructed on it",
    "properties",
    "This is a piece of real estate",
    "iron",
    "A silvery-white, lustrous, malleable, ductile, magnetic\n\
or magnetizable, metallic element occurring abundantly in\n\
combined forms",
    "fence",
    "A structure serving as an enclosure made of posts joined\n\
together by iron rails",
    "fencing",
    "Material, such as wire, stakes, and rails, used in building\n\
fences",
  });
  dest_dir =
  ({
    "/players/angel/area/colony/room/colony_03", "northeast",
    "/players/angel/area/colony/room/colony_01", "south",
  });
}

init() {
  ::init();
    add_action("enter","224");
    add_action("walk","223");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_11.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

walk(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_12.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
