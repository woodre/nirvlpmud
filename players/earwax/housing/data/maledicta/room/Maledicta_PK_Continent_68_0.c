#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Artos's Mansion[2;37;0m[2;37;0m";
  Short2 = ": Foyer[2;37;0m[2;37;0m";
  long_desc = "Cleared.  Sorry :(";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_";
  Entrance = "/players/maledicta/cont/rooms/881.c";
  get_master();
  items = ({ "paintings", "Random abstract arts that show you the anger of the artist.  They \
give you chills and you feel the need to look away. " });
  dest_dir = ({ "/players/maledicta/cont/rooms/881.c", "out",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_1", "room1",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_2", "room2",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_3", "room3",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_4", "room4",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_5", "room5",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_6", "room6" });
}
