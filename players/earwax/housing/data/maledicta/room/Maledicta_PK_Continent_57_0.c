#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sephiroth's Palace[2;37;0m[2;37;0m";
  Short2 = ": )*(THE HIGH RIDE)*([2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_";
  Entrance = "/players/maledicta/cont/rooms/599.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/maledicta/cont/rooms/599.c", "out",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_1", "room1",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_2", "room2",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_3", "room3",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_4", "room4",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_5", "room5",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_6", "room6",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_7", "room7",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_8", "room8",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_9", "room9",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_57_1", "hideout" });
}
