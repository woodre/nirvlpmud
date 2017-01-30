#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Krash's Mansion[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/angel/room/Angel_Gas_City_87_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/angel/room/Angel_Gas_City_87_";
  Entrance = "/players/angel/area/colony/land/land_12.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/angel/area/colony/land/land_12.c", "out",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_87_1.c", "room1",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_87_2.c", "room2",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_87_3.c", "room3",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_87_4.c", "room4",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_87_5.c", "room5",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_87_6.c", "room6" });
}
