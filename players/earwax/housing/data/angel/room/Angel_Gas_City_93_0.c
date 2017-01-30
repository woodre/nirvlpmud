#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Joab's House[2;37;0m[2;37;0m";
  Short2 = ": Living Room[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m  This room appears to be very open with high vaulted ceilings\n[2;37;0mwith oak tree timbers holding it up.  The floor is covered\n[2;37;0mwith larger 24 inch granite tiles. This room is simply awesome.\n[2;37;0mLuxury furniture cover the room and make it very inviting.\n[2;37;0mYou feel as if you will never leave this room.[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_0.c";
  RoomNum = 0;
  BaseFilename = "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_";
  Entrance = "/players/angel/area/colony/land/land_09.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/angel/area/colony/land/land_09.c", "out",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_93_1", "room1",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_93_2", "room2",
"/players/earwax/housing/data/angel/room/Angel_Gas_City_93_3", "room3" });
}
