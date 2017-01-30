#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Gogeta's House[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "[2;37;0mWelcome \n[2;37;0mThis is the house of Gogeta,please watch out for the weapons laying \non the ground. You see servants bustling around the house trying to \ncomplete work and as you see them they look happy. \n[2;37;0mYou see picture of a man and a woman on the wall that look older then \ngogeta and think that is his mother and father, as you look on the \nother side of the wall you see pictures of him and his girlfriend. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_";
  Entrance = "/players/molasar/PLAINS/plain3.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/molasar/PLAINS/plain3.c", "out",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_48_1.c", "room1",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_48_2.c", "room2",
"/players/earwax/housing/data/molasar/room/Molasar_Plains_48_3.c", "room3" });
}
