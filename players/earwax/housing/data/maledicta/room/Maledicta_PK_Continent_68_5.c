#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Artos's Mansion[2;37;0m[2;37;0m";
  Short2 = ": Master Bedroom[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is a large dark room with the walls decorated in the same manner \nas the foyer.  In the far corner a fireplace is lit, but it glows with \na dark blue flame, giving off just enough light for you to be able to \nstumble through the room and see the glowing eyes of whoever is with \nyou.  There is a large bed with a dark canopy that can be closed to \nmake sure not even the slightest bit of light seeps into the serenity \nof the bed.  Next to the bed are small night stands, this is where \nsmall concealed weapons are placed when sleeping in the bed.  On the \nwall to the right of you is a large wardrobe that matches the bed.  \nLooking to the floor you notice the carpet is black with burgundy \nmixed through it.  It almost looks as if blood was spilled to decorate \nthe carpet. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_5.c";
  RoomNum = 5;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_";
  Entrance = "/players/maledicta/cont/rooms/881.c";
  get_master();
  items = ({ "bed", "The large wood bed is surrounded by a dark thick canopy.  Inside the 
canopy you notice the bed is made with soft blankets that seem to draw 
you in.  A large stack of fluffy pillows is at the head of the bed.  
The bed isn't made all the way and you notice the sheets glisten like 
silk.  It looks way too comfortable to be the bed of the hardened 
killer you know sleeps here. ",
"flame", "A large blue flame, it looks cold to the touch but you know it is 
really very warm.  As it flickers it is almost as if it is drawing you 
in. " });
  dest_dir = ({ "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_0", "back" });
}
