#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Carnage's Palace[2;37;0m[2;37;0m";
  Short2 = ": [1;30mViewing Room[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is a large room that is specifically for watching movies.  There[2;37;0m[2;37;0m\n[2;37;0mis a large screen on one wall, with a projector on the other.[2;37;0m[2;37;0m\n[2;37;0mThere are 4 rows of large plush recliners, to help make the viewing[2;37;0m[2;37;0m\n[2;37;0mexperience more pleasureable.  On the other side of the room,[2;37;0m[2;37;0m\n[2;37;0mthere is a small stand where you can get popcorn and drinks.[2;37;0m[2;37;0m[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_7.c";
  RoomNum = 7;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_";
  Entrance = "/players/molasar/PLAINS/plain8.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_0.c", "back" });
}
