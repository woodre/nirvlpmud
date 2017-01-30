#include "ansi.h"
inherit "room/room";
reset(arg)  {
  if(arg)  return;


short_desc = "A Portal Room";
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/TEMPLE/CLERICS/c1.c","southeast",
"players/mosobp/areas/TEMPLE/CLERICS/c4.c","northeast",
"players/mosobp/areas/TEMPLE/CLERICS/c3.c","east",
});
}
