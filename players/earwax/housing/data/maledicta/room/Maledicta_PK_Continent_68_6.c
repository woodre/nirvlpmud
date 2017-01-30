#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Artos's Mansion[2;37;0m[2;37;0m";
  Short2 = ": Office[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mAnother dark room in the mansion. The floors are dark stained \nhardwood. In the center of the room is a large desk on a black fur \ncarpet. The desk is neat with a couple of photos and a laptop computer \non it. The back wall behind the desk is a huge weapons case. All kinds \nof deadly weapons are stored here and on the bottom shelves are some \npieces of armor.  Artos runs his business from this room, what did you \nexpect to find? [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_6.c";
  RoomNum = 6;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_";
  Entrance = "/players/maledicta/cont/rooms/881.c";
  get_master();
  items = ({ "photos", "There is one photo that draws your attention.  This is a photo of 
Artos with his lovely wife Teiannia.  The duo surrounded by an aura of 
evil gives you the chills, yet somehow its almost romantic to see a 
perfect couple, even in their special way. ",
"laptop", "This is a small, black laptop computer.  Artos uses it to store the 
scouting reports of every opposition player. " });
  dest_dir = ({ "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_0.c", "back" });
}
