#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Carnage's Palace[2;37;0m[2;37;0m";
  Short2 = ": [1;31mEntry Way[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is the entry way to Carnage's Palace.  Exits lead off in almost[2;37;0m[2;37;0m\n[2;37;0mevery direction.  There are a few sofa's scattered about the room,[2;37;0m[2;37;0m\n[2;37;0mleft here for the receiving of visitors.[2;37;0m[2;37;0m[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_";
  Entrance = "/players/molasar/PLAINS/plain8.c";
  get_master();
  items = ({ "sofa", "The sofa is large, with room for three, and made of leather.[2;37;0m[2;37;0m",
"sofas", "The sofas are large, with room for three, and made of leather.[2;37;0m[2;37;0m" });
  dest_dir = ({ "/players/molasar/PLAINS/plain8.c", "out",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_1", "room1",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_2", "room2",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_3", "room3",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_4", "room4",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_5", "room5",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_6", "room6",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_7", "room7",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_8", "room8",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_49_9", "room9" });
}
