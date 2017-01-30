/* Path 1, Created <5/14/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A narrow path";
  long_desc=
    "  The path through the fields narrows as it winds past a pile of rocks.\n"+
    "The high grass that borders each side of the trail ends abruptly just\n"+
    "to the north, and short, squatty trees are visible in the distance.\n"+
    "There are several vines of blackberries and small, yellow flowers peek\n"+
    "through the thickets within the grass. The path continues south toward\n"+
    "the docks and north to an intersection.\n";
  items=({
    "fields",
    "The field stretches east and west along the shoreline. The high grass\n"+
    "is a deep green in color, and yellow wildflowers are visible in the\n"+
    "undergrowth",
    "rocks",
    "A pile of rocks, recently pushed aside from the path",
    "grass",
    "The grass is approximately three feet high",
    "path",
    "A narrow dirt path, mixed with sand and bits of gravel",
    "trees",
    "The short trees are spindly and without leaves",
    "vines",
    "Thickets of blackberry vines, with ripe blackberries and thorns",
    "flowers",
    "Bright, yellow wildflowers that grow on the weeds in the underbrush",
    "docks",
    "A warehouse and cabin are visible beside the boardwalk that leads\n"+
    "the docks",
    "warehouse",
    "The warehouse is a large, two-story building",
    "cabin",
    "The cabin has a brickwork chimney, and a spiral of smoke is visible",
    "intersection",
    "The intersection to the north travels to the north, east, and west" });
  dest_dir=({
    PATH+"path2.c","north",
    "/players/jara/area1/docks/room/path2.c","southeast" });
}
