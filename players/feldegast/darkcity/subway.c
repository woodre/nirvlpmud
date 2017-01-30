#include "def.h"

inherit MYROOM;

reset(arg) {
  if(!present("detective"))
    move_object(clone_object(PATH+"Npc/walenski"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="The Subway";
  long_desc=
"     Showers of sparks fly through the air as each train enters this\n\
station.  A poster on the wall advertises the virtues of a vacation\n\
at shell beach, and a stairway leads back up into the night.\n";
  items=({
    "train","Strange.  None of them seem to be taking on passengers",
    "trains","Strange.  None of them seem to be taking on passengers",
    "poster", "A bright poster with a girl sitting on the beach",
    "stairway", "It leads back up to the streets",
  });
  dest_dir=({
    PATH+"street5","up"
  });
}   
