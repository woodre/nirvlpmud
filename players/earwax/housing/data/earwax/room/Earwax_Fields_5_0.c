#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Whitehawk's Trailer[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "[2;37;0mThe Foyer is a simple room there is mint green paint on the walls and ceramic tile on the floors. \nTo the left is a coat rack that could also be used for hanging umbrellas. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/earwax/room/Earwax_Fields_5_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/earwax/room/Earwax_Fields_5_";
  Entrance = "/players/earwax/area/fields/room/fields5.c";
  get_master();
  items = ({ "The", "Foyer is a simple room there is mint green paint on the walls and 
ceramic tile on the floors. To the left is a coat rack that could also 
be used for hanging umbrellas. " });
  dest_dir = ({ "/players/earwax/area/fields/room/fields5.c", "out",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_5_1", "room1",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_5_2", "room2" });
}
