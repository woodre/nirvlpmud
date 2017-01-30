#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Carnage's Palace[2;37;0m[2;37;0m";
  Short2 = ": [1;35mGuest Bedroom[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is a large guest bedroom.  There is a queen size bed in[2;37;0m[2;37;0m\n[2;37;0mthe middle of the room, with a canopy above it.  There are[2;37;0m[2;37;0m\n[2;37;0mseveral fluffy pillows covering the bed.  A television[2;37;0m[2;37;0m\n[2;37;0mis on the wall opposite of the bed.[2;37;0m[2;37;0m[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_8.c";
  RoomNum = 8;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_";
  Entrance = "/players/molasar/PLAINS/plain8.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_0.c", "back" });
}
