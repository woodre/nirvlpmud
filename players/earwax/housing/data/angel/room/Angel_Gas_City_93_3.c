#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Joab's House[2;37;0m[2;37;0m";
  Short2 = ": Grand Banquet Hall[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m  You stand within a beautiful banquet hall.  Long tables extend\n[2;37;0mthe length of the room, each covered in fine cloth and candles.\n[2;37;0mA stone fireplace is located on the north wall, the fires provide\n[2;37;0ma nice warmth to the room. There is an unlimited amount of food\n[2;37;0mbeing served this day.[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_3.c";
  RoomNum = 3;
  BaseFilename = "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_";
  Entrance = "/players/angel/area/colony/land/land_09.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_0.c", "back" });
}
