#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object cartman;
object kitty;
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Cartman's House";
long_desc =
"  The entire house is filled with the aroma of food.  A large\n"+
"plush couch is facing the TV.  Several plates and a glass are\n"+  
"sitting on an end table next to the couch.  A small cat dish is\n"+
"in the corner of the room.\n";

items = ({
  "couch",
  "This is a very large couch with soft cushions to sit on", 
  "plates",
  "They all have crumbs on them from the food that once was on them", 
  "tv",
  "The TV is tuned into the Terrance and Phillip show of course",
  "glass",
  "It is tall and still has a little bit of milk in it",
  "table",
  "It looks like an antique, there are some intricate carvings on it",
  "carvings",
  "It looks like a garden scene with flowers and bushes",
  "dish",
  "The dish is empty and the words 'Mr. Kitty' is written on it",   
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r6.c","out",
  });
  cartman = clone_object("/players/fred/SP/Mon/cartman.c");
  kitty = clone_object("/players/fred/SP/Mon/mkitty.c");
  move_object(kitty, this_object());
  move_object(cartman, this_object());
}
