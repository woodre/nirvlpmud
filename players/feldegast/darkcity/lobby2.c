#include "def.h"
inherit MYROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="An office building";
  long_desc=
"     This is the lobby of a luxurious office building.  A battery of\n\
elevators lead upstairs while a flight of steps leads down to the\n\
heated pool beneath the building.  A pair of double doors to the east\n\
lead out.\n";
  items=({
    "elevators", "The elevators appear to have only one destination...How odd",
    "steps", "They lead downstairs",
    "pool", "It isn't here",
    "doors", "Glass doors with bronze fixtures",
  });
  dest_dir=({
    PATH+"street7","east",
    PATH+"droffice","up",
    PATH+"pool","down"
  });
}
