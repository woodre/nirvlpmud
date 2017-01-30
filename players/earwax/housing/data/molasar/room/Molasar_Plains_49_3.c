#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Carnage's Palace[2;37;0m[2;37;0m";
  Short2 = ": [37mKitchen[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is a very large kitchen.  There are several stoves, two[2;37;0m[2;37;0m\n[2;37;0mrefridgerators, and a freezer.  There is a large countertop[2;37;0m[2;37;0m\n[2;37;0mthat extends through half the room, where most of the creation[2;37;0m[2;37;0m\n[2;37;0mof food begins.  It appears obvious that Carnage himself does[2;37;0m[2;37;0m\n[2;37;0mnot use this kitchen.[2;37;0m[2;37;0m[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_3.c";
  RoomNum = 3;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_";
  Entrance = "/players/molasar/PLAINS/plain8.c";
  get_master();
  items = ({ "refridgerator", "A large silver, side by side door refridgerator.[2;37;0m[2;37;0m",
"freezer", "Large silver freezer, one would surpmise it contains frozen beef, \
chicken and popsicles.[2;37;0m[2;37;0m ",
"countertop", "A smooth white marble countertop with several utensils.[2;37;0m[2;37;0m",
"fridge", "A large silver, side by side door refridgerator.[2;37;0m[2;37;0m",
"fridges", "Large silver, side by side door refridgerators.[2;37;0m[2;37;0m" });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_0.c", "back" });
}
