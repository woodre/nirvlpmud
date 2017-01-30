#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Larisa's House[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "[2;37;0mThe entry is a small room with pale marble walls and ceramic tile \nfloors. A table stands against the wall and holds several silver \ncandlesticks. The candles flicker gently, casting a warm glow \nthroughout the room. There is a warm glow of light coming from further \nwithin and a door leads back out to the forest. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_";
  Entrance = "/players/molasar/FOREST/Eforest7.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/molasar/FOREST/Eforest7.c", "out",
"/players/earwax/housing/data/molasar/room/Molasar_Forest_55_1", "north",
"/players/earwax/housing/data/molasar/room/Molasar_Forest_55_5.c", "NEWROOM" });
}
