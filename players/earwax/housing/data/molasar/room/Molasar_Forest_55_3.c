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
  long_desc = "[2;37;0mThe balcony overlooks the peaceful clearing dotted by patches of\n[2;37;0mvibrant wildflowers. The forest beyond begins abruptly at the\n[2;37;0medge of the clearing, with thick underbrush and earthy scented\n[2;37;0mevergreens. Two wooden chairs sit beside a carved oak table with\n[2;37;0ma dark finish, and a candle is lit inside a small, ceramic jar\n[2;37;0mon the center of the table. Several baskets lined in moss hang\n[2;37;0mfrom the eaves with beautiful, brightly colored flowers cascading\n[2;37;0mdownward. A door to the south leads back within the cabin.[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_3.c";
  RoomNum = 3;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_";
  Entrance = "/players/molasar/FOREST/Eforest7.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Forest_55_1", "south" });
}
