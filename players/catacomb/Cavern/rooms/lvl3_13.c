#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The tunnel's walls are lined with torches making it easy to see.  The \n"+
"rocks lining the cavern floor are very large and make traversing the \n"+
"tunnel somewhat difficult.  To the west a large opening can be seen\n"+
"along with a bridge.\n");

items = ({
  "bridge",
  "A bridge to the west", 
  "rocks",
  "Several rocks are scattered on the ground", 
  "ground",
  "The ground is covered in several sharp rocks",
  "floor",
  "The floor is covered in several sharp rocks",
  "walls",
  "The walls are lined with torches",
  "wall",
  "The wall is lined with torches",
  "torches",
  "They are fastened to the wall securely",
  "torch",
  "The torch is securely fastened to the wall"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_12.c","west",
  "/players/catacomb/Cavern/rooms/lvl3_14.c","southeast" 
  });
  }

