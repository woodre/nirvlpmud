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
"  A deafening silence overcomes all who enter into this area.  Torches\n"+
"line the wall but no sound comes from them.  The silence is very creepy,\n"+
"almost like the calm before the storm.  The ground is clear of everything\n"+
"except for the marks of dried blood on the ground.  The walls show signs of\n"+
"a recent battle here with sword slices carved into them.\n");

items = ({
  "ground",
  "Dried blood covers the floor", 
  "torches",
  "Torches line the sides of the path", 
  "torch",
  "A light source securely fastened to the sides of the path",
  "sides",
  "Torches and sword marks line the sides of the cavern",
  "side",
  "Torches and sword marks line the sides of the path",
  "wall",
  "The walls are covered in marks from a recent battle",
  "walls",
  "The walls are covered in marks from a recent battle",
  "marks",
  "Chips embedded in the walls from the many battles taking place in the cave",
  "mark",
  "A very deep cut in the side of the wall"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_6.c","west",
  "/players/catacomb/Cavern/rooms/lvl3_8.c","northeast", 
  });
  }

