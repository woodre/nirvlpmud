#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Soft Beach";
long_desc =
"  This is the tree line on the edge of the Soft Beach.\n"+  
"The ground here is sandy like that on the beach, but the\n"+
"sand here is rougher and harder.  Little patches of grass\n"+
"grow here and there and small lizards move through them.\n"+ 
"To the east you can hear the waves crashing on the beach\n"+
"and the call of the seagulls.\n";

add_listen("main", "You hear the trees ruffling in the breeze and small birds singing within the trees.");
add_smell("main", "You smell the fresh oxygen provided by the large trees.");


items = ({
  "sand",
  "The sand here is mixed with dirt and there are very few seashells mixed in", 
  "grass",
  "Small patches of long beach grass growing every couple of feet or so",
  "tree",
  "A large tree with its heavy branches waving in the wind",
  "trees",
  "Large trees with their heavy branches waving in the wind", 
    });

dest_dir = ({
  "/players/jamila/beach/beach6.c","north",
  "/players/jamila/beach/beach8.c","south",
  "/players/jamila/beach/beach4.c","east",
  });

}
