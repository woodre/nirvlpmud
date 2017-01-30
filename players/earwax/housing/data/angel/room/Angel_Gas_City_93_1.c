#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Joab's House[2;37;0m[2;37;0m";
  Short2 = ": Lover's Den[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m  This rooms is lavishly put together and in tones\n[2;37;0mthat are obviously meant to sooth and relax. The \n[2;37;0mThe entire home is more of a retreat than a\n[2;37;0mprivate home for the Lord.[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_";
  Entrance = "/players/angel/area/colony/land/land_09.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_0.c", "back" });
}
