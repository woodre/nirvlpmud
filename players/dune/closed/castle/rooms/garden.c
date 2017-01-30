inherit "room/room";
#include "definitions.h"


reset(arg)
{

  if (!present("amerasu"))
    move_object(clone_object(CASTLEMONSTER+"/amerasu.c"), this_object());

  if(!arg)
  {
    set_light(1);
    short_desc=("Garden of the Sithi");
    long_desc=
"     This old organic labyrinth lies hidden in a patch of trees.\n"+
"A beautifully thatched roof of vines stretches over your head and\n"+
"gently tapers to the ground on thin overgrown pillars.\n";

    dest_dir=({
CASTLEROOM+"/green6.c","leave"  ,
    });

    items=({
"garden",    "     A labyrinth of plants hides this most secret garden",
"plants",    "     A zoo of multi-colored plants lie all about, some seem to glow",
"labyrinth", "     This beautiful labyrinth hides the secret garden of the Sithi",
"pillars",   "     The vine-covered pillars are covered with ancient runes",
"roof",      "     The roof is composed of intertwining vines and leaves",
    });
  }
}
