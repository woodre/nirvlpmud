#include "/players/maledicta/ansi.h"
#define WAR "/players/maledicta/cont/war/war"

inherit "room/room";



reset(arg) {
if(WAR->query_king()){  
  move_object(clone_object("/players/maledicta/cont/mobs/goblin_king.c"), this_object());
  }
  if(arg) return;
set_light(1);
short_desc = YEL+"The Goblin Command Tent"+NORM;
long_desc =
"  You stand within the smelly confines of the Goblin command\n"+
"tent.  A large skin map of Nirvana hangs from a wooden rack\n"+
"of crude wood.  A lice-ridden cot sits in one corner next to\n"+
"a stand with a burned out candle on it. The only exit is a\n"+
"flap leading out.\n";

items = ({
  "map",
  "A large map of Nirvana. It is mostly blank and seems a work in progress",
  "rack",
  "A crude wooden rack that holds the map",
  "cot",
  "A wood and straw cot that sits in the corner",
  "candle",
  "A used up candle that sits on a stand",
  "stand",
  "A crude wooden stand",
  "flap",
  "The only exit leading out of the tent",
});

dest_dir = ({
  "/players/reflex/realms/coastline/main.c","out",
});
}
