#include "ansi.h"
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Hallway";
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"/players/mosobp/areas/TEMPLE/CLERICS/c2.c","northwest",
"/players/mosobp/areas/TEMPLE/CLERICS/c3.c","northeast",
"players/mosobp/areas/TEMPLE/rooms/temple8.c","out",
});
}
