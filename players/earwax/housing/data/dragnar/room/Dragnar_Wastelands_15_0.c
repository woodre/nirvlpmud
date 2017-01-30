#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Shadowstone's Hut[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/dragnar/room/Dragnar_Wastelands_15_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/dragnar/room/Dragnar_Wastelands_15_";
  Entrance = "/players/dragnar/WasteLands/rooms/townrd.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/dragnar/WasteLands/rooms/townrd.c", "out",
"/players/earwax/housing/data/dragnar/room/Dragnar_Wastelands_15_1", "grave" });
}
