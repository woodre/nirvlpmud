#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sin's Palace[2;37;0m[2;37;0m";
  Short2 = ": [34mS[1;34mtairwell[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m[1;34mThe stairwell stretches up and down. Upwards there is bright light \nwhile downwards there is a soft glow. The walls are made of stone \nslabs with jagged cracks in them from the moisture. Echos can be heard \nas though each person who descended or ascended in the past has kept \nthe sound of their footsteps in this enchanted place.[0m[2;37;0m[2;37;0m [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_2.c";
  RoomNum = 2;
  BaseFilename = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_";
  Entrance = "/players/mythos/aroom/village.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_1", "up",
"/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_3", "down" });
}
