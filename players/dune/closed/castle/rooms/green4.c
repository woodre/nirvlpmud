inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("Southeastern Green Plains");
    long_desc=
"     The land slopes gently downward to the south\n"+
"and upward to the north.  To the east, the green\n"+
"grass loses its dominance near the river's edge.\n"+
"Pine trees take over and form a line along the \n"+
"riverside.  As the river curves eastward, the line\n"+
"of trees ends in a distant sand beach.\n";

    dest_dir=({
CASTLEROOM+"/green9.c","west"  ,
CASTLEROOM+"/green5.c","south"  ,
CASTLEROOM+"/green3.c","north"  ,
    });

    items=({
"river",    "     This is a wide river, uncrossable from here",
"trees",    "     The line of trees is thick with mainly pine",
"line",     "     The line of trees is thick with mainly pine",
"beach",    "     The beach is long and thin",
"land",     "     The land slopes down to the beach",
"grass",    "     The grass grows thick-leaved here",
"riverside","     The riverside is filled with pine trees",
    });
  }
}
