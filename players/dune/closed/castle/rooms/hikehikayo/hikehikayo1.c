inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if (!arg)
  {
    set_light(0);
    short_desc=("The Ruins of Hikehikayo");
    long_desc=
"     The Ruins of Hikehikayo lie scattered all around you.\n"+
"Very little of the ancient city remains.  The forces of the\n"+
"earth have mangled and twisted the city to pieces.  Most\n"+
"passageways have been cut off.\n";

    dest_dir=({
CASTLEROOM+"/hikehikayo2.c","south",
    });

    items=({
"entrance","     The entrance is like a hole in the hill",
"ceiling", "     The ceiling is smooth, almost man-made",
"walls",   "     The walls have nicks on them, as if smoothed by man",
"floor",   "     The floor looks well trampled on",
    });
  }
}
