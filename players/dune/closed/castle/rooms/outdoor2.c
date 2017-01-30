inherit "room/room";
#include "definitions.h"


int i;

reset(arg)
{
  if (!present("orc"))
  {
    for(i = 1; i<=3; i++) 
      move_object(clone_object(CASTLEMONSTER+"/orc.c"),this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc=("Base of the Volcano");
    long_desc=
"     You arrive at the foot of the volcano. The volcano seems to\n"+
"be inactive for quite some time now. There is an abundance of\n"+
"vegetation on the volcano and everywhere near it.\n";

    dest_dir=({
CASTLEROOM+"/outdoor1.c","south"  ,
    });

    items=({
"volcano",   "     The volcano fills your entire northern view",
"vegetation","     Tall pine trees and thick undergrowth scatter the area",
    });
  }
}
