#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Artos's Mansion[2;37;0m[2;37;0m";
  Short2 = ": Sitting Room[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis room unlike all the others has a window.  The large picture \nwindow has dark curtains to keep out the light, but allows for light \nwhen friendly visitors need the light (not all can be as cool as those \nwho live off the dark).  There is a large sofa and a couple of padded \nchairs set up around a long coffee table.  The walls are covered with \nshelves holding many books for researh and pleasure reading. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_";
  Entrance = "/players/maledicta/cont/rooms/881.c";
  get_master();
  items = ({ "sofa", "The sofa is almost round with all the padding.  It looks as if you 
would sink into it when you sat on it.  Something like floating on a 
cloud. ",
"chairs", "The chairs look almost as comfy as the sofa, but with the arm rests 
being closer together there isn't as much room for so much fluff. ",
"window", "You don't see anything beyond the curtains, but you are sure that if 
you really needed light that the curtains could be opened and a little 
could filter in for you. " });
  dest_dir = ({ "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_0.c", "back" });
}
