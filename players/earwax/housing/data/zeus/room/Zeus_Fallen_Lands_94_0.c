#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Z's Palace[2;37;0m[2;37;0m";
  Short2 = ": Foyer[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_";
  Entrance = "/players/zeus/realm/taus/guth6.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/zeus/realm/taus/guth6.c", "out",
"/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_1", "north",
"/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_2", "east",
"/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_3", "south",
"/players/earwax/housing/data/zeus/room/Zeus_Fallen_Lands_94_4", "up" });
}
