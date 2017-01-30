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
  long_desc = "[2;37;0mAs you look through the room you see the room is painted in a blue \nbackground with ocean settings, you see dolphins setting on the \nfurniture and guess this is either his girlfriend's room or some \nfreakshow of a house. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_";
  Entrance = "/players/molasar/PLAINS/plain3.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_0.c", "back" });
}
