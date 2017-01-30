#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The dampness of the cave gives off the smell of mildew.  The\n"+
  "stench is almost unbearable.  A combination of mold and decay,\n"+
  "only the strongest can stand to walk through the stench and not \n"+
  "succumb to it.\n"); 


  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_4.c","north",
    "/players/catacomb/Cavern/rooms/lvl2_6.c","west"
  });
if (!present("lizard"))
{
   move_object(clone_object("/players/catacomb/Cavern/mobs/lizard1.c"),
     this_object());
   move_object(clone_object("/players/catacomb/Cavern/mobs/lizard1.c"),
     this_object());
}
}
