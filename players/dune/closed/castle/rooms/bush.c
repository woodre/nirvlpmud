inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if (!present("corpse"))
    move_object(clone_object(CASTLEOBJECT+"/corpse.c"), this_object());

  if(!arg)
  {
    short_desc="Bushes";
    long_desc=
"     Thicket bushes completely surround you. The tracks you followed\n"+
"here have led straight into these nasty bushes. No apparent path or\n"+
"reason can explain the sudden wandering track, but, perhaps there is\n"+
"a reason. The tracks lead back to the way you came. It looks like there\n"+
"was a little action that took place here, and a pool of blood lies on\n"+
"the ground.\n";

    dest_dir=({
CASTLEROOM+"/many_tracks.c","east"  ,
    });

    items=({
"blood", "     The blood must be from something killed recently",
"tracks","     The few tracks here suggest a quick fight",
"pool",  "     The blood is soaked into the ground",
"bushes","     The bushes have nasty thorns",
    });
  }
}
