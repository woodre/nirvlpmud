#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Gogeta's Shack[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_72_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_72_";
  Entrance = "/players/maledicta/cont/rooms/82.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/maledicta/cont/rooms/82.c", "out" });
}
