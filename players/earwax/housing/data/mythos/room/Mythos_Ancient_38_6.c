#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Sin's Palace[2;37;0m[2;37;0m";
  Short2 = ": [1;31mDu[0m[31mngeon [1;31mCh[0m[31mambers[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m[1;31mThis room was obviously meant to torture, or perhaps please. \nScattered everywhere are machines used to torture people. Along the \nwalls you see various restrictive devices as well as whips and chains. \nThe scent of dried blood fills the nostrils as most of anything in \nhere has spatters of it including the machines. There is also a \ndripping of water, making the room humid among the heat.[2;37;0m[2;37;0m [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_6.c";
  RoomNum = 6;
  BaseFilename = "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_";
  Entrance = "/players/mythos/aroom/village.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/mythos/room/Mythos_Ancient_38_4", "north" });
}
