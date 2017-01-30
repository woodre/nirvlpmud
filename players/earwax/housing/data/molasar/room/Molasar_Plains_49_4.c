#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Carnage's Palace[2;37;0m[2;37;0m";
  Short2 = ": [36mDining Roomn[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is the fine dining area of Carnage.  There is a large round[2;37;0m[2;37;0m\n[2;37;0mtable in the middle of the room.  8 chairs circle the table.[2;37;0m[2;37;0m\n[2;37;0mThere is a smaller serving table off to the west side of the room.[2;37;0m[2;37;0m[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_4.c";
  RoomNum = 4;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_";
  Entrance = "/players/molasar/PLAINS/plain8.c";
  get_master();
  items = ({ "table", "A large round table made for eating, this one appears to be from the \
Camelot time.[2;37;0m[2;37;0m ",
"serving table", "A small table used to place the food on while serving people.[2;37;0m[2;37;0m",
"chairs", "8 wooden chairs that circle the table.[2;37;0m[2;37;0m",
"chair", "A wooden chair that sits around the table.[2;37;0m[2;37;0m" });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_0.c", "back" });
}
