#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Z's 0[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_4.c";
  RoomNum = 4;
  BaseFilename = "/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_";
  Entrance = "/players/zeus/realm/taus/guth6.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_7", "up",
"/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_0", "down",
"/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_5", "north",
"/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_6", "east" });
}
