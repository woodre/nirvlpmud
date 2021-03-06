#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Deathseeker's Palace[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_105_8.c";
  RoomNum = 8;
  BaseFilename = "/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_105_";
  Entrance = "/players/dragnar/WalkingDead/rooms/p2.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_105_0.c", "back" });
}
