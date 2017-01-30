#include <ansi.h>

inherit "room/room.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Colony Way Subdivision"+NORM;
  long_desc =
"  This is the beginning of Colony Way Subdivision. The road curves\n\
around several times. This is where the rich and powerful reside.\n\
There are several large homes and a couple that qualify as mansions.\n\
All of the lawns are perfectly manicured and the air smells of fresh-\n\
cut grass. 221 Colony Way is to the east and 222 is to the west.\n";

  items =
  ({
    "road",
    "It is a concrete paved road, top of the line",
    "home",
    "There are several family structures of high quality\n\
and workmanship",
    "homes",
    "There are several family structures of high quality\n\
and workmanship",
    "mansion",
    "This is a large and stately dwelling house built in a\n\
completely gracious style, with gardens, parks and drives.\n\
It is comprised four wings in a square surrounding a central\n\
courtyard",
    "mansions",
    " These are large and stately dwelling houses built in a\n\
completely gracious style, with gardens, parks and drives.\n\
Many are comprised of four wings in a square surrounding a\n\
central courtyard",
    "grass",
    "This is narrow-leaved green herbage grown as lawns.",
    "lawn",
    "A plot of grass, usually tended or mowed, as one around\n\
a resident estate",
    "lawns",
    "Plots of grass, usually tended or mowed, as one around\n\
a residence or in a park or estate",
    "subdivision",
    "This is an area of land composed of subdivided lots",
  });
  dest_dir =
  ({
    "/players/angel/area/colony/room/colony_02", "north",
    "/players/angel/area/town/room/4thnh", "south",
  });
}

cmd_smell(str) {
  write("You smell the fresh cut grass in the air.\n");
  return 1;
}

init() {
  ::init();
    add_action("enter"); add_verb ("221");
    add_action("walk"); add_verb ("222");
    add_action("cmd_smell","smell");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_09.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

walk(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward towards the lawn.\n");
    this_player()->move_player(
    "walking over to the lawn#/players/angel/area/colony/land/land_10.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
