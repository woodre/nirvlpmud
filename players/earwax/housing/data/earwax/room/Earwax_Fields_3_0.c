#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Fenris's Palace[2;37;0m[2;37;0m";
  Short2 = ": <[1;37mEntry[0m>[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/earwax/room/Earwax_Fields_3_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/earwax/room/Earwax_Fields_3_";
  Entrance = "/players/earwax/area/fields/room/fields9.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/area/fields/room/fields9.c", "out",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_3_3", "room3",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_3_4", "room4",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_3_5", "room5",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_3_6", "room6",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_3_8", "room8",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_3_9", "room9",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_3_10", "north",
"/players/earwax/housing/data/earwax/room/Earwax_Fields_3_1", "enter" });
}
