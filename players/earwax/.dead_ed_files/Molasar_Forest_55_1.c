#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Larisa's House[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "[2;37;0mA warm fire is burning quietly in the white brick fireplace set \nagainst the eastern wall. There is a soft, fur rug spread out on the \nceramic tiles in front of the fireplace, and some logs stacked beside \nthe low mantle. The southern wall holds a balcony with a view of a \nsmall clearing and the forest that surrounds the home. Two chairs and \na small table have been placed on the balcony. The western portion of \nthe room holds a cream colored leather couch with an endtable ";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_";
  Entrance = "/players/molasar/FOREST/Eforest7.c";
  get_master();
  items = ({ "roses", "A fresh collection of dark red roses perfectly arranged in the vase.",
"vase", "An unusual material, the black vase seems black. Upon closer \
inspection, shadows swirl just beneath the glass. ",
"fire", "A gently burning fire.",
"fireplace", "The white brick fireplace stretches from the floor to the ceiling and 
takes up most of the eastern wall. ",
"rug", "A large fur rug from a creature that had a beautiful white coat 
streaked with black. ",
"tiles", "The ceramic tiles seem to be flecked and swirled with gold. They are 
warm to the touch. ",
"mantle", "A low mantle, just a foot from the ground. It is made of black tile 
and is well polished. ",
"balcony", "A balcony that stretches across the length of the room and extends 
over the ground for several feet. It is fenced. ",
"clearing", "The clearing holds lush, green grasses and a beautiful variety of 
wildflowers ranging in color from bright yellow to a vibrant red. ",
"forest", "The beautiful forest beyond the clearing is home to many elves. The 
trees are old and full of thick evergreen branches. ",
"couch", "The couch appears plush and very comfortable." });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_0", "entry" });
}
