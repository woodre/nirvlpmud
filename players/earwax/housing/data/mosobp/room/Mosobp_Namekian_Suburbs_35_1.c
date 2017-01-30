#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Whitehawk's Trailer[2;37;0m[2;37;0m";
  Short2 = ": Bedroom[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mAs you enter the room it looks very plain, a short hallway the opens \nup into a wide room, along the north wall there is a huge bay window, \nalong the east wall there is a double glass sliding door that leads \nout onto a huge cedar deck. Along the south wall there is the huge \nCalifornia King size bed and realize there must be a very large man \nthat sleeps here. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/mosobp/room/Mosobp_Namekian_Suburbs_35_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/mosobp/room/Mosobp_Namekian_Suburbs_35_";
  Entrance = "/players/mosobp/areas/HOUSING/rooms/h15.c";
  get_master();
  items = ({ "Bedroom", "As you enter the room it looks very plain, a short hallway the opens 
up into a wide room, along the north wall there is a huge bay window, 
along the east wall there is a double glass sliding door that leads 
out onto a huge cedar deck. " });
  dest_dir = ({ "/players/earwax/housing/data/mosobp/room/Mosobp_Namekian_Suburbs_35_0.c", "back" });
}
