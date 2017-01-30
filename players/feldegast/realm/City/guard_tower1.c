#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Ironheart Tower";
  long_desc=
"  Ironheart tower, the legendary tower from which Gravin Ironheart\n"+
"made his famous last stand in the last Majiri uprising, has a\n"+
"commanding view of the city of Haven and the surrounding terrain.\n"+
"The edges of the tower's roof are crenelated with merlons, large\n"+
"stones from which the tower's soldiers can defend the tower.\n";
  items=({
    "view","You see the notorious coliseum of Haven, the cathedral, and\n"+
           "Haven's famous skyline",
    "terrain","You see the sparkling ocean to the west, the mountains to\n"+
              "the north, and thick woods to the south and east",
  });
  dest_dir=({
    PATH+"Haven/guard_tower3","down"
  });
}   
