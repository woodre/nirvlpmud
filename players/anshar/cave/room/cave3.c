#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(0);
  short_desc="A dark cave";
  long_desc =
"The cave splits off here, and a loud rumbling noise can be heard\n\
repetetively from the east. There is a light coming from the south,\n\
and the stench seems to be emanating from this direction.\n";
  items =
  ({
    "cave",        "Dark granite walls, beaded with moisture",
    "walls",       "Dark granite walls, beaded with moisture",
    "water",       "Moisture drips down the walls in dark, cool rivulets",
    "moisture",    "Moisture drips down the walls in dark, cool rivulets",
    "rivulets",    "Moisture drips down the walls in dark, cool rivulets",
  });
  dest_dir =
  ({
    CROOM+"cave2", "north",
    CROOM+"cave5", "south",
    CROOM+"cave4", "east",
  });
}
