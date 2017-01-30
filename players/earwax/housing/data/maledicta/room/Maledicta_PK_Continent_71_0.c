#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
if(arg) return;

 Light = 1;
 LightToggle = (Light ? 1 : 0);
set_light(Light);
Short1 = "Land";
Short2 = "";
long_desc = "This room hasn't been described yet.\nType		hcommands to see available commands.\n";
FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_71_0.c";
RoomNum = 0;
 BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_71_";
 Entrance = "/players/maledicta/cont/rooms/111.c";
 get_master();
 items = ({ });
dest_dir = ({ "/players/maledicta/cont/rooms/111.c", "out" });
}
