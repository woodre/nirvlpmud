#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Oz's Palace[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "This room hasn't been described yet.\nType [1;37mhcommands[2;37;0m[2;37;0m to see available commands.\n";
  FileName = "/players/earwax/housing/data/snow/room/Snow_Mountain_84_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/snow/room/Snow_Mountain_84_";
  Entrance = "/players/snow/ROOMS/summit.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/snow/ROOMS/summit.c", "out",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_1.c", "room1",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_2.c", "room2",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_3.c", "room3",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_4.c", "room4",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_5.c", "room5",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_6.c", "room6",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_7.c", "room7",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_8.c", "room8",
"/players/earwax/housing/data/snow/room/Snow_Mountain_84_9.c", "room9" });
}
