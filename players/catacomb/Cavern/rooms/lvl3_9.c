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
"  A large stone bridge can be seen up and to the west.  A small spiral\n"+
"staircase leads up to the bridge to the south.  The masonary work on the\n"+
"stairs is of excellent craftsmanship.  There is no dust on these steps\n"+
"indicating that it is used very often.  The underpass to the bridge is \n"+
"located to west.\n");

items = ({
  "bridge",
  "A stone bridge can be seen overhead", 
  "staircase",
  "The staircase leads up to the bridge", 
  "work",
  "The craftsmanship is excellent",
  "steps",
  "The stonework of the steps is excellent",
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_8.c","west",
  "/players/catacomb/Cavern/rooms/lvl3_10.c","stairs", 
  });
  }

