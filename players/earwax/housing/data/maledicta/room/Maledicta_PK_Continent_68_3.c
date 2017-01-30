#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 0;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Artos's Mansion[2;37;0m[2;37;0m";
  Short2 = ": Solarium[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis room is almost like a porch with 2 walls of glass to the outside \nworld.  Unlike most solariums though, this one has glass that is a \nvery dark bronze and only lets enough rays through to keep the plants \ninside alive.  The plants growing inside are also those that like less \nlight, mushrooms, some ferns, and even some moss growing on rocks \naround a little pond that is installed in the middle of the room. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_3.c";
  RoomNum = 3;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_";
  Entrance = "/players/maledicta/cont/rooms/881.c";
  get_master();
  items = ({ "pond", "The pond is about 5 foot in diameter.  A smaller pond sits behind it 
elevated slightly and between them a small waterfall cascades nonstop. ",
"plants", "The plants seem to be very happy in their dark little world.  They 
have grown large despite the lack of sun. " });
  dest_dir = ({ "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_0", "back" });
}
