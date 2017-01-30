#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sin's Palace[2;37;0m[2;37;0m";
  Short2 = ": [34mCo[1;34moridore[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m[1;34mThe cooridore stretches in either way. Along the walls you see \nvarious doorways, but for some reason no one can go through most of \nthem. To the west you see the lights brighten as they feel the \napproach of someone in need of their light. Towards the east you see a \nstairwell which leads back above the surface.[2;37;0m[2;37;0m [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_4.c";
  RoomNum = 4;
  BaseFilename = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_";
  Entrance = "/players/mythos/aroom/village.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_3", "east",
"/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_5", "west",
"/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_6", "south" });
}
