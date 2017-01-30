#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Viper's Shack[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "[2;37;0mThis is a shitty ass shack which was built with Hercules' money! HA![2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/earwax/room/Earwax_Fields_8_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/earwax/room/Earwax_Fields_8_";
  Entrance = "/players/earwax/area/fields/room/fields4.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/area/fields/room/fields4.c", "out" });
}
