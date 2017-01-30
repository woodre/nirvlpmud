inherit "room/room";
#include "definitions.h"


init()
{
  add_action("goplace","north");
  add_action("goplace","n");
  ::init();
}


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("Northwestern Green Plains");
    long_desc=
"     Here the plains continue to stretch along\n"+
"the foothills to the south and west.  Past the\n"+
"foothills, tall mountains meet the horizon.\n"+
"To the north, a great forest envelopes the land.\n";

    dest_dir=({
CASTLEROOM+"/green19.c","west"  ,
CASTLEROOM+"/green18.c","south"  ,
CASTLEROOM+"/green15.c","east"  ,
    });

    items=({
   "foothills","     The foothills slope steeply",
   "plains","     The plains extend mainly east and west here",
   "mountains","     The mountains stand tall in the horizon",
   "forest","     The forest is huge and very dense",
    });
  }
}


goplace()
{
   say("\n" + TPN + " enters the northern forest.\n\n");
   write("You enter the forest.\n");
   move_object(TP, CASTLEROOM+"/forestpath4.c");
   return 1;
}
