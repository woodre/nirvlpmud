#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Z's 0[2;37;0m[2;37;0m";
  Short2 = ": [31mTo[1;30mwe[0m[31mr o[1;30mf t[0m[31mhe [1;30mBl[0m[31mac[1;30mk Z[0m[31mod[1;30mia[0m[31mc[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_";
  Entrance = "/players/zeus/realm/taus/guth6.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_0", "south" });
}
