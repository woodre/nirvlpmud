#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sin's Palace[2;37;0m[2;37;0m";
  Short2 = ": [1;34m G[0m[34mate[0m[1;34m W[0m[34may[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m[1;34mThis is the entranceway to the palace, to the north there is a hall \nand to the east is a stairway. The floor is made from granite while \npedestals stand along the hall in the distance. [2;37;0m[2;37;0m [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_";
  Entrance = "/players/mythos/aroom/village.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/mythos/aroom/village.c", "out",
"/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_1", "sin",
"/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_7", "ancient" });
}
