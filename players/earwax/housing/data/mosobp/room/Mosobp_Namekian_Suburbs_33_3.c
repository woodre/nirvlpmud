#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Mosh's Mansion[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/mosobp/room/Mosobp_Namekian_Suburbs_33_3.c";
  RoomNum = 3;
  BaseFilename = "/players/earwax/housing/data/mosobp/room/Mosobp_Namekian_Suburbs_33_";
  Entrance = "/players/mosobp/areas/HOUSING/rooms/h12.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/mosobp/room/Mosobp_Namekian_Suburbs_33_0.c", "back" });
}
