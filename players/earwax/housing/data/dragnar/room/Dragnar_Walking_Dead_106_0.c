#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Hugh's Palace[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_";
  Entrance = "/players/dragnar/WalkingDead/rooms/t6.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/dragnar/WalkingDead/rooms/t6.c", "out",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_1.c", "room1",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_2.c", "room2",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_3.c", "room3",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_4.c", "room4",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_5.c", "room5",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_6.c", "room6",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_7.c", "room7",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_8.c", "room8",
"/players/earwax/housing/data/dragnar/room/Dragnar_Walking_Dead_106_9.c", "room9" });
}
