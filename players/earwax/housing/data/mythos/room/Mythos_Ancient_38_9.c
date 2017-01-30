#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sin's Palace[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_9.c";
  RoomNum = 9;
  BaseFilename = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_";
  Entrance = "/players/mythos/aroom/village.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_7", "south" });
}
