#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Artos's Mansion[2;37;0m[2;37;0m";
  Short2 = ": Kitchen[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThe kitchen almost feels like the darkest room you've been in and you \nwonder how anyone can cook without light.  Then you realize as \nsomething scurries past your feet that the chef is not human.  A flame \nlights on the stove and you see a demon standing next to the stove \nmixing something.  You glance around the room now that you can see \nwith the small light and you notice tons of counter space piled high \nwith all kinds of food to be cooked and some that is done.  Apparently \ndemons know how to cook quite well, and with demons as servants, Artos \nmust truly be as evil as you thought. [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_2.c";
  RoomNum = 2;
  BaseFilename = "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_";
  Entrance = "/players/maledicta/cont/rooms/881.c";
  get_master();
  items = ({ "food", "So many types of food.  Raw foods one one counter and cooked on 
another.  There are meats and vegetables, and there is a counter on 
the far wall that has a couple of fruit deserts on it. ",
"demon", "A small very creepy looking creature.  He has long fuzzy ears and 
angry red eyes that glow with the light from the stove.  You see his 
hands with long sharp claws and you imagine he has no need for knives. " });
  dest_dir = ({ "/players/earwax/housing/data/maledicta/room/Maledicta_PK_Continent_68_0.c", "back" });
}
