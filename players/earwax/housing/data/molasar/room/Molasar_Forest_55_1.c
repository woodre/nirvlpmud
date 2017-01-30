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
  long_desc = "[2;37;0mThe interior of the cabin is set with vaulted ceilings and a brick\n[2;37;0mfireplace. There is a gentle fire burning within the hearth, and a\n[2;37;0msoft, fur rug has been spread out on the wooden floor. The northern\n[2;37;0mwall has large picture windows open to the picturesque clearing and\n[2;37;0mforest beyond the cabin, and a door leads out to the balcony. A\n[2;37;0mplush, leather sofa sits in the center of the room, facing the fire\n[2;37;0mand decorated with pillows and a knitted throw. There are hallways\n[2;37;0mto both the east and west.[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_1.c";
  RoomNum = 1;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_";
  Entrance = "/players/molasar/FOREST/Eforest7.c";
  get_master();
  items = ({ "roses", "A fresh collection of dark red roses perfectly arranged in the vase.",
"vase", "An unusual material, the black vase seems black. Upon closer inspection, shadows swirl just beneath the glass. ",
"fire", "A gently burning fire.",
"fireplace", "The white brick fireplace stretches from the floor to the ceiling and takes up most of the eastern wall. ",
"rug", "A large fur rug from a creature that had a beautiful white coat streaked with black. ",
"tiles", "The ceramic tiles seem to be flecked and swirled with gold. They are warm to the touch. ",
"mantle", "A low mantle, just a foot from the ground. It is made of black tile and is well polished. ",
"balcony", "A balcony that stretches across the length of the room and extends over the ground for several feet. It is fenced. ",
"clearing", "The clearing holds lush, green grasses and a beautiful variety of wildflowers ranging in color from bright yellow to a vibrant red. ",
"forest", "The beautiful forest beyond the clearing is home to many elves. The trees are old and full of thick evergreen branches. ",
"couch", "The couch appears plush and very comfortable." });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_0", "entry",
"/players/earwax/housing/data/molasar/room/Molasar_Forest_55_2", "east",
"/players/earwax/housing/data/molasar/room/Molasar_Forest_55_3", "balcony",
"/players/earwax/housing/data/molasar/room/Molasar_Forest_55_4", "west" });
}
