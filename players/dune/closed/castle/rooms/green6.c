inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("Northern Green Plains");
    long_desc=
"     Broad green grass plains stretch across the\n"+
"greater expanse of your view. The land slopes gently,\n"+
"making for easy travel. A patch of old tall pine trees\n"+
"grow around what looks like a hidden garden. Except for\n"+
"Except for the trees, the land is mainly wide and open.\n"+
"Very far off in the southwest, you can see tall mountains.\n"+
"Farmland lies to the north.\n";

    dest_dir=({
CASTLEROOM+"/green1.c", "east"  ,
CASTLEROOM+"/green7.c", "south"  ,
CASTLEROOM+"/garden.c", "garden"  ,
    });

    items=({
"plains",   "     The plains stretch for miles",
"land",     "     The land is smooth and green",
"trees",    "     The trees are short and few in numbers",
"mountains","     The mountains are too far to clearly see",
"farmland", "     The farmland continues for miles northward",
"garden",   "     The trees and garden walls hide what might be inside",
    });
  }
}
