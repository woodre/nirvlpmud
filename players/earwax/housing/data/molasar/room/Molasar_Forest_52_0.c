#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Avant's Land[2;37;0m[2;37;0m";
  Short2 = ": The [1mEntrance[0m To [1;32mAvant[0m'[1;32ms[0m [1;31mParty [0m[33mShack[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n\n\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Forest_52_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Forest_52_";
  Entrance = "/players/molasar/FOREST/forest13.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/molasar/FOREST/forest13.c", "out",
"/players/earwax/housing/data/molasar/room/Molasar_Forest_52_1", "room1" });
}
