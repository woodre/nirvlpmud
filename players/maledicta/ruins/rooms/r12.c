#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   You find yourself in a large dark tunnel. The walls here are scorched\n"+
"and melted, parts of it pooled and lumped onto the floor.  A hole in the\n"+
"ceiling leads up to the ruins. The tunnel continues to the east.\n";

items = ({
  "walls",
  "They look to have been shaped by intense heat, as does\n"+
  "the entire room",
  "hole",
  "A hole that leads up to the ruins",
  "floor",
  "It is smooth to the touch, and seems to have been formed by melting",
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r11.c","up",
  "/players/maledicta/ruins/rooms/r13.c","east",
});

}
