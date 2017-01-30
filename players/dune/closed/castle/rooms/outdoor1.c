inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("Path further towards a volcano");
    long_desc=
"     The hills around you grow steeper and more rocky to the north.\n"+
"The volcano dominates the western landscape. You are almost under\n"+
"the dark shadow of the dark clouds above.\n";

    dest_dir=({
CASTLEROOM+"/mountainentrance.c","south"  ,
CASTLEROOM+"/outdoor2.c","north"  ,
    });

    items=({
"clouds", "     The clouds seem to be ordinary rain clouds",
"hills",  "     The hills are somewhat craggy, vegetated with small shrubs",
"volcano","     The volcano seems to draw you near",
    });
  }
}
