#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sami's Shack[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/zone/room/Zone_Forest_77_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/zone/room/Zone_Forest_77_";
  Entrance = "/players/zone/rooms/path4.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/zone/rooms/path4.c", "out" });
}
