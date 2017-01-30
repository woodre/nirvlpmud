#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Upus's Palace[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "[2;37;0mThis is the entry hall to Upus' Palace.  This room is long, so long \nyou can barely make out the end, with numerous rooms leading off it.  \nThe walls are also covered in pictures of Upus' favourite places that \nhe has visited.[2;37;0m[2;37;0m [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_";
  Entrance = "/players/bastion/isle/rocky2.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/bastion/isle/rocky2.c", "out",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_1.c", "room1",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_2.c", "room2",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_3.c", "room3",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_4.c", "room4",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_5.c", "room5",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_6.c", "room6",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_7.c", "room7",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_8.c", "room8",
"/players/earwax/housing/data/bastion/room/Bastion_Rocky_Shore_82_9.c", "room9" });
}
