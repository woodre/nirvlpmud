#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Artos's Mansion[2;37;0m[2;37;0m";
  Short2 = ": Basement[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThe basement is dark with stone walls.  In the back corner is what \nlooks like a holding cell in a police station.  Next to the cell is a \ntable with some tools of torture.  Other than that the room is empty, \nbut you think if rooms could talk this one would have horrible stories \nto tell. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_4.c";
  RoomNum = 4;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_";
  Entrance = "/players/maledicta/cont/rooms/881.c";
  get_master();
  items = ({ "cell", "Unlike a police cell the bars on this one are a lot more heavy duty.  
This is probably because those who appose Artos are stronger than your 
average thugs.  Good seems to have a special power that gets them out 
of troubled situations, but you don't think it will save them from 
Artos or his cell. ",
"tools", "You glance at the tools and then look away because the first thing 
you notice is that none of them have been cleaned and the table is 
covered in blood.  Where was the bathroom again? " });
  dest_dir = ({ "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_0.c", "back" });
}
