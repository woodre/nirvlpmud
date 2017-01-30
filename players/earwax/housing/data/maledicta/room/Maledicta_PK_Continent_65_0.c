#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sephiroth's Trailer[2;37;0m[2;37;0m";
  Short2 = ": Sephiroth's Shack-O-Hoes[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is the main entryway in the Shack-O-Hoes.\n[2;37;0mThere are hoes everywhere! Pick one, have fun![2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_65_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_65_";
  Entrance = "/players/maledicta/cont/rooms/780.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/maledicta/cont/rooms/780.c", "out",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_65_1.c", "room1",
"/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_65_2.c", "room2" });
}
