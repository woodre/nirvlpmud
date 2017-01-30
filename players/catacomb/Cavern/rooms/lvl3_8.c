#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  A large bridge can be seen overhead, but nothing can be seen on top\n"+
"of it.  The shadows created underneath the bridge seem to leap out from\n"+
"the darkness.  The smell of battle invades the underpass, but nothing \n"+
"can be seen anywhere but darkness.  The path leads to the east and to the\n"+
"southwest.\n");

items = ({
  "bridge",
  "A stone bridge stretches across the area overhead", 
  "shadows",
  "The shadows seem to have eyes for watching all intruders into the area", 
  "shadow",
  "The shadows seem to have eyes for watching all intruders into the area",
  "darkness",
  "The darkness pervades the area, making all who pass uneasy",
  "path",
  "The path leads to the east and southwest"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_7.c","southwest",
  "/players/catacomb/Cavern/rooms/lvl3_9.c","east", 
  });
  }

