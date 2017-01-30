#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The torches cast several shadows on the rocks.  Each of the shadows\n"+
"seem to leap out and attack the people who cross their path.  The \n"+
"shadows seem to have eyes themselves.  With every passing moment the \n"+
"crackling torch grow steadily smaller. \n");

items = ({
  "shadows",
  "The shadows seem to jump out at you", 
  "shadow",
  "The shadow seems to watch your every move", 
  "rocks",
  "The rocks are covered in blood and shadows",
  "rock",
  "The rock juts out making it easy to catch a limb on the sharp point",
  "torches",
  "They are fastened to the wall securely",
  "torch",
  "The torch is securely fastened to the wall"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_13.c","northwest",
  "/players/catacomb/Cavern/rooms/lvl3_15.c","south" 
  });
  }

