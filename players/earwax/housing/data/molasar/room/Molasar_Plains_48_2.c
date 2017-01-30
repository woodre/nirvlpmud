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
  long_desc = "[2;37;0mThis room is decrated with a blood red design and as you look around \nit has a sand like title lining and as you look in the corners you see \nsand in each, you try to guess whats it for but as you are thinking, \nyou feel your body being consumed by sand, you panic,struggle,but as \nyou try you here someone in the corner of the room appear from the \nshadows and as you see him he says \"Exploding Sand Funeral\" and you \nfeel your body crushed and YOU DIE! [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_2.c";
  RoomNum = 2;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_";
  Entrance = "/players/molasar/PLAINS/plain3.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_0.c", "back" });
}
