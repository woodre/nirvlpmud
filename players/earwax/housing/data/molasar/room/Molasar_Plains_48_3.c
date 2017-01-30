#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Gogeta's House[2;37;0m[2;37;0m";
  Short2 = "";
  long_desc = "[2;37;0mOn the wall on your right you see a sign and figure its a Uchiha \nsign, and as you look on your other side you see many eyes that seem \nto pierce you every movement, and as you look around more the entire \nroom is made of a thick crystal, and you see shuriken, daggers, and \nswords on the wall. As you walk around the room you hear the door shut \nand the lights turn off, all you can see is the redness of two eyes \nlooking at you as if piercing your soul and you very existence, as you \ntry to move you feel a glowing hand piercing through your stomach and \nfall to the grounds, all you hear now is the sadistic laughing of \nSasuke Uchiha, of The Legendary Clan of Konoha (The Village Hidden In \nthe Leavs). [2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_3.c";
  RoomNum = 3;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_";
  Entrance = "/players/molasar/PLAINS/plain3.c";
  get_master();
  items = ({  });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_48_0.c", "back" });
}
