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
"  The caverns form a path through the underearth lighted by torches.\n"+
"Every sound echoes hollowly throughout the area.  Sounds become\n"+
"amplified several times within the caverns of the Durkor.  Otherwise\n"+
"inaudible noises are now almost deafening.  The path leads off to the\n"+
"south and west.\n");

if(!present("warrior"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Duwarrior.c"),
	    this_object());

items = ({
  "path",
  "The path leads off to the south and west", 
  "torches",
  "Torches line the sides of the path", 
  "torch",
  "A light source securely fastened to the sides of the path",
  "sides",
  "Torches line the sides of the path",
  "side",
  "Torches line the sides of the path"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_1.c","west",
  "/players/catacomb/Cavern/rooms/lvl3_6.c","south", 
  });
  }

