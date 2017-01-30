#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Lungbutter's Hut[2;37;0m[2;37;0m";
  Short2 = ": Test[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is a test[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/jaraxle/room/Jaraxle_Third_Earth_79_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/jaraxle/room/Jaraxle_Third_Earth_79_";
  Entrance = "/players/jaraxle/3rd/warrior/rooms/land_4_sale/land1.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/jaraxle/3rd/warrior/rooms/land_4_sale/land1.c", "out",
"/players/earwax/housing/data/jaraxle/room/Jaraxle_Third_Earth_79_1.c", "room1" });
}
