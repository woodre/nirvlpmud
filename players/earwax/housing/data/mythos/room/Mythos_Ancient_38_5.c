#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sin's Palace[2;37;0m[2;37;0m";
  Short2 = ": [34mA[1;34mncient[0m [34mL[1;34mibrary[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m[1;34mUpon the walls there are shelves of books five stories high. To the \nright is a ladder one would use to climb up to get a certain book. In \nthe center of the room are tables where people may read whatever \ninterested them in peace. The ceiling has a great mosaic on it and \ngives off enchanted light.[2;37;0m[2;37;0m [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_5.c";
  RoomNum = 5;
  BaseFilename = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_";
  Entrance = "/players/mythos/aroom/village.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_4", "east" });
}
