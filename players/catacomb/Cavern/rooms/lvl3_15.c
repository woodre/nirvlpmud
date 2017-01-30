#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  A large opening lies to the east.  The torches stop before entering\n"+
"into the large cavern.  A savage wind blows through the passageway into\n"+
"the cavern.  The rocks end before entering into the opening.  Complete\n"+
"darkness is all that can be seen within.\n");

items = ({
  "opening",
  "A large cavern opens up to the east", 
  "cavern",
  "A large cavern opens up to the east", 
  "rocks",
  "The shadows leap around the rocks",
  "rock",
  "A rock has some sort of scribbling on it",
  "torches",
  "They are fastened to the wall securely",
  "torch",
  "The torch is securely fastened to the wall",
  "scribbling",
  "The scribbles read: Consume"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_14.c","north",
  "/players/catacomb/Cavern/rooms/lvl3_16.c","east" 
});
}

