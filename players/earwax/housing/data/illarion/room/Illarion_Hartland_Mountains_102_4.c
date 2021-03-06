#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Mythago's House[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/illarion/room/Illarion_Hartland_Mountains_102_4.c";
  RoomNum = 4;
  BaseFilename = "/players/earwax/housing/data/illarion/room/Illarion_Hartland_Mountains_102_";
  Entrance = "/players/illarion/hart/room/meadow.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/illarion/room/Illarion_Hartland_Mountains_102_0.c", "back" });
}
