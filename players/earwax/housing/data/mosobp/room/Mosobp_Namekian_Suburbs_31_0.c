#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Whitehawk's Shack[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "[2;37;0mYou have entered into a small but comfortable shack, straight ahead \nis the ammenities of a kitchen. Off to your right is the double sized \nbed and off to the left is a few chairs, a table and a tv. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/mosobp/room/Mosobp_Namekian_Suburbs_31_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/mosobp/room/Mosobp_Namekian_Suburbs_31_";
  Entrance = "/players/mosobp/areas/HOUSING/rooms/h9.c";
  get_master();
  items = ({ "door", "This is a steel door" });
  dest_dir = ({ "/players/mosobp/areas/HOUSING/rooms/h9.c", "out" });
}
