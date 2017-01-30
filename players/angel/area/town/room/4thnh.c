inherit "room/room";

#include <ansi.h>


reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "4th & North H";
  long_desc =
"  "+HIM+"Fourth and North H street"+NORM+".\n\
  To the north is the entrance to the Colony Way Subdivision. There\n\
are two large grey limestone entrance signs on each side of the road.\n\
There are exquisite stone lintels, walling stone and stone copings\n\
around the fantastic stone entrance. The original surrounding walls\n\
are made of yorkstone, with cast iron rails and original yorkstone\n\
paving. Further east is Northview Elementary School and Beech Drive.\n";

  items =
  ({
    "entrance",
    "A means or point by which to enter the subdivision",
    "subdivision",
    "This is an area of land composed of subdivided lots",
    "limestone",
    "Sedimentary rocks that are made from the mineral calcite\n\
which came from the beds of evaporated seas and lakes",
    "signs",
    "They appear to be large brick walls with the subdivision's\n\
name on it. It reads Colony Way!",
    "road",
    "It is a concrete paved road, top of the line.",
    "stone",
    "this is a rock or a piece of rock shaped or finished\n\
for a particular purpose",
    "lintels",
    "A horizontal structural member, such as a beam or stone,\n\
that spans an opening, as between the uprights of a door or\n\
window or between two columns or piers",
    "coping's",
    "The top layer or course of a masonry wall, usually having\n\
a slanting upper surface to shed water; a cope.",
    "yorkstone",
    "Yorkstone (york stone)was widely used throughout the UK\n\
yorkstone is now used for garden paths and patios to give\n\
gardens an old look to them which makes yorkstone a very\n\
popular choice",
    "iron",
    "A silvery-white, lustrous, malleable, ductile, magnetic\n\
or magnetizable, metallic element occurring abundantly in\n\
combined forms",
    "rails",
    "A structure made of such bars and supports and forming a barrier or guard; a railing",
    "school",
    "It is a large brick building, with a glass entrance",
  });
  dest_dir =
  ({
    "/players/angel/area/colony/room/colony_01", "north",
    "/players/angel/area/town/room/5thnh", "east",
/*
    "/players/angel/area/school/room/airport", "heli3",
*/
  });
}
/*
init() {
  ::init();
    add_action("east"); add_verb("east");
} 

east() {
    if (call_other(this_player(), "query_level", 0) < 20) {
        write("A strong magic force stops you.\n");
        say(call_other(this_player(), "query_name", 0) +
            " tries to go through the field, but fails.\n");
        return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "fly#/players/angel/area/town/room/5thnh.c");
    return 1;
}
*/
