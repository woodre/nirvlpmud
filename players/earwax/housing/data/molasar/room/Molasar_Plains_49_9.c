#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Carnage's Palace[2;37;0m[2;37;0m";
  Short2 = ": [1;37mMaster Bathroom[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is the master bathroom.  The room is very large.  There[2;37;0m[2;37;0m\n[2;37;0mis a double sink on the west wall.  A very large tub with a[2;37;0m[2;37;0m\n[2;37;0mshower attachment on the south wall.  The floor is marble[2;37;0m[2;37;0m\n[2;37;0mtiles encrusted with gold.  The throne sits on the north wall,[2;37;0m[2;37;0m\n[2;37;0mwith what appears to be a few magazines sitting next to it.[2;37;0m[2;37;0m[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_9.c";
  RoomNum = 9;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_";
  Entrance = "/players/molasar/PLAINS/plain8.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_0.c", "back" });
}
