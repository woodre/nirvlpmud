#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Finn's House[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/earwax/room/Earwax_Fields_6_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/earwax/room/Earwax_Fields_6_";
  Entrance = "/players/earwax/area/fields/room/fields2.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/area/fields/room/fields2.c", "out",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_6_1.c", "room1",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_6_2.c", "room2",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_6_3.c", "room3",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_6_4.c", "NEWROOM" });
}
