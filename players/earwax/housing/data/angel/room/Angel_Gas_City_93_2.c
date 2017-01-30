#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Joab's House[2;37;0m[2;37;0m";
  Short2 = ": Library[2;37;0m[2;37;0m";
  long_desc = "[2;37;0m   This large open room houses some of the greatest works in\n[2;37;0mthe Known Lands, both fictional and non-fictional. The walls\n[2;37;0mare covered with dark Mahogany wood shelves filled with books.\n[2;37;0mIt is a readers dream.[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_2.c";
  RoomNum = 2;
  BaseFilename = "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_";
  Entrance = "/players/angel/area/colony/land/land_09.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/angel/room/Angel_Gas_City_93_0.c", "back" });
}
