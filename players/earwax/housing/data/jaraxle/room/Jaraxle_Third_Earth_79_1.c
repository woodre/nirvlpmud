#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Lungbutter's Hut[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/jaraxle/room/Jaraxle_Third_Earth_79_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/jaraxle/room/Jaraxle_Third_Earth_79_";
  Entrance = "/players/jaraxle/3rd/warrior/rooms/land_4_sale/land1.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/jaraxle/room/Jaraxle_Third_Earth_79_0.c", "back" });
}
