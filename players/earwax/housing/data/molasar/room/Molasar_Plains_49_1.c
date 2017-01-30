#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Carnage's Palace[2;37;0m[2;37;0m";
  Short2 = ": [1;37mHot Tub[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is the room that has a very large hot tub in it. There[2;37;0m[2;37;0m\n[2;37;0mis a small cooling off area on the east side of the room.[2;37;0m[2;37;0m\n[2;37;0mThe flooring around the tub, is nice hard wood.  There are[2;37;0m[2;37;0m\n[2;37;0ma few deck chairs scattered around the room.[2;37;0m[2;37;0m[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_";
  Entrance = "/players/molasar/PLAINS/plain8.c";
  get_master();
  items = ({ "tub", "A large hot tub, that appears to be able to hold 15 people.[2;37;0m[2;37;0m",
"hot tub", "A large hot tub, that appears to be able to hold 15 people.[2;37;0m[2;37;0m",
"water", "The water in the tub is steaming and bubbling, and looking very \
inviting.[2;37;0m[2;37;0m ",
"hard wood", " The hard wood floor is very shiny with a deep oak stain.[2;37;0m[2;37;0m",
"floor", " The hard wood floor is very shiny with a deep oak stain.[2;37;0m[2;37;0m",
"hard wood floor", " The hard wood floor is very shiny with a deep oak stain.[2;37;0m[2;37;0m",
"chair", "A plastic deck chair that looks very comfortable to sit in.[2;37;0m[2;37;0m",
"deck chair", "A plastic deck chair that looks very comfortable to sit in.[2;37;0m[2;37;0m",
"deck chairs", "A few plastic deck chairs that look very comfortable to sit in.[2;37;0m[2;37;0m",
"chairs", "A few plastic deck chairs that look very comfortable to sit in.[2;37;0m[2;37;0m",
"area", "A small area, where one can cool off, and towel off.[2;37;0m[2;37;0m",
"cooling area", "A small area, where one can cool off, and towel off.[2;37;0m[2;37;0m",
"cooling off area", "A small area, where one can cool off, and towel off.[2;37;0m[2;37;0m" });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_0.c", "back" });
}
