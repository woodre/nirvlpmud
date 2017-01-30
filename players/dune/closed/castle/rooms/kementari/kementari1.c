inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("The Ruins of Kementari");
    long_desc=
"     You stand on the outer edges of the crag.\n"+
"Whatever Kementari was once ago, it is nothing now.\n"+
"Long white stone boulders cover most of the ground.\n"+
"Some stand high in the air, others sit atop\n"+
"eachother.\n";

    dest_dir=({
CASTLEROOM+"/kementari2.c","east",
    });

    items=({
"crag",    "     The crags have many pathways for exploration",
"boulders","     Huge boulders tower above and around you",
"ground",  "     The ground is of loose dry clay",
    });
  }
}
